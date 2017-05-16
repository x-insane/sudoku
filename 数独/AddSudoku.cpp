#include "stdafx.h"

using namespace System::IO;

System::Void AddSudoku::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ data = data_text->Text;
	String^ group = group_text->Text;
	int d[10][10] = {0};
	int g[10][10] = {0};
	int k = 0, m = data->Length;
	for(int i=1;i<10;++i)
	{
		for(int j=1;j<10;++j)
		{
			while(k < m && (data[k] < '0' || data[k] > '9'))
				k++;
			if(k >= m)
				return;
			d[i][j] = int(data[k++] - '0');
		}
	}
	k = 0;
	m = group->Length;
	for(int i=1;i<10;++i)
	{
		for(int j=1;j<10;++j)
		{
			while(k < m && (group[k] < '0' || group[k] > '9'))
				k++;
			if(k >= m)
				return;
			g[i][j] = int(group[k++] - '0');
		}
	}
	f_parent->p_sd->set(d, g);
}

System::Void AddSudoku::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ data = data_text->Text;
	String^ group = group_text->Text;
	int d[10][10] = {0};
	int g[10][10] = {0};
	int k = 0, m = data->Length;
	for(int i=1;i<10;++i)
	{
		for(int j=1;j<10;++j)
		{
			while(k < m && (data[k] < '0' || data[k] > '9'))
				k++;
			if(k >= m)
				return;
			d[i][j] = int(data[k++] - '0');
		}
	}
	k = 0;
	m = group->Length;
	for(int i=1;i<10;++i)
	{
		for(int j=1;j<10;++j)
		{
			while(k < m && (group[k] < '0' || group[k] > '9'))
				k++;
			if(k >= m)
				return;
			g[i][j] = int(group[k++] - '0');
		}
	}
	SaveFileDialog^ sf = gcnew SaveFileDialog();
	sf->Filter = L"数独文件 (*.sd)|*.sd";
	if(sf->ShowDialog() == Windows::Forms::DialogResult::Cancel)
		return;
	Stream^ fs = sf->OpenFile();
	if(!fs)
	{
		MessageBox::Show(L"无法打开目标文件，请检查文件目录是否正确，是否有读写该位置文件的权限。", L"错误");
		return;
	}
	BinaryWriter^ writer = gcnew BinaryWriter(fs);
	for(int i=1;i<10;++i)
		for(int j=1;j<10;++j)
			writer->Write(d[i][j]);
	for(int i=1;i<10;++i)
		for(int j=1;j<10;++j)
			writer->Write(g[i][j]);
	writer->Close();
	fs->Close();
}