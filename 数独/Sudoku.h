#pragma once

namespace Algorithm
{
	struct SD // 设计数独小格
	{
		short num;
		short group;
		// 1-9，表示所属分组
		short who;
		// 0 -- 数独原有数字，默认
		// 1 -- 玩家添入数字
		// 2 -- 解数独时填入数字
		// 3 -- 玩家错填数字
		short range; // 表示能填数的个数
		bool is[10]; // 表示该格能否填1-9的数
	};
	
	typedef const SD(*Board)[10];
	typedef const int(*Res)[10];
	
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
		struct 
		{
			short x;
			short y;
			bool is[10];
		}n_map[10]; // 有n种填法的小格
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
		Status set(Res res, Res group=0); // group为0时表示默认标准数独
		Status set(Board res);
		Status play(int x, int y, int k);
		Status reset();
		Status reset(int x, int y);
		int solve(bool isreset=false);
	protected:
		void clear(); // 清除当前所有数据，准备接收新数据
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