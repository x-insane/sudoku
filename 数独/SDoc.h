#pragma once

class SDoc
{
protected:
	Res data;
	Res map;
	char name[256];
	char author[256];
	unsigned long long time;
public:
	static bool save();
	static Sudoku* open();
};
