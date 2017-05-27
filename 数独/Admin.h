#pragma once

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Admin ժҪ
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
		//TODO: �ڴ˴���ӹ��캯������
		//
		f_parent = parent;
	}
	virtual SDoc^ sdoc();
	virtual void modify_ok();
	virtual void modify_cancel();

protected:
	/// <summary>
	/// ������������ʹ�õ���Դ��
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
	/// ����������������
	/// </summary>
	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// �����֧������ķ��� - ��Ҫ
	/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
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
