#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// AddSudoku 摘要
	/// </summary>
	public ref class AddSudoku : public System::Windows::Forms::Form
	{
		Form1^ f_parent;
	public:
		AddSudoku(Form1^ parent)
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
		~AddSudoku()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  data_text;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  group_text;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->data_text = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->group_text = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"数独名：";
			this->textBox1->Location = System::Drawing::Point(104, 18);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(180, 27);
			this->textBox1->TabIndex = 1;
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 19);
			this->label2->TabIndex = 2;
			this->label2->Text = L"数独数据";
			this->data_text->Location = System::Drawing::Point(20, 102);
			this->data_text->Multiline = true;
			this->data_text->Name = L"data_text";
			this->data_text->Size = System::Drawing::Size(210, 239);
			this->data_text->TabIndex = 3;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(294, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 19);
			this->label3->TabIndex = 4;
			this->label3->Text = L"分组数据";
			this->group_text->Location = System::Drawing::Point(300, 102);
			this->group_text->Multiline = true;
			this->group_text->Name = L"group_text";
			this->group_text->Size = System::Drawing::Size(210, 239);
			this->group_text->TabIndex = 3;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(310, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 19);
			this->label4->TabIndex = 5;
			this->label4->Text = L"作者：";
			this->textBox4->Location = System::Drawing::Point(383, 18);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(127, 27);
			this->textBox4->TabIndex = 6;
			this->button1->Location = System::Drawing::Point(383, 367);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 32);
			this->button1->TabIndex = 7;
			this->button1->Text = L"导出";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddSudoku::button1_Click);
			this->button2->Location = System::Drawing::Point(241, 367);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 32);
			this->button2->TabIndex = 7;
			this->button2->Text = L"显示";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddSudoku::button2_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 421);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->group_text);
			this->Controls->Add(this->data_text);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"等线", 14.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddSudoku";
			this->Text = L"制作数独";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AddSudoku::AddSudoku_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void AddSudoku_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 e->Cancel = true;
				 Hide();
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
};
