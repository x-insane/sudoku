// ����.cpp: ����Ŀ�ļ���

#include "stdafx.h"

using namespace System::IO;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Form1^ form = gcnew Form1();
	if(args->Length > 0)
	{
		if(File::Exists(args[0]))
		{
			FileStream^ fs = File::Open(args[0], FileMode::Open, FileAccess::Read);
			BinaryReader^ reader = gcnew BinaryReader(fs);
			int d[10][10], g[10][10];
			for(int i=1;i<10;++i)
				for(int j=1;j<10;++j)
					d[i][j] = reader->ReadInt32();
			for(int i=1;i<10;++i)
				for(int j=1;j<10;++j)
					g[i][j] = reader->ReadInt32();
			form->p_sd->set(d, g);
			reader->Close();
			fs->Close();
		}
	}
	Application::Run(form);
	return 0;
}
