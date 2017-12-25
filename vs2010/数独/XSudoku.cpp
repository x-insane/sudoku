#include "stdafx.h"
#include <memory.h>

XSudoku::XSudoku()
{
}

XSudoku::XSudoku(const Sudoku & sd) : Sudoku(sd)
{
}

XSudoku::~XSudoku()
{
}

void XSudoku::init()
{
	Sudoku::init();
	memset(g1, 0, sizeof(g1));
	memset(g2, 0, sizeof(g2));
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			if (data[i][j].num)
			{
				if (i == j)
					g1[data[i][j].num] = true;
				if (i + j == 10)
					g2[data[i][j].num] = true;
			}
		}
	}
}

bool XSudoku::can(int x, int y, int k)
{
	if (!Sudoku::can(x, y, k))
		return false;
	if (x==y && g1[k])
		return false;
	if (x + y == 10 && g2[k])
		return false;
	return true;
}

Status XSudoku::play(int i, int j, int k, bool is_solve)
{
	if (i < 1 || i>9 || j < 1 || j>9 || data[i][j].num)
	{
		_status = Status::Error;
		return Status::Error;
	}
	if (!is_solve && !data[i][j].is[k])
	{
		_status = Status::Wrong;
		if (i == j)
		{
			for (int o = 1; o <= 9; ++o)
			{
				if (o == i)
					continue;
				if (data[o][o].num == k && data[o][o].who == 1)
					data[o][o].who = 3; // 标红该组重复数字
			}
		}
		if (i + j == 10)
		{
			for (int o = 1; o <= 9; ++o)
			{
				if (o == i)
					continue;
				if (data[o][10 - o].num == k && data[o][10 - o].who == 1)
					data[o][10 - o].who = 3; // 标红该组重复数字
			}
		}
	}
	return Sudoku::play(i, j, k, is_solve);
}

bool XSudoku::check()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			if (!data[i][j].num)
				continue;
			if (i == j)
			{
				for (int o = 1; o <= 9; ++o)
				{
					if (o == i)
						continue;
					if (data[o][o].num == data[i][j].num)
						return false;
				}
			}
			if (i + j == 10)
			{
				for (int o = 1; o <= 9; ++o)
				{
					if (o == i)
						continue;
					if (data[o][10 - o].num == data[i][j].num)
						return false;
				}
			}
		}
	}
	return Sudoku::check();
}

void XSudoku::Draw(Graphics ^ dc, DSS dss)
{
	Board board = data;
	float a = dss.a;
	float x = dss.left, y = dss.top;
	Pen^ pen = gcnew Pen(Color::Black, dss.penw);

	System::Drawing::Font^ font = gcnew System::Drawing::Font("You yuan", a / 18);
	System::Drawing::Font^ sfont = gcnew System::Drawing::Font("You yuan", dss.sfontw);
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
			Rectangle r2 = rect;
			r2.X += int(dss.a / 180);
			r2.Y += int(dss.a / 180);
			r2.Width -= int(dss.a / 90);
			r2.Height -= int(dss.a / 90);
			if (i == j)
				dc->DrawRectangle(Pens::Purple, r2);
			if (i + j == 8)
				dc->DrawEllipse(Pens::Green, r2);
			System::Drawing::Brush^ brush = Brushes::Black;
			if (dss.type == DSS::DS_Main)
			{
				if (board[j + 1][i + 1].who == 1)
					brush = Brushes::Blue;
				else if (board[j + 1][i + 1].who == 2)
					brush = Brushes::Green;
				else if (board[j + 1][i + 1].who == 3)
					brush = dss.is_show_tip ? Brushes::Red : Brushes::Blue;
			}
			if (board[j + 1][i + 1].num && (dss.type == DSS::DS_Main || !board[j + 1][i + 1].who))
				dc->DrawString(board[j + 1][i + 1].num.ToString(), font, brush, rect, sf);
			if (board[j + 1][i + 1].group && dss.type == DSS::DS_Modify && dss.is_draw_group)
				dc->DrawString(board[j + 1][i + 1].group.ToString(), sfont, Brushes::Blue, rect);
		}
	}
}

