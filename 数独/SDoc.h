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
	bool isnew()
	{
		return filename ? false : true;
	}
	bool reload()
	{
		if (!filename)
			return false;
		return open(filename);
	}
	void changeModel(int model);
};
