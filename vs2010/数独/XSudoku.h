#pragma once

class XSudoku :
	public Sudoku
{
protected:
	bool g1[10], g2[10];
public:
	XSudoku();
	XSudoku(const Sudoku& sd);
	~XSudoku();
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
		return SD_X;
	}
};

