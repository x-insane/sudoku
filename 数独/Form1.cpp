#include "stdafx.h"

Form1::Form1()
{
	InitializeComponent();

	f_admin = gcnew Admin(this);
	Sudoku* p_sd = new Sudoku();
	int data[10][10] =
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,9,0,0,0,0,0,4},
		{0,0,0,0,0,0,0,0,2,0},
		{0,0,6,0,0,0,2,3,0,0},
		{0,5,3,0,0,0,0,1,0,0},
		{0,0,2,0,0,0,0,0,1,0},
		{0,0,0,7,0,0,0,0,8,9},
		{0,0,0,5,8,0,0,0,4,0},
		{0,0,1,0,0,0,0,0,0,0},
		{0,4,0,0,0,0,0,9,0,0}
	};
	int group[10][10] = 
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,2,2,2,3,4,4,4,4},
		{0,1,1,1,2,3,3,3,4,4},
		{0,1,1,2,2,3,7,3,4,4},
		{0,1,2,2,2,7,7,3,3,4},
		{0,1,1,6,7,7,7,3,9,9},
		{0,5,6,6,7,7,8,8,8,9},
		{0,5,5,6,7,6,8,8,9,9},
		{0,5,5,6,6,6,8,9,9,9},
		{0,5,5,5,5,6,8,8,8,9}
	};
	p_sd->set(data, group);
	doc = gcnew SDoc(p_sd);
	saveToolStripMenuItem->Enabled = false;
}

Form1::Form1(String^ filename)
{
	InitializeComponent();
	doc = gcnew SDoc(filename);
	saveToolStripMenuItem->Enabled = false;
}

System::Void Form1::����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Hide();
	f_admin->reload();
	f_admin->Show();
}

System::Void Form1::label1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	Graphics^ dc = e->Graphics;
	float a = 360; // ������������ı߳�
	int h = label1->Height - statusStrip1->Height,
		w = label1->Width;
	if(w > 900 && h > 900)
		a = 800;
	else if(w > 400 && h > 400)
		a = float(min(w, h) * 0.9);
	// ����Ϊ��С����Ӧ����
	float x = (w - a) / 2;
	float y = (h - a) / 2; // �����������Ͻ�����

	DSS dss;
	dss.a = a;
	dss.left = x;
	dss.top = y;
	dss.penw = 3;
	dss.type = DSS::DS_Main;

	doc->sd()->Draw(dc, dss);
}

System::Void Form1::label1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(doc->sd()->status() == Status::Win)
		return;
	float a = 360;
	int h = label1->Height - statusStrip1->Height,
		w = label1->Width;
	if(w > 900 && h > 900)
		a = 800;
	else if(w > 400 && h > 400)
		a = float(min(w, h) * 0.9);
	float x = (w - a) / 2;
	float y = (h - a) / 2;
	if(e->X < x || e->Y < y)
		return;
	int i = int((e->X - x)/(a/9)) + 1;
	int j = int((e->Y - y)/(a/9)) + 1;
	if(i<1 || i>9 || j<1 || j>9)
		return;
	SD sd = doc->sd()->get()[j][i];
	this->i = j;
	this->j = i;
	if(sd.num)
	{
		if(sd.who)
			contextMenuStrip2->Show(label1, e->X, e->Y);
	}
	else if(mi_is_showtip->Checked)
	{
		System::Windows::Forms::ContextMenuStrip^ context = gcnew System::Windows::Forms::ContextMenuStrip();
		context->Name = L"contextMenu";
		context->Size = System::Drawing::Size(97*sd.range+1, 26);
		for(int k=1;k<10;++k)
		{
			if(sd.is[k])
			{
				System::Windows::Forms::ToolStripItem^ item = gcnew System::Windows::Forms::ToolStripMenuItem();
				item->Size = System::Drawing::Size(97, 22);
				item->Name = L"context_item_" + k.ToString();
				item->Text = k.ToString();
				item->Click += gcnew System::EventHandler(this, &Form1::handle_play);
				context->Items->Add(item);
			}
		}
		context->Show(label1, e->X, e->Y);
	}
	else
		contextMenuStrip1->Show(label1, e->X, e->Y);
}

