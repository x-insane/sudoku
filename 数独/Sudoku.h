#pragma once

#include "SDoc.h"
using namespace Document;

namespace Algorithm
{
	enum class Status // enum class 方式 
	{
		Empty, // 表示还未加载数独资源
		Bad,   // 表示所加载的数据有错误，无法提供功能
		Loaded,// 刚加载并初始化数独数据，还没有进行任何填数操作
		Ok,    // 表示一切正常
		Wrong, // 表示当前状态有错误填数
		Error, // 传入参数错误
		Win    // 表示全部填满且正确
	};
	
	class Sudoku
	{
		struct NMap
		{
			short x;
			short y;
			bool is[10];
		}n_map[10]; // 有n种填法的小格
		short map[10][10]; // 每个group的所有成员
		bool row[10][10]; // row[i][k] -- 第i行是否被k占领
		bool col[10][10]; // col[j][k] -- 第j列是否被k占领
		bool group[10][10]; // group[g][k] -- 第g组被k占领
	protected:
		SD data[10][10];
		Status _status; // enum class 方式
	public:
		Sudoku()
		{
			_status = Status::Empty;
		}
		Board get() const // 获取数据
		{
			return data;
		}
		Status status() const // 获取状态
		{
			return _status;
		}
		const char* status_string() const
		{
			switch(_status)
			{
			case Status::Bad:
				return "错误";
			case Status::Empty:
				return "未加载";
			case Status::Error:
				return "错误";
			case Status::Loaded:
				return "就绪";
			case Status::Ok:
				return "正常";
			case Status::Win:
				return "完成";
			case Status::Wrong:
				return "有错填";
			}
			return "";
		}
		Status set(Res res, Res group=0); // group为0时表示默认标准数独
		Status set(Board res);
		Status play(int x, int y, int k, bool is_solve=false);
		Status reset();
		Status reset(int x, int y, bool is_solve=false);
		Status solve(bool is_reset=false);
	protected:
		bool can(int x, int y, int k) // 判断x行y列能否填k
		{
			if(data[x][y].num)
				return false;
			if(row[x][k] || col[y][k] || group[data[x][y].group][k])
				return false;
			return true;
		}
		Status scan(); // 扫描并计算每个格子可填数和有n种填法的小格
	};
}