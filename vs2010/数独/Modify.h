#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Modify 摘要
/// </summary>
public ref class Modify : public System::Windows::Forms::Form
{
	SDoc^ doc;
	// bool isnew;
	Sudoku* p_sd;
	IModify^ msif;
private:
	int getRadioValue();
	void handle_modify(int x, int y, int k);
public:
	// Modify(IModify^ m, bool isnew);
	Modify(IModify^ m, String^ filename);

protected:
	/// <summary>
	/// 清理所有正在使用的资源。
	/// </summary>
	~Modify()
	{
		if (components)
		{
			delete components;
		}
	}

protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	private: System::Windows::Forms::RadioButton^  radioButton9;
	private: System::Windows::Forms::RadioButton^  radioButton10;
	private: System::Windows::Forms::RadioButton^  radioButton11;
	private: System::Windows::Forms::RadioButton^  radioButton12;
	private: System::Windows::Forms::RadioButton^  radioButton13;
	private: System::Windows::Forms::RadioButton^  radioButton14;
	private: System::Windows::Forms::RadioButton^  radioButton15;
	private: System::Windows::Forms::RadioButton^  radioButton16;
	private: System::Windows::Forms::RadioButton^  radioButton17;
	private: System::Windows::Forms::RadioButton^  radioButton18;
	private: System::Windows::Forms::RadioButton^  radioButton19;
	private: System::Windows::Forms::RadioButton^  radioButton20;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  check_X;
	private: System::Windows::Forms::CheckBox^  check_P;

private:
	/// <summary>
	/// 必需的设计器变量。
	/// </summary>
	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// 设计器支持所需的方法 - 不要修改
	/// 使用代码编辑器修改此方法的内容。
	/// </summary>
	void InitializeComponent(void)
	{
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton12 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton13 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton14 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton15 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton16 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton17 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton18 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton19 = (gcnew System::Windows::Forms::RadioButton());
		this->radioButton20 = (gcnew System::Windows::Forms::RadioButton());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->button3 = (gcnew System::Windows::Forms::Button());
		this->button4 = (gcnew System::Windows::Forms::Button());
		this->button5 = (gcnew System::Windows::Forms::Button());
		this->button6 = (gcnew System::Windows::Forms::Button());
		this->button7 = (gcnew System::Windows::Forms::Button());
		this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
		this->check_X = (gcnew System::Windows::Forms::CheckBox());
		this->check_P = (gcnew System::Windows::Forms::CheckBox());
		this->SuspendLayout();
		// 
		// label2
		// 
		this->label2->Cursor = System::Windows::Forms::Cursors::Cross;
		this->label2->Location = System::Drawing::Point(74, 23);
		this->label2->Margin = System::Windows::Forms::Padding(0);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(382, 382);
		this->label2->TabIndex = 15;
		this->label2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Modify::label2_Paint);
		this->label2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Modify::label2_MouseDown);
		this->label2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Modify::label2_MouseMove);
		// 
		// radioButton1
		// 
		this->radioButton1->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton1->BackColor = System::Drawing::SystemColors::ButtonFace;
		this->radioButton1->Location = System::Drawing::Point(22, 23);
		this->radioButton1->Name = L"radioButton1";
		this->radioButton1->Size = System::Drawing::Size(32, 32);
		this->radioButton1->TabIndex = 16;
		this->radioButton1->TabStop = true;
		this->radioButton1->Text = L"1";
		this->radioButton1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton1->UseVisualStyleBackColor = false;
		// 
		// radioButton2
		// 
		this->radioButton2->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton2->BackColor = System::Drawing::SystemColors::Control;
		this->radioButton2->Location = System::Drawing::Point(22, 62);
		this->radioButton2->Name = L"radioButton2";
		this->radioButton2->Size = System::Drawing::Size(32, 32);
		this->radioButton2->TabIndex = 16;
		this->radioButton2->TabStop = true;
		this->radioButton2->Text = L"2";
		this->radioButton2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton2->UseVisualStyleBackColor = false;
		// 
		// radioButton3
		// 
		this->radioButton3->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton3->BackColor = System::Drawing::SystemColors::Control;
		this->radioButton3->Location = System::Drawing::Point(22, 101);
		this->radioButton3->Name = L"radioButton3";
		this->radioButton3->Size = System::Drawing::Size(32, 32);
		this->radioButton3->TabIndex = 16;
		this->radioButton3->TabStop = true;
		this->radioButton3->Text = L"3";
		this->radioButton3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton3->UseVisualStyleBackColor = false;
		// 
		// radioButton4
		// 
		this->radioButton4->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton4->BackColor = System::Drawing::SystemColors::Control;
		this->radioButton4->Location = System::Drawing::Point(22, 140);
		this->radioButton4->Name = L"radioButton4";
		this->radioButton4->Size = System::Drawing::Size(32, 32);
		this->radioButton4->TabIndex = 16;
		this->radioButton4->TabStop = true;
		this->radioButton4->Text = L"4";
		this->radioButton4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton4->UseVisualStyleBackColor = false;
		// 
		// radioButton5
		// 
		this->radioButton5->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton5->BackColor = System::Drawing::SystemColors::Control;
		this->radioButton5->Location = System::Drawing::Point(22, 179);
		this->radioButton5->Name = L"radioButton5";
		this->radioButton5->Size = System::Drawing::Size(32, 32);
		this->radioButton5->TabIndex = 16;
		this->radioButton5->TabStop = true;
		this->radioButton5->Text = L"5";
		this->radioButton5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton5->UseVisualStyleBackColor = false;
		// 
		// radioButton6
		// 
		this->radioButton6->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton6->BackColor = System::Drawing::SystemColors::Control;
		this->radioButton6->Location = System::Drawing::Point(22, 218);
		this->radioButton6->Name = L"radioButton6";
		this->radioButton6->Size = System::Drawing::Size(32, 32);
		this->radioButton6->TabIndex = 16;
		this->radioButton6->TabStop = true;
		this->radioButton6->Text = L"6";
		this->radioButton6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton6->UseVisualStyleBackColor = false;
		// 
		// radioButton7
		// 
		this->radioButton7->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton7->BackColor = System::Drawing::SystemColors::Control;
		this->radioButton7->Location = System::Drawing::Point(22, 257);
		this->radioButton7->Name = L"radioButton7";
		this->radioButton7->Size = System::Drawing::Size(32, 32);
		this->radioButton7->TabIndex = 16;
		this->radioButton7->TabStop = true;
		this->radioButton7->Text = L"7";
		this->radioButton7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton7->UseVisualStyleBackColor = false;
		// 
		// radioButton8
		// 
		this->radioButton8->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton8->BackColor = System::Drawing::SystemColors::Control;
		this->radioButton8->Location = System::Drawing::Point(22, 296);
		this->radioButton8->Name = L"radioButton8";
		this->radioButton8->Size = System::Drawing::Size(32, 32);
		this->radioButton8->TabIndex = 16;
		this->radioButton8->TabStop = true;
		this->radioButton8->Text = L"8";
		this->radioButton8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton8->UseVisualStyleBackColor = false;
		// 
		// radioButton9
		// 
		this->radioButton9->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton9->BackColor = System::Drawing::SystemColors::Control;
		this->radioButton9->Location = System::Drawing::Point(22, 335);
		this->radioButton9->Name = L"radioButton9";
		this->radioButton9->Size = System::Drawing::Size(32, 32);
		this->radioButton9->TabIndex = 16;
		this->radioButton9->TabStop = true;
		this->radioButton9->Text = L"9";
		this->radioButton9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton9->UseVisualStyleBackColor = false;
		// 
		// radioButton10
		// 
		this->radioButton10->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(193)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(193)));
		this->radioButton10->Location = System::Drawing::Point(477, 23);
		this->radioButton10->Name = L"radioButton10";
		this->radioButton10->Size = System::Drawing::Size(32, 32);
		this->radioButton10->TabIndex = 16;
		this->radioButton10->TabStop = true;
		this->radioButton10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton10->UseVisualStyleBackColor = false;
		// 
		// radioButton11
		// 
		this->radioButton11->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton11->BackColor = System::Drawing::Color::LightGoldenrodYellow;
		this->radioButton11->Location = System::Drawing::Point(477, 62);
		this->radioButton11->Name = L"radioButton11";
		this->radioButton11->Size = System::Drawing::Size(32, 32);
		this->radioButton11->TabIndex = 16;
		this->radioButton11->TabStop = true;
		this->radioButton11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton11->UseVisualStyleBackColor = false;
		// 
		// radioButton12
		// 
		this->radioButton12->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton12->BackColor = System::Drawing::Color::PowderBlue;
		this->radioButton12->Location = System::Drawing::Point(477, 101);
		this->radioButton12->Name = L"radioButton12";
		this->radioButton12->Size = System::Drawing::Size(32, 32);
		this->radioButton12->TabIndex = 16;
		this->radioButton12->TabStop = true;
		this->radioButton12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton12->UseVisualStyleBackColor = false;
		// 
		// radioButton13
		// 
		this->radioButton13->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton13->BackColor = System::Drawing::Color::Lavender;
		this->radioButton13->Location = System::Drawing::Point(477, 140);
		this->radioButton13->Name = L"radioButton13";
		this->radioButton13->Size = System::Drawing::Size(32, 32);
		this->radioButton13->TabIndex = 16;
		this->radioButton13->TabStop = true;
		this->radioButton13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton13->UseVisualStyleBackColor = false;
		// 
		// radioButton14
		// 
		this->radioButton14->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		this->radioButton14->Location = System::Drawing::Point(477, 179);
		this->radioButton14->Name = L"radioButton14";
		this->radioButton14->Size = System::Drawing::Size(32, 32);
		this->radioButton14->TabIndex = 16;
		this->radioButton14->TabStop = true;
		this->radioButton14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton14->UseVisualStyleBackColor = false;
		// 
		// radioButton15
		// 
		this->radioButton15->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
			static_cast<System::Int32>(static_cast<System::Byte>(204)));
		this->radioButton15->Location = System::Drawing::Point(477, 218);
		this->radioButton15->Name = L"radioButton15";
		this->radioButton15->Size = System::Drawing::Size(32, 32);
		this->radioButton15->TabIndex = 16;
		this->radioButton15->TabStop = true;
		this->radioButton15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton15->UseVisualStyleBackColor = false;
		// 
		// radioButton16
		// 
		this->radioButton16->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
			static_cast<System::Int32>(static_cast<System::Byte>(206)));
		this->radioButton16->Location = System::Drawing::Point(477, 257);
		this->radioButton16->Name = L"radioButton16";
		this->radioButton16->Size = System::Drawing::Size(32, 32);
		this->radioButton16->TabIndex = 16;
		this->radioButton16->TabStop = true;
		this->radioButton16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton16->UseVisualStyleBackColor = false;
		// 
		// radioButton17
		// 
		this->radioButton17->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton17->BackColor = System::Drawing::Color::PaleTurquoise;
		this->radioButton17->Location = System::Drawing::Point(477, 296);
		this->radioButton17->Name = L"radioButton17";
		this->radioButton17->Size = System::Drawing::Size(32, 32);
		this->radioButton17->TabIndex = 16;
		this->radioButton17->TabStop = true;
		this->radioButton17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton17->UseVisualStyleBackColor = false;
		// 
		// radioButton18
		// 
		this->radioButton18->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
			static_cast<System::Int32>(static_cast<System::Byte>(238)));
		this->radioButton18->Location = System::Drawing::Point(477, 335);
		this->radioButton18->Name = L"radioButton18";
		this->radioButton18->Size = System::Drawing::Size(32, 32);
		this->radioButton18->TabIndex = 16;
		this->radioButton18->TabStop = true;
		this->radioButton18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton18->UseVisualStyleBackColor = false;
		// 
		// radioButton19
		// 
		this->radioButton19->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton19->BackColor = System::Drawing::SystemColors::Control;
		this->radioButton19->Location = System::Drawing::Point(22, 373);
		this->radioButton19->Name = L"radioButton19";
		this->radioButton19->Size = System::Drawing::Size(32, 32);
		this->radioButton19->TabIndex = 16;
		this->radioButton19->TabStop = true;
		this->radioButton19->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton19->UseVisualStyleBackColor = false;
		// 
		// radioButton20
		// 
		this->radioButton20->Appearance = System::Windows::Forms::Appearance::Button;
		this->radioButton20->BackColor = System::Drawing::Color::White;
		this->radioButton20->ForeColor = System::Drawing::SystemColors::Control;
		this->radioButton20->Location = System::Drawing::Point(477, 373);
		this->radioButton20->Name = L"radioButton20";
		this->radioButton20->Size = System::Drawing::Size(32, 32);
		this->radioButton20->TabIndex = 16;
		this->radioButton20->TabStop = true;
		this->radioButton20->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->radioButton20->UseVisualStyleBackColor = false;
		// 
		// button1
		// 
		this->button1->AutoSize = true;
		this->button1->Location = System::Drawing::Point(22, 423);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(84, 31);
		this->button1->TabIndex = 17;
		this->button1->Text = L"清空所有";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &Modify::button1_Click);
		// 
		// button2
		// 
		this->button2->AutoSize = true;
		this->button2->Location = System::Drawing::Point(22, 463);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(84, 31);
		this->button2->TabIndex = 17;
		this->button2->Text = L"清空数字";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &Modify::button2_Click);
		// 
		// button3
		// 
		this->button3->AutoSize = true;
		this->button3->Location = System::Drawing::Point(122, 463);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(84, 31);
		this->button3->TabIndex = 17;
		this->button3->Text = L"清空分组";
		this->button3->UseVisualStyleBackColor = true;
		this->button3->Click += gcnew System::EventHandler(this, &Modify::button3_Click);
		// 
		// button4
		// 
		this->button4->AutoSize = true;
		this->button4->Location = System::Drawing::Point(296, 423);
		this->button4->Name = L"button4";
		this->button4->Size = System::Drawing::Size(100, 31);
		this->button4->TabIndex = 17;
		this->button4->Text = L"标准九宫格";
		this->button4->UseVisualStyleBackColor = true;
		this->button4->Click += gcnew System::EventHandler(this, &Modify::button4_Click);
		// 
		// button5
		// 
		this->button5->AutoSize = true;
		this->button5->Font = (gcnew System::Drawing::Font(L"微软雅黑 Light", 12, System::Drawing::FontStyle::Bold));
		this->button5->ForeColor = System::Drawing::Color::Red;
		this->button5->Location = System::Drawing::Point(431, 448);
		this->button5->Name = L"button5";
		this->button5->Size = System::Drawing::Size(32, 31);
		this->button5->TabIndex = 17;
		this->button5->Text = L"×";
		this->button5->UseVisualStyleBackColor = true;
		this->button5->Click += gcnew System::EventHandler(this, &Modify::button5_Click);
		// 
		// button6
		// 
		this->button6->AutoSize = true;
		this->button6->Font = (gcnew System::Drawing::Font(L"微软雅黑 Light", 12, System::Drawing::FontStyle::Bold));
		this->button6->ForeColor = System::Drawing::Color::Green;
		this->button6->Location = System::Drawing::Point(483, 448);
		this->button6->Name = L"button6";
		this->button6->Size = System::Drawing::Size(32, 31);
		this->button6->TabIndex = 17;
		this->button6->Text = L"√";
		this->button6->UseVisualStyleBackColor = true;
		this->button6->Click += gcnew System::EventHandler(this, &Modify::button6_Click);
		// 
		// button7
		// 
		this->button7->AutoSize = true;
		this->button7->Location = System::Drawing::Point(296, 463);
		this->button7->Name = L"button7";
		this->button7->Size = System::Drawing::Size(100, 31);
		this->button7->TabIndex = 17;
		this->button7->Text = L"检查可行性";
		this->button7->UseVisualStyleBackColor = true;
		this->button7->Click += gcnew System::EventHandler(this, &Modify::button7_Click);
		// 
		// checkBox1
		// 
		this->checkBox1->AutoSize = true;
		this->checkBox1->Location = System::Drawing::Point(124, 425);
		this->checkBox1->Name = L"checkBox1";
		this->checkBox1->Size = System::Drawing::Size(93, 25);
		this->checkBox1->TabIndex = 18;
		this->checkBox1->Text = L"显示组号";
		this->checkBox1->UseVisualStyleBackColor = true;
		this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Modify::checkBox1_CheckedChanged);
		// 
		// check_X
		// 
		this->check_X->AutoSize = true;
		this->check_X->Location = System::Drawing::Point(233, 433);
		this->check_X->Name = L"check_X";
		this->check_X->Size = System::Drawing::Size(39, 25);
		this->check_X->TabIndex = 19;
		this->check_X->Text = L"X";
		this->check_X->UseVisualStyleBackColor = true;
		this->check_X->CheckedChanged += gcnew System::EventHandler(this, &Modify::check_X_CheckedChanged);
		// 
		// check_P
		// 
		this->check_P->AutoSize = true;
		this->check_P->Location = System::Drawing::Point(233, 463);
		this->check_P->Name = L"check_P";
		this->check_P->Size = System::Drawing::Size(43, 25);
		this->check_P->TabIndex = 19;
		this->check_P->Text = L"%";
		this->check_P->UseVisualStyleBackColor = true;
		this->check_P->CheckedChanged += gcnew System::EventHandler(this, &Modify::check_P_CheckedChanged);
		// 
		// Modify
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(9, 21);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(537, 506);
		this->Controls->Add(this->check_P);
		this->Controls->Add(this->check_X);
		this->Controls->Add(this->checkBox1);
		this->Controls->Add(this->button6);
		this->Controls->Add(this->button7);
		this->Controls->Add(this->button5);
		this->Controls->Add(this->button4);
		this->Controls->Add(this->button3);
		this->Controls->Add(this->button2);
		this->Controls->Add(this->button1);
		this->Controls->Add(this->radioButton20);
		this->Controls->Add(this->radioButton18);
		this->Controls->Add(this->radioButton17);
		this->Controls->Add(this->radioButton16);
		this->Controls->Add(this->radioButton15);
		this->Controls->Add(this->radioButton14);
		this->Controls->Add(this->radioButton13);
		this->Controls->Add(this->radioButton12);
		this->Controls->Add(this->radioButton11);
		this->Controls->Add(this->radioButton10);
		this->Controls->Add(this->radioButton19);
		this->Controls->Add(this->radioButton9);
		this->Controls->Add(this->radioButton8);
		this->Controls->Add(this->radioButton7);
		this->Controls->Add(this->radioButton6);
		this->Controls->Add(this->radioButton5);
		this->Controls->Add(this->radioButton4);
		this->Controls->Add(this->radioButton3);
		this->Controls->Add(this->radioButton2);
		this->Controls->Add(this->radioButton1);
		this->Controls->Add(this->label2);
		this->Font = (gcnew System::Drawing::Font(L"微软雅黑 Light", 12));
		this->Margin = System::Windows::Forms::Padding(5);
		this->MaximizeBox = false;
		this->MaximumSize = System::Drawing::Size(553, 545);
		this->MinimumSize = System::Drawing::Size(553, 545);
		this->Name = L"Modify";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
		this->Text = L"编辑数独";
		this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Modify::Modify_FormClosed);
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion
	private: System::Void label2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
	private: System::Void Modify_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
	private: System::Void label2_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void label2_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void check_X_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void check_P_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
};
