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
	Form1^ form;
	if (args->Length > 0 && File::Exists(args[0]))
		form = gcnew Form1(args[0]);
	else
		form = gcnew Form1();
	Application::Run(form);
	return 0;
}
