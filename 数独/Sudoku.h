#pragma once
	
class Sudoku
{
protected:
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
	Sudoku();
	Sudoku(const Sudoku& sd);
	virtual bool check();
	Board get() const // 获取数据
	{
		return data;
	}
	Status status() const // 获取状态
	{
		return _status;
	}
	const char* status_string(bool is_show_tip = true) const
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
			return is_show_tip ? "有错填" : "正常";
		}
		return "";
	}
	Status set(Res res, Res group=0); // group为0时表示默认标准数独
	Status set(Board res);
	virtual Status play(int x, int y, int k, bool is_solve=false);
	virtual Status reset();
	virtual Status reset(int x, int y, bool is_solve=false);
	Status solve(bool is_reset=false);
	virtual void Draw(Graphics^ dc, DSS dss);
	virtual bool Serialize(BinaryWriter^ bw);
	virtual bool Serialize(BinaryReader^ br);
	virtual int kind()
	{
		return SD_Standard;
	}
protected:
	void setBoard(int x, int y, int k);
	void setGroup(int x, int y, int g);
	friend ref class Modify; // 允许Modify窗口对数独数据进行修改
protected:
	virtual void init();
	virtual bool can(int x, int y, int k); // 判断x行y列能否填k
	Status scan(); // 扫描并计算每个格子可填数和有n种填法的小格
	virtual bool Callback()
	{
		return true;
	}
};