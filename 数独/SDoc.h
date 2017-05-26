#pragma once

ref class SDoc
{
	String^ filename;
	Sudoku* p_sd = 0;
public:
	SDoc(Sudoku* p);
	SDoc(String^ filename);
	Sudoku* sd()
	{
		return p_sd;
	}
	String^ getFilename()
	{
		return filename;
	}
	bool open(Sudoku* p);
	bool open(String^ filename);
	bool save();
	bool save(String^ filename);
};
