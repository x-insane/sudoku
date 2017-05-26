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
public ref class Admin : public System::Windows::Forms::Form
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
	void InitializeComponent(void)
	{
		this->listView1 = (gcnew System::Windows::Forms::ListView());
		this->SuspendLayout();
		// 
		// listView1
		// 
		this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			| System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->listView1->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(134)));
		this->listView1->Location = System::Drawing::Point(15, 15);
		this->listView1->Margin = System::Windows::Forms::Padding(30);
		this->listView1->Name = L"listView1";
		this->listView1->OwnerDraw = true;
		this->listView1->Size = System::Drawing::Size(1092, 685);
		this->listView1->TabIndex = 0;
		this->listView1->TileSize = System::Drawing::Size(202, 227);
		this->listView1->UseCompatibleStateImageBehavior = false;
		this->listView1->View = System::Windows::Forms::View::Tile;
		this->listView1->DrawItem += gcnew System::Windows::Forms::DrawListViewItemEventHandler(this, &Admin::listView1_DrawItem);
		this->listView1->DoubleClick += gcnew System::EventHandler(this, &Admin::listView1_DoubleClick);
		// 
		// Admin
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(1121, 717);
		this->Controls->Add(this->listView1);
		this->Name = L"Admin";
		this->Padding = System::Windows::Forms::Padding(0, 15, 0, 0);
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
		this->Text = L"数独管理器";
		this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Admin::Admin_FormClosing);
		this->ResumeLayout(false);

	}
#pragma endregion
	private: System::Void Admin_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	public: System::Void reload();
	private: System::Void listView1_DrawItem(System::Object^  sender, System::Windows::Forms::DrawListViewItemEventArgs^  e);
	private: System::Void listView1_DoubleClick(System::Object^  sender, System::EventArgs^  e);
};
