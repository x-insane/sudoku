#include "stdafx.h"
#include "memory.h"


Sudoku::Sudoku()
{
	memset(data, 0, sizeof(data));
	_status = Status::Empty;
}

Sudoku::Sudoku(const Sudoku & sd)
{
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j)
			data[i][j] = sd.data[i][j];
}

bool Sudoku::check()
{
	init();
	int gn[10] = { 0 };
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			SD& sd = data[i][j];
			if (sd.num < 0 || sd.num > 9)
				return false;
			if (sd.group < 1 || sd.group > 9)
				return false;
			gn[sd.group] ++;
			if (gn[sd.group] > 9)
				return false;
			if (!sd.num)
				continue;
			for (int k = 1; k <= 9; ++k)
			{
				if (i != k && data[k][j].num == sd.num)
					return false;
				if (j != k && data[i][k].num == sd.num)
					return false;
				short pos = map[sd.group][k];
				if (pos != i * 10 + j && data[pos / 10][pos % 10].num == sd.num)
					return false;
			}
		}
	}
	return true;
}

void Sudoku::init()
{
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(group, 0, sizeof(group));
	memset(map, 0, sizeof(map));
	int map_n[10] = {0};
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			row[i][data[i][j].num] = true;
			col[j][data[i][j].num] = true;
			group[data[i][j].group][data[i][j].num] = true;
			map[data[i][j].group][++map_n[data[i][j].group]] = i*10+j;
		}
	}
}

Status Sudoku::set(Res res, Res group)
{
	memset(data, 0, sizeof(data));
	for(int i=1;i<10;++i)
	{
		for(int j=1;j<10;++j)
		{
			if(group)
				data[i][j].group = group[i][j];
			else
				data[i][j].group = (i-1)/3*3+(j-1)/3+1; // 标准规则数独
			data[i][j].num = res[i][j];
		}
	}
	if (check())
	{
		_status = Status::Loaded;
		return scan();
	}
	_status = Status::Bad;
	return _status;
}

Status Sudoku::set(Board res)
{
	memset(group, 0, sizeof(group));
	for(int i=1;i<10;++i)
		for(int j=1;j<10;++j)
			data[i][j] = res[i][j];
	if (check())
	{
		_status = Status::Loaded;
		return scan();
	}
	_status = Status::Bad;
	return _status;
}

Status Sudoku::scan()
{
	if(_status == Status::Win)
		return _status;
	Status _s = Status::Ok;
	memset(n_map, 0, sizeof(n_map));
	bool is_full = true;
	for(int i=1;i<10;++i)
	{
		for(int j=1;j<10;++j)
		{
			if(data[i][j].num)
				continue;
			is_full = false;
			data[i][j].range = 0;
			memset(data[i][j].is, 0, sizeof(data[i][j].is));
			for(int k=1;k<10;++k)
			{
				if(can(i, j, k)) // 能填
				{
					data[i][j].range ++;
					data[i][j].is[k] = true;
				}
				/*if(data[i][k].num == data[i][j].num && data[i][k].who == 1)
				{
					data[i][k].who = 3; // 标红该行重复数字
					_s = _status = Status::Wrong;
				}
				if(data[k][j].num == data[i][j].num && data[k][j].who == 1)
				{
					data[k][j].who = 3; // 标红该列重复数字
					_s = _status = Status::Wrong;
				}
				int n = map[data[i][j].group][k];
				short xx = n / 10,
					yy = n % 10;
				if(data[xx][yy].num == data[i][j].num && data[xx][yy].who == 1)
				{
					data[xx][yy].who = 3; // 标红该组重复数字
					_s = _status = Status::Wrong;
				}*/
			}
			if(data[i][j].range)
			{
				n_map[data[i][j].range].x = i;
				n_map[data[i][j].range].y = j;
				for(int k=1;k<10;++k)
					n_map[data[i][j].range].is[k] = data[i][j].is[k];
			}
			else // 存在某格无法填数
				_s = Status::Wrong;
		}
	}
	if (_status == Status::Ok)
	{
		if (is_full)
			_status = _s = Callback() ? Status::Win : Status::Wrong;
	}
	return _s;
}

Status Sudoku::play(int i, int j, int k, bool is_solve)
{
	if (i < 1 || i>9 || j < 1 || j>9 || data[i][j].num)
	{
		_status = Status::Error;
		return Status::Error;
	}
	data[i][j].num = k;
	if(is_solve)
		data[i][j].who = 2;
	else
		data[i][j].who = 1;
	_status = Status::Ok;
	if(!is_solve && !data[i][j].is[k])
	{
		_status = Status::Wrong;
		for(int o=1;o<10;++o)
		{
			if(data[i][o].num == k && data[i][o].who == 1)
				data[i][o].who = 3; // 标红该行重复数字
			if(data[o][j].num == k && data[o][j].who == 1)
				data[o][j].who = 3; // 标红该列重复数字
			int n = map[data[i][j].group][o];
			short xx = n / 10,
				yy = n % 10;
			if(data[xx][yy].num == data[i][j].num && data[xx][yy].who == 1)
				data[xx][yy].who = 3; // 标红该组重复数字
		}
	}
	row[i][k] = true;
	col[j][k] = true;
	group[data[i][j].group][k] = true;
	return scan();
}

