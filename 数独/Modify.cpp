#include "stdafx.h"
#include "Modify.h"

Modify::Modify(Form1 ^ parentForm, Sudoku * p) : src(p), parent(parentForm)
{
	InitializeComponent();
	doc = gcnew SDoc(new Sudoku(*p));
	doc->sd()->reset();
}

Modify::Modify(Form1 ^ parentForm) : parent(parentForm)
{
	InitializeComponent();
	doc = gcnew SDoc(new Sudoku());
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
	doc->sd()->Draw(dc, dss);
}

System::Void Modify::Modify_FormClosed(System::Object ^ sender, System::Windows::Forms::FormClosedEventArgs ^ e)
{
	parent->Show();
	delete doc->sd();
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
		doc->sd()->setBoard(x, y, v);
	else if (v >= 10 && v <= 18)
		doc->sd()->setGroup(x, y, v - 9);
	else if(v == 19)
		doc->sd()->setBoard(x, y, 0);
	else if (v == 20)
		doc->sd()->setGroup(x, y, 0);
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
			doc->sd()->setBoard(i, j, 0);
			doc->sd()->setGroup(i, j, 0);
		}
	}
	label2->Invalidate();
}

System::Void Modify::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j)
			doc->sd()->setBoard(i, j, 0);
	label2->Invalidate();
}

System::Void Modify::button3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j)
			doc->sd()->setGroup(i, j, 0);
	label2->Invalidate();
}

System::Void Modify::button4_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j)
			doc->sd()->setGroup(i, j, (i - 1) / 3 * 3 + (j - 1) / 3 + 1);
	label2->Invalidate();
}

System::Void Modify::button5_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Close();
}

System::Void Modify::button6_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (!doc->sd()->check())
	{
		MessageBox::Show("不符合要求，暂不能提交！");
		return;
	}
	if (src)
	{
		*src = *doc->sd();
		src->reset();
		if (parent->doc->getFilename())
			parent->saveToolStripMenuItem->Enabled = true;
	}
	else
	{
		SaveFileDialog^ sf = gcnew SaveFileDialog();
		sf->Filter = L"数独文件 (*.sd)|*.sd";
		if (sf->ShowDialog() == Windows::Forms::DialogResult::Cancel)
			return;
		doc->save(sf->FileName);
	}
	Close();
}

System::Void Modify::button7_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (doc->sd()->check())
		MessageBox::Show("符合要求，可以提交！");
	else
		MessageBox::Show("不符合要求，暂不能提交！");
}

System::Void Modify::checkBox1_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	label2->Invalidate();
}