bool XSudoku::Serialize(BinaryWriter ^ bw)
{
	bw->Write(Byte(SD_X));
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j)
			bw->Write(Byte(data[i][j].who ? 0 : data[i][j].num));
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j)
			bw->Write(Byte(data[i][j].group));
	return true;
}

bool XSudoku::Serialize(BinaryReader ^ br)
{
	int d[10][10];
	int g[10][10];
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j)
			d[i][j] = br->ReadByte();
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j)
			g[i][j] = br->ReadByte();
	if (set(d, g) == Status::Bad)
		return false;
	return true;
}

bool XSudoku::Callback()
{
	return true;
}

Status XSudoku::reset()
{
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(group, 0, sizeof(group));
	memset(g1, 0, sizeof(g1));
	memset(g2, 0, sizeof(g2));
	for (int i = 1; i<10; ++i)
	{
		for (int j = 1; j<10; ++j)
		{
			if (data[i][j].who)
				data[i][j].num = 0;
			data[i][j].who = 0;
			if (data[i][j].num)
			{
				row[i][data[i][j].num] = true;
				col[j][data[i][j].num] = true;
				group[data[i][j].group][data[i][j].num] = true;
				if (i == j)
					g1[data[i][j].num] = true;
				if (i + j == 10)
					g2[data[i][j].num] = true;
			}
		}
	}
	_status = Status::Loaded;
	return scan();
}

Status XSudoku::reset(int i, int j, bool is_solve)
{
	if (i<1 || i>9 || j<1 || j>9 || !data[i][j].num)
		return Status::Error;
	if (!data[i][j].who)
		return Status::Error;
	data[i][j].num = 0;
	data[i][j].who = 0;

	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(group, 0, sizeof(group));
	memset(g1, 0, sizeof(g1));
	memset(g2, 0, sizeof(g2));
	for (int i = 1; i<10; ++i)
	{
		for (int j = 1; j<10; ++j)
		{
			if (data[i][j].who == 3)
				data[i][j].who = 1;
			if (data[i][j].num)
			{
				row[i][data[i][j].num] = true;
				col[j][data[i][j].num] = true;
				group[data[i][j].group][data[i][j].num] = true;
				if (i == j)
					g1[data[i][j].num] = true;
				if (i + j == 10)
					g2[data[i][j].num] = true;
			}
		}
	}

	if (is_solve)
		return scan();

	_status = Status::Ok;
	for (int i = 1; i<10; ++i)
	{
		for (int j = 1; j<10; ++j)
		{
			for (int k = 1; k<10; ++k)
			{
				if (k != j && data[i][k].num == data[i][j].num && data[i][k].who == 1)
				{
					data[i][k].who = 3; // 标红该行重复数字
					_status = Status::Wrong;
				}
				if (k != i && data[k][j].num == data[i][j].num && data[k][j].who == 1)
				{
					data[k][j].who = 3; // 标红该列重复数字
					_status = Status::Wrong;
				}
				int n = map[data[i][j].group][k];
				short xx = n / 10,
					yy = n % 10;
				if ((xx != i || yy != j) && data[xx][yy].num == data[i][j].num && data[xx][yy].who == 1)
				{
					data[xx][yy].who = 3; // 标红该组重复数字
					_status = Status::Wrong;
				}

				if (i == j)
				{
					for (int o = 1; o <= 9; ++o)
					{
						if (o == i)
							continue;
						if (data[o][o].num == k && data[o][o].who == 1)
							data[o][o].who = 3; // 标红该组重复数字
					}
				}
				if (i + j == 10)
				{
					for (int o = 1; o <= 9; ++o)
					{
						if (o == i)
							continue;
						if (data[o][10 - o].num == k && data[o][10 - o].who == 1)
							data[o][10 - o].who = 3; // 标红该组重复数字
					}
				}
			}
		}
	}
	return scan();
}
