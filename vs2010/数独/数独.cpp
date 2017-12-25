// 数独.cpp: 主项目文件。

#include "stdafx.h"

using namespace System::IO;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// 在创建任何控件之前启用 Windows XP 可视化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// 创建主窗口并运行它
	Form1^ form;
	if (args->Length > 0 && File::Exists(args[0]))
		form = gcnew Form1(args[0]);
	else
		form = gcnew Form1();
	Application::Run(form);
	return 0;
}
