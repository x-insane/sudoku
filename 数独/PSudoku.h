#pragma once

class PSudoku :
	public Sudoku
{
protected:
	bool g_percent[4][10] = { 0 };
	int g_which(int x, int y)
	{
		if (x + y == 10)
			return 2; // 中央斜线
		if (x >= 2 && x <= 4 && y >= 2 && y <= 4)
			return 1; // 左上角方形
		if (x >= 6 && x <= 8 && y >= 6 && y <= 8)
			return 3; // 右下角方形
		return 0;
	}
public:
	PSudoku();
	PSudoku(const Sudoku& sd);
	~PSudoku();
public:
	virtual void init();
	virtual bool can(int x, int y, int k);
	virtual Status play(int x, int y, int k, bool is_solve = false);
	virtual bool check();
	virtual void Draw(Graphics^ dc, DSS dss);
	virtual bool Serialize(BinaryWriter^ bw);
	virtual bool Serialize(BinaryReader^ br);
	virtual bool Callback();
	virtual Status reset();
	virtual Status reset(int x, int y, bool is_solve = false);
	virtual int kind()
	{
		return SD_Percent;
	}
};