Status Sudoku::reset()
{
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(group, 0, sizeof(group));
	for (int i=1;i<10;++i)
	{
		for (int j=1;j<10;++j)
		{
			if(data[i][j].who)
				data[i][j].num = 0;
			data[i][j].who = 0;
			if(data[i][j].num)
			{
				row[i][data[i][j].num] = true;
				col[j][data[i][j].num] = true;
				group[data[i][j].group][data[i][j].num] = true;
			}
		}
	}
	_status = Status::Loaded;
	return scan();
}

Status Sudoku::reset(int i, int j, bool is_solve)
{
	if(i<1 || i>9 || j<1 || j>9 || !data[i][j].num)
		return Status::Error;
	if(!data[i][j].who)
		return Status::Error;
	data[i][j].num = 0;
	data[i][j].who = 0;

	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(group, 0, sizeof(group));
	for (int i=1;i<10;++i)
	{
		for (int j=1;j<10;++j)
		{
			if(data[i][j].who == 3)
				data[i][j].who = 1;
			if(data[i][j].num)
			{
				row[i][data[i][j].num] = true;
				col[j][data[i][j].num] = true;
				group[data[i][j].group][data[i][j].num] = true;
			}
		}
	}

	if(is_solve)
		return scan();

	_status = Status::Ok;
	for (int i=1;i<10;++i)
	{
		for (int j=1;j<10;++j)
		{
			for(int k=1;k<10;++k)
			{
				if(k != j && data[i][k].num == data[i][j].num && data[i][k].who == 1)
				{
					data[i][k].who = 3; // 标红该行重复数字
					_status = Status::Wrong;
				}
				if(k != i && data[k][j].num == data[i][j].num && data[k][j].who == 1)
				{
					data[k][j].who = 3; // 标红该列重复数字
					_status = Status::Wrong;
				}
				int n = map[data[i][j].group][k];
				short xx = n / 10,
					yy = n % 10;
				if((xx!=i || yy!=j) && data[xx][yy].num == data[i][j].num && data[xx][yy].who == 1)
				{
					data[xx][yy].who = 3; // 标红该组重复数字
					_status = Status::Wrong;
				}
			}
		}
	}
	return scan();
}


Status Sudoku::solve(bool is_reset)
{
	if(is_reset)
		reset();
	if(_status != Status::Loaded && _status != Status::Ok)
		return Status::Error;
	int i = 0;
	while(i<10 && !n_map[i].x)
		++i;
	if(i == 10)
		return Status::Wrong;
	NMap tmp[10];
	for(int a=1;a<10;++a)
		tmp[a] = n_map[a];
	for(int k=1;k<10;++k)
	{
		if(!tmp[i].is[k])
			continue;
		if(play(tmp[i].x, tmp[i].y, k, true) == Status::Win)
			return Status::Ok;
		if(solve(false) == Status::Ok)
			return Status::Ok;
		reset(tmp[i].x, tmp[i].y, true);
	}
	return Status::Wrong;
}

void Sudoku::Draw(Graphics^ dc, DSS dss)
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
			System::Drawing::Brush^ brush = Brushes::Black;
			if (dss.type == DSS::DS_Main)
			{
				if (board[j + 1][i + 1].who == 1)
					brush = Brushes::Blue;
				else if (board[j + 1][i + 1].who == 2)
					brush = Brushes::Green;
				else if (board[j + 1][i + 1].who == 3)
					brush = Brushes::Red;
			}
			if (board[j + 1][i + 1].num && (dss.type == DSS::DS_Main || !board[j + 1][i + 1].who))
				dc->DrawString(board[j + 1][i + 1].num.ToString(), font, brush, rect, sf);
			if(board[j + 1][i + 1].group && dss.type == DSS::DS_Modify && dss.is_draw_group)
				dc->DrawString(board[j + 1][i + 1].group.ToString(), sfont, Brushes::Blue, rect);
		}
	}
}

bool Sudoku::Serialize(BinaryWriter ^ bw)
{
	bw->Write(Byte(SD_Standard));
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j)
			bw->Write(Byte(data[i][j].who ? 0 : data[i][j].num));
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j < 10; ++j)
			bw->Write(Byte(data[i][j].group));
	return true;
}

bool Sudoku::Serialize(BinaryReader ^ br)
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

void Sudoku::setBoard(int i, int j, int k)
{
	if (i<1 || i>9 || j<1 || j>9)
		return;
	data[i][j].num = k;
	data[i][j].who = 0;
}

void Sudoku::setGroup(int i, int j, int g)
{
	if (i<1 || i>9 || j<1 || j>9)
		return;
	data[i][j].group = g;
}
