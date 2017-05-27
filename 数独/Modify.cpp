#include "stdafx.h"
#include "Modify.h"

/*
Modify::Modify(ModifySuccess^ m, Sudoku * p) : src(p), msif(m)
{
	InitializeComponent();
	doc = gcnew SDoc(new Sudoku(*p));
	doc->sd()->reset();
}*/

Modify::Modify(ModifySuccess^ m, bool is) : msif(m), isnew(is)
{
	InitializeComponent();
	if (isnew)
	{
		doc = gcnew SDoc(new Sudoku());
		p_sd = doc->sd();
	}
	else if (m->sdoc()->isnew())
	{
		doc = gcnew SDoc(new Sudoku(*m->sdoc()->sd()));
		p_sd = doc->sd();
		isnew = true;
	}
	else
	{
		doc = m->sdoc();
		p_sd = new Sudoku(*doc->sd());
	}
}

System::Void Modify::label2_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{
	Graphics^ dc = e->Graphics;
	float a = float(label2->Width - 2); // 绘制数独区域的边长
	float x = 1;
	float y = 1; // 数独区域左上角坐标

	DSS dss;
	dss.a = a;
	dss.left = x;
	dss.top = y;
	dss.sfontw = 8;
	dss.penw = 2;
	dss.type = DSS::DS_Modify;
	dss.is_draw_group = checkBox1->Checked;
	p_sd->Draw(dc, dss);
}

System::Void Modify::Modify_FormClosed(System::Object ^ sender, System::Windows::Forms::FormClosedEventArgs ^ e)
{
	if (e->CloseReason == CloseReason::UserClosing)
		msif->modify_cancel();
	delete p_sd;
}

System::Void Modify::label2_MouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	int v = getRadioValue();
	int x = e->Y / (label2->Height / 9) + 1;
	int y = e->X / (label2->Width / 9) + 1;
	handle_modify(x, y, v);
}

System::Void Modify::label2_MouseMove(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	int v = getRadioValue();
	int x = e->Y / (label2->Height / 9) + 1;
	int y = e->X / (label2->Width / 9) + 1;
	if (e->Button.ToString() == "Left")
		handle_modify(x, y, v);
}

void Modify::handle_modify(int x, int y, int v)
{
	if (v >= 1 && v <= 9)
		p_sd->setBoard(x, y, v);
	else if (v >= 10 && v <= 18)
		p_sd->setGroup(x, y, v - 9);
	else if(v == 19)
		p_sd->setBoard(x, y, 0);
	else if (v == 20)
		p_sd->setGroup(x, y, 0);
	label2->Invalidate();
}

int Modify::getRadioValue()
{
	if (radioButton1->Checked)
		return 1;
	if (radioButton2->Checked)
		return 2;
	if (radioButton3->Checked)
		return 3;
	if (radioButton4->Checked)
		return 4;
	if (radioButton5->Checked)
		return 5;
	if (radioButton6->Checked)
		return 6;
	if (radioButton7->Checked)
		return 7;
	if (radioButton8->Checked)
		return 8;
	if (radioButton9->Checked)
		return 9;
	if (radioButton10->Checked)
		return 10;
	if (radioButton11->Checked)
		return 11;
	if (radioButton12->Checked)
		return 12;
	if (radioButton13->Checked)
		return 13;
	if (radioButton14->Checked)
		return 14;
	if (radioButton15->Checked)
		return 15;
	if (radioButton16->Checked)
		return 16;
	if (radioButton17->Checked)
		return 17;
	if (radioButton18->Checked)
		return 18;
	if (radioButton19->Checked)
		return 19;
	if (radioButton20->Checked)
		return 20;
	return 0;
}

System::Void Modify::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			p_sd->setBoard(i, j, 0);
			p_sd->setGroup(i, j, 0);
		}
	}
	label2->Invalidate();
}

System::Void Modify::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j)
			p_sd->setBoard(i, j, 0);
	label2->Invalidate();
}

System::Void Modify::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j)
			p_sd->setGroup(i, j, 0);
	label2->Invalidate();
}

System::Void Modify::button4_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j)
			p_sd->setGroup(i, j, (i - 1) / 3 * 3 + (j - 1) / 3 + 1);
	label2->Invalidate();
}

System::Void Modify::button5_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Close();
}

System::Void Modify::button6_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (!p_sd->check())
	{
		MessageBox::Show("不符合要求，暂不能提交！");
		return;
	}
	if (isnew)
	{
		SaveFileDialog^ sf = gcnew SaveFileDialog();
		sf->Filter = L"数独文件 (*.sd)|*.sd";
		if (sf->ShowDialog() == Windows::Forms::DialogResult::Cancel)
			return;
		if (doc->save(sf->FileName))
			msif->sdoc()->open(sf->FileName);
		msif->modify_cancel();
	}
	else
	{
		*doc->sd() = *p_sd;
		doc->save();
		msif->modify_ok();
	}
	Close();
}

System::Void Modify::button7_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (p_sd->check())
		MessageBox::Show("符合要求，可以提交！");
	else
		MessageBox::Show("不符合要求，暂不能提交！");
}

System::Void Modify::checkBox1_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	label2->Invalidate();
}
