#include "StdAfx.h"
#include "Sudoku.h"
#include "memory.h"

using namespace Algorithm;

void Sudoku::clear()
{
}

Status Sudoku::set(Res res, Res group)
{
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(data, 0, sizeof(data));
	memset(this->group, 0, sizeof(this->group));
	for(int i=1;i<10;++i)
	{
		for(int j=1;j<10;++j)
		{
			if(group)
			{
				if(group[i][j] >= 0 && group[i][j] < 10)
					data[i][j].group = group[i][j];
				else
				{
					_status = Status::Bad;
					return _status;
				}
			}
			else
				data[i][j].group = (i-1)/3*3+(j-1)/3+1; // 标准规则数独
			if(res[i][j] >= 0 && res[i][j] < 10)
			{
				data[i][j].num = res[i][j];
				row[i][res[i][j]] = true;
				col[j][res[i][j]] = true;
				this->group[data[i][j].group][res[i][j]] = true;
			}
			else
			{
				_status = Status::Bad;
				return _status;
			}
		}
	}
	_status = Status::Loaded;
	return scan();
}

Status Sudoku::set(Board res)
{
	memset(group, 0, sizeof(group));
	for(int i=1;i<10;++i)
	{
		for(int j=1;j<10;++j)
		{
			data[i][j] = res[i][j];
			row[i][data[i][j].num] = true;
			col[j][data[i][j].num] = true;
			group[data[i][j].group][data[i][j].num] = true;
		}
	}
	_status = Status::Loaded;
	return scan();
}

Status Sudoku::scan()
{
	Status _s = Status::Ok;
	for(int i=1;i<10;++i)
	{
		for(int j=1;j<10;++j)
		{
			if(data[i][j].num)
				continue;
			data[i][j].range = 0;
			memset(data[i][j].is, 0, sizeof(data[i][j].is));
			for(int k=1;k<10;++k)
			{
				if(can(i, j, k))
				{
					data[i][j].range ++;
					data[i][j].is[k] = true;
				}
			}
			if(!data[i][j].range) // 存在某格无法填数
				_s = Status::Wrong;
			n_map[data[i][j].range].x = i;
			n_map[data[i][j].range].y = j;
			for(int k=1;k<10;++k)
				n_map[data[i][j].range].is[k] = data[i][j].is[k];
		}
	}
	return _s;
}

Status Sudoku::play(int i, int j, int k)
{
	if(i<1 || i>9 || j<1 || j>9 || data[i][j].num)
		return Status::Error;
	data[i][j].num = k;
	data[i][j].who = 1;
	if(!data[i][j].is[k])
	{
		_status = Status::Error;
		for(int o=1;o<10;++o)
		{
			if(data[i][o].num == k && data[i][o].who == 1)
				data[i][o].who = 3;
			if(data[o][j].num == k && data[i][o].who == 1)
				data[o][j].who = 3;
			// 这里还需判断group中的数字
		}
	}
	row[i][k] = true;
	col[j][k] = true;
	group[data[i][j].group][k] = true;
	return scan();
}