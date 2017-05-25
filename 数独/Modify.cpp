#include "stdafx.h"
#include "Modify.h"

Modify::Modify(System::Windows::Forms::Form ^ parentForm, Sudoku * p) : src(p), parent(parentForm)
{
	InitializeComponent();
	//
	//TODO:  在此处添加构造函数代码
	//
	p_sd = new Sudoku(*src);
	p_sd->reset();
}

System::Void Modify::label2_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{
	Graphics^ dc = e->Graphics;
	float a = float(label2->Width - 2); // 绘制数独区域的边长
	// 以上为大小自适应代码
	float x = 1;
	float y = 1; // 数独区域左上角坐标

	Pen^ pen = gcnew Pen(Color::Black, 2);

	Board board = p_sd->get();
	System::Drawing::Font^ font = gcnew System::Drawing::Font("You yuan", a / 18);
	System::Drawing::Font^ sfont = gcnew System::Drawing::Font("You yuan", 8);
	StringFormat^ sf = gcnew StringFormat;
	sf->LineAlignment = StringAlignment::Center;
	sf->Alignment = StringAlignment::Center;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			Rectangle rect = Rectangle(int(x + i*a / 9 + 2 + 0.5), int(y + j*a / 9 + 2 + 0.5), int(a / 9 - 1), int(a / 9 - 1));
			switch (board[j + 1][i + 1].group)
			{
			case 1:
				dc->FillRectangle(gcnew SolidBrush(Color::FromArgb(0xFFC1FFC1)), rect);
				break;
			case 2:
				dc->FillRectangle(Brushes::LightGoldenrodYellow, rect);
				break;
			case 3:
				dc->FillRectangle(Brushes::PowderBlue, rect);
				break;
			case 4:
				dc->FillRectangle(Brushes::Lavender, rect);
				break;
			case 5:
				dc->FillRectangle(gcnew SolidBrush(Color::FromArgb(0xFFFFE1FF)), rect);
				break;
			case 6:
				dc->FillRectangle(gcnew SolidBrush(Color::FromArgb(0xFFF6E6CC)), rect);
				break;
			case 7:
				dc->FillRectangle(gcnew SolidBrush(Color::FromArgb(0xFFF0DBCE)), rect);
				break;
			case 8:
				dc->FillRectangle(Brushes::PaleTurquoise, rect);
				break;
			case 9:
				dc->FillRectangle(gcnew SolidBrush(Color::FromArgb(0xFFEED2EE)), rect);
				break;
			}
		}
	}

	for (int i = 0; i<10; ++i)
	{
		// 黑色线画边框，灰色线画内部小格
		dc->DrawLine(i % 9 ? Pens::LightGray : pen, x + i*a / 9, y, x + i*a / 9, y + a);
		dc->DrawLine(i % 9 ? Pens::LightGray : pen, x, y + i*a / 9, x + a, y + i*a / 9);
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			Rectangle rect = Rectangle(int(x + i*a / 9 + 2 + 0.5), int(y + j*a / 9 + 2 + 0.5), int(a / 9 - 1), int(a / 9 - 1));
			if (i && board[j + 1][i + 1].group != board[j + 1][i].group)
				dc->DrawLine(pen, x + i*a / 9, y + j*a / 9, x + i*a / 9, y + (j + 1)*a / 9); // 用粗线画左边框
			if (j && board[j + 1][i + 1].group != board[j][i + 1].group)
				dc->DrawLine(pen, x + i*a / 9, y + j*a / 9, x + (i + 1)*a / 9, y + j*a / 9); // 用粗线画上边框
			System::Drawing::Brush^ brush = Brushes::Black;
			if (board[j + 1][i + 1].who == 0 && board[j + 1][i + 1].num)
				dc->DrawString(board[j + 1][i + 1].num.ToString(), font, brush, rect, sf);
			if(board[j + 1][i + 1].group && checkBox1->Checked)
				dc->DrawString(board[j + 1][i + 1].group.ToString(), sfont, Brushes::Blue, rect);
		}
	}

	delete pen;
	delete font;
	delete sf;
}

System::Void Modify::Modify_FormClosed(System::Object ^ sender, System::Windows::Forms::FormClosedEventArgs ^ e)
{
	parent->Show();
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
	*src = *p_sd;
	src->reset();
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
