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
	public ref class Admin : public System::Windows::Forms::Form
	{
		System::Windows::Forms::Form^ f_parent;

	public:

	public:
		Admin(System::Windows::Forms::Form^ parent)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
			f_parent = parent;
		}

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
		void InitializeComponent(void)
		{
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Alignment = System::Windows::Forms::ListViewAlignment::Left;
			this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listView1->Font = (gcnew System::Drawing::Font(L"����", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->listView1->ImeMode = System::Windows::Forms::ImeMode::On;
			this->listView1->Location = System::Drawing::Point(30, 24);
			this->listView1->Margin = System::Windows::Forms::Padding(30);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1061, 663);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
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
			this->Text = L"����������";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Admin::Admin_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Admin_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 e->Cancel = true;
				 Hide();
				 f_parent->TopMost = true;
				 f_parent->Show();
				 f_parent->TopMost = false;
			 }
			 /*
	private: System::Void listView1_DrawItem(System::Object^  sender, System::Windows::Forms::DrawListViewItemEventArgs^  e) {
				 if (listView1->SelectedIndices->Count)
				 {
					e->State;
				 }
			}
	private: System::Void listView1_DrawColumnHeader(System::Object^  sender, System::Windows::Forms::DrawListViewColumnHeaderEventArgs^  e) {
				 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial", 10);
				 SolidBrush^ drawBrush = gcnew SolidBrush( Color::Black );
				 Rectangle drawRect = e->Bounds;
				 Pen^ blackPen = gcnew Pen( Color::Black );
				 StringFormat^ drawFormat = gcnew StringFormat;
				 drawFormat->Alignment = StringAlignment::Center;
				 drawFormat->LineAlignment = StringAlignment::Center;
				 e->Graphics->DrawString( e->Header->Text, drawFont, drawBrush, drawRect, drawFormat);
			 }
	private: System::Void listView1_DrawSubItem(System::Object^  sender, System::Windows::Forms::DrawListViewSubItemEventArgs^  e) {
				if (e->ItemState == (Windows::Forms::ListViewItemStates)529)
				{
					Rectangle drawRect = e->Bounds;
					SolidBrush^ drawBrush = gcnew SolidBrush(Color::Blue);
					e->Graphics->FillRectangle(drawBrush, drawRect);
				}
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial", 10);
				SolidBrush^ drawBrush = gcnew SolidBrush( Color::Black );
				Rectangle drawRect = e->Bounds;
				Pen^ blackPen = gcnew Pen( Color::Black );
				StringFormat^ drawFormat = gcnew StringFormat;
				if (e->ColumnIndex == 0)
					drawFormat->Alignment = StringAlignment::Far;
				else
					drawFormat->Alignment = StringAlignment::Center;
				drawFormat->LineAlignment = StringAlignment::Center;
				e->Graphics->DrawString( e->SubItem->Text, drawFont, drawBrush, drawRect, drawFormat);
			}*/
public: System::Void reload()
		{
			listView1->Clear();
			if(!Directory::Exists("Games"))
			{
				Directory::CreateDirectory("Games");
				return;
			}
			array<String^>^ all = Directory::GetFiles("Games", "*.sd");
			for(int i=0;i<all->Length;++i)
				listView1->Items->AddRange(gcnew cli::array<System::Windows::Forms::ListViewItem^>(1){gcnew System::Windows::Forms::ListViewItem(all[i])});
		}
};
