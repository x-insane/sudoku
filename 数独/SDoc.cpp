#include "stdafx.h"

SDoc::SDoc(Sudoku * p)
{
	open(p);
}

SDoc::SDoc(String^ filename)
{
	open(filename);
}

bool SDoc::open(Sudoku * p)
{
	if (!p)
		return false;
	p_sd = p;
	filename = nullptr;
	return true;
}

bool SDoc::open(String ^ filename)
{
	if (!filename)
		return false;
	try
	{
		FileInfo^ fi = gcnew FileInfo(filename);
		if (!fi->Exists)
			return false;
		FileStream^ fs = fi->Open(FileMode::Open, FileAccess::Read);
		BinaryReader^ br = gcnew BinaryReader(fs);
		if (p_sd && this->filename)
		{
			delete p_sd;
			p_sd = 0;
		}
		Byte type = br->ReadByte();
		switch (type)
		{
		case SD_Standard:
			p_sd = new Sudoku();
			break;
		case SD_X:
			p_sd = new XSudoku();
			break;
		case SD_Percent:
			p_sd = new PSudoku();
			break;
		}
		if (!p_sd)
		{
			br->Close();
			fs->Close();
			return false;
		}
		bool result = p_sd->Serialize(br);
		br->Close();
		fs->Close();
		this->filename = filename;
		return result;
	}
	catch (IOException^ e)
	{
		MessageBox::Show(e->ToString());
	}
	return false;
}

bool SDoc::save()
{
	return save(filename);
}

bool SDoc::save(String ^ filename)
{
	if (!filename || !p_sd)
		return false;
	try
	{
		FileInfo^ fi = gcnew FileInfo(filename);
		FileStream^ fs = fi->Open(FileMode::OpenOrCreate, FileAccess::Write);
		BinaryWriter^ bw = gcnew BinaryWriter(fs);
		bool result = p_sd->Serialize(bw);
		bw->Close();
		fs->Close();
		return result;
	}
	catch (IOException^ e)
	{
		MessageBox::Show(e->ToString());
	}
	return false;
}

void SDoc::changeModel(int model)
{
	switch (model)
	{
	case SD_Standard:
		p_sd = new Sudoku(*p_sd);
		break;
	case SD_X:
		p_sd = new XSudoku(*p_sd);
		break;
	case SD_Percent:
		p_sd = new PSudoku(*p_sd);
		break;
	}
}