System::Void Form1::handle_play(System::Object^  sender, System::EventArgs^  e)
{
	int k = int::Parse(sender->ToString());
	doc->sd()->play(i, j, k);
	statusText->Text = %String(doc->sd()->status_string());
	label1->Invalidate(true);
	if(doc->sd()->status() == Status::Win)
		MessageBox::Show(L"��ϲ�����������������", L"��Ϸ����");
}

System::Void Form1::mi_restart_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(doc->sd()->status() == Status::Loaded)
		return;
	if(MessageBox::Show(L"��Ϸ״̬����������ȷ�����¿�ʼ��", L"���¿�ʼ", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning)
		== System::Windows::Forms::DialogResult::OK)
	{
		doc->sd()->reset();
		statusText->Text = "���¿�ʼ";
		label1->Invalidate(true);
	}
}

System::Void Form1::resetijToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	doc->sd()->reset(i, j);
	statusText->Text = %String(doc->sd()->status_string());
	label1->Invalidate(true);
}

System::Void Form1::solveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	switch(doc->sd()->solve(false))
	{
	case Status::Error:
		MessageBox::Show(L"��ǰ״̬����ʹ�ñ�����", L"��ʾ");
		break;
	case Status::Wrong:
		MessageBox::Show(L"��ǰ״̬û�п��н�", L"��ʾ");
		break;
	}
	statusText->Text = %String(doc->sd()->status_string());
	label1->Invalidate(true);
}

System::Void Form1::answerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	switch(doc->sd()->solve(true))
	{
	case Status::Error:
		MessageBox::Show(L"��ǰ״̬����ʹ�ñ�����", L"��ʾ");
		break;
	case Status::Wrong:
		MessageBox::Show(L"��ǰ״̬û�п��н�", L"��ʾ");
		break;
	}
	statusText->Text = %String(doc->sd()->status_string());
	label1->Invalidate(true);
}

System::Void Form1::addsudokuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Modify^ modify = gcnew Modify(this, true);
	Hide();
	modify->Show();
}

System::Void Form1::modifysudokuToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Modify^ modify = gcnew Modify(this, false);
	Hide();
	modify->Show();
}

System::Void Form1::saveToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	doc->save();
	saveToolStripMenuItem->Enabled = false;
}

System::Void Form1::fetchToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	SaveFileDialog^ sf = gcnew SaveFileDialog();
	sf->Filter = L"�����ļ� (*.sd)|*.sd";
	if (sf->ShowDialog() == Windows::Forms::DialogResult::Cancel)
		return;
	doc->save(sf->FileName);
}

System::Void Form1::openToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	OpenFileDialog^ of = gcnew OpenFileDialog();
	of->Filter = L"�����ļ� (*.sd)|*.sd";
	if (of->ShowDialog() == Windows::Forms::DialogResult::Cancel)
		return;
	if (doc->open(of->FileName))
	{
		saveToolStripMenuItem->Enabled = false;
		statusText->Text = "�Ѽ��������ļ���" + of->SafeFileName;
		Text = "���� - " + of->SafeFileName;
	}
	label1->Invalidate();
}

System::Void Form1::reloadToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (doc->isnew())
	{
		statusText->Text = "�޷����¼���Ĭ������";
		return;
	}
	if (!doc->reload())
		MessageBox::Show("�޷����¼����ļ��������ļ��ѱ�ɾ����û�з��ʵ�Ȩ�ޡ�");
	else
		statusText->Text = "�����¼��������ļ�";
	label1->Invalidate();
}

void Form1::modify_ok()
{
	doc->reload();
	Show();
}

void Form1::modify_cancel()
{
	Show();
}
