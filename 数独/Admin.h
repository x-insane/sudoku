#pragma once

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Admin 摘要
/// </summary>
public ref class Admin : public System::Windows::Forms::Form, ModifySuccess
{
	Form1^ f_parent;
	array<SDoc^>^ sdList = nullptr;
public:

public:
	Admin(Form1^ parent)
	{
		InitializeComponent();
		//
		//TODO: 在此处添加构造函数代码
		//
		f_parent = parent;
	}
	virtual SDoc^ sdoc();
	virtual void modify_ok();
	virtual void modify_cancel();

protected:
	/// <summary>
	/// 清理所有正在使用的资源。
	/// </summary>
	~Admin()
	{
		if (components)
		{
			delete components;
		}
	}
private: System::Windows::Forms::ListView^  listView1;

protected: 

private:
	/// <summary>
	/// 必需的设计器变量。
	/// </summary>
	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// 设计器支持所需的方法 - 不要
	/// 使用代码编辑器修改此方法的内容。
	/// </summary>
	void InitializeComponent(void);
#pragma endregion
	private: System::Void Admin_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	public: System::Void reload();
	private: System::Void listView1_DrawItem(System::Object^  sender, System::Windows::Forms::DrawListViewItemEventArgs^  e);
	private: System::Void listView1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
	private: System::Void listView1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void listView1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void handle_reload(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void handle_delete(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void handle_open(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void handle_modify(System::Object ^ sender, System::EventArgs ^ e);
};
