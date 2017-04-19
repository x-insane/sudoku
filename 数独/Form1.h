#pragma once

#include "Sudoku.h"
#include "SDoc.h"
#include "Admin.h"
#define min(a ,b) ((a)<(b)?(a):(b))

namespace 数独 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		Algorithm::Sudoku* p_sd;
		Document::SDoc m_doc;
		Admin^ f_admin;
		int i,j;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_game;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_restart;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_is_showtip;




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem6;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem7;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem8;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem9;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem10;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  resetijToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  solveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  answerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_manage;



	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
			f_admin = gcnew Admin(this);
			p_sd = new Algorithm::Sudoku();
			/*int data[10][10] =
			{
				{0,0,0,0,0,0,0,0,0,0},
				{0,0,0,9,5,3,6,0,0,4},
				{0,5,0,0,0,0,0,3,0,0},
				{0,0,3,0,7,9,0,0,0,0},
				{0,8,6,0,4,0,0,9,5,0},
				{0,3,0,4,0,5,0,2,0,8},
				{0,0,7,5,0,0,8,0,4,3},
				{0,0,0,0,0,4,7,0,8,0},
				{0,0,0,7,0,0,0,0,0,2},
				{0,4,0,0,1,6,2,7,0,0}
			};
			int group[10][10] = 
			{
				{0,0,0,0,0,0,0,0,0,0},
				{0,1,1,1,2,2,2,3,3,3},
				{0,1,1,1,2,2,2,3,3,3},
				{0,1,1,1,2,2,2,3,3,3},
				{0,4,4,4,5,5,5,6,6,6},
				{0,4,4,4,5,5,5,6,6,6},
				{0,4,4,4,5,5,5,6,6,6},
				{0,7,7,7,8,8,8,9,9,9},
				{0,7,7,7,8,8,8,9,9,9},
				{0,7,7,7,8,8,8,9,9,9}
			};*/
			int data[10][10] =
			{
				{0,0,0,0,0,0,0,0,0,0},
				{0,0,0,9,0,0,0,0,0,4},
				{0,0,0,0,0,0,0,0,2,0},
				{0,0,6,0,0,0,2,3,0,0},
				{0,5,3,0,0,0,0,1,0,0},
				{0,0,2,0,0,0,0,0,1,0},
				{0,0,0,7,0,0,0,0,8,9},
				{0,0,0,5,8,0,0,0,4,0},
				{0,0,1,0,0,0,0,0,0,0},
				{0,4,0,0,0,0,0,9,0,0}
			};
			int group[10][10] = 
			{
				{0,0,0,0,0,0,0,0,0,0},
				{0,1,2,2,2,3,4,4,4,4},
				{0,1,1,1,2,3,3,3,4,4},
				{0,1,1,2,2,3,7,3,4,4},
				{0,1,2,2,2,7,7,3,3,4},
				{0,1,1,6,7,7,7,3,9,9},
				{0,5,6,6,7,7,8,8,8,9},
				{0,5,5,6,7,6,8,8,9,9},
				{0,5,5,6,6,6,8,9,9,9},
				{0,5,5,5,5,6,8,8,8,9}
			};
			if(p_sd->set(data, group) != Algorithm::Status::Ok)
			{
			}
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mi_game = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mi_restart = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mi_is_showtip = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->solveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->answerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mi_manage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem7 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem8 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem9 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem10 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->resetijToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->contextMenuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->mi_game, this->mi_manage});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(674, 25);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mi_game
			// 
			this->mi_game->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->mi_restart, 
				this->mi_is_showtip, this->solveToolStripMenuItem, this->answerToolStripMenuItem});
			this->mi_game->Name = L"mi_game";
			this->mi_game->Size = System::Drawing::Size(44, 21);
			this->mi_game->Text = L"游戏";
			// 
			// mi_restart
			// 
			this->mi_restart->Name = L"mi_restart";
			this->mi_restart->Size = System::Drawing::Size(152, 22);
			this->mi_restart->Text = L"重新开始";
			this->mi_restart->Click += gcnew System::EventHandler(this, &Form1::mi_restart_Click);
			// 
			// mi_is_showtip
			// 
			this->mi_is_showtip->Name = L"mi_is_showtip";
			this->mi_is_showtip->Size = System::Drawing::Size(152, 22);
			this->mi_is_showtip->Text = L"显示提示";
			this->mi_is_showtip->Click += gcnew System::EventHandler(this, &Form1::mi_is_showtip_Click);
			// 
			// solveToolStripMenuItem
			// 
			this->solveToolStripMenuItem->Name = L"solveToolStripMenuItem";
			this->solveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->solveToolStripMenuItem->Text = L"模拟解数独";
			this->solveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::solveToolStripMenuItem_Click);
			// 
			// answerToolStripMenuItem
			// 
			this->answerToolStripMenuItem->Name = L"answerToolStripMenuItem";
			this->answerToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->answerToolStripMenuItem->Text = L"显示答案";
			this->answerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::answerToolStripMenuItem_Click);
			// 
			// mi_manage
			// 
			this->mi_manage->Name = L"mi_manage";
			this->mi_manage->Size = System::Drawing::Size(44, 21);
			this->mi_manage->Text = L"管理";
			this->mi_manage->Click += gcnew System::EventHandler(this, &Form1::管理ToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Location = System::Drawing::Point(0, 25);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(674, 567);
			this->label1->TabIndex = 3;
			this->label1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::label1_Paint);
			this->label1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::label1_MouseClick);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {this->toolStripMenuItem2, 
				this->toolStripMenuItem3, this->toolStripMenuItem4, this->toolStripMenuItem5, this->toolStripMenuItem6, this->toolStripMenuItem7, 
				this->toolStripMenuItem8, this->toolStripMenuItem9, this->toolStripMenuItem10});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(84, 202);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(83, 22);
			this->toolStripMenuItem2->Text = L"1";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &Form1::handle_play);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(83, 22);
			this->toolStripMenuItem3->Text = L"2";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &Form1::handle_play);
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(83, 22);
			this->toolStripMenuItem4->Text = L"3";
			this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &Form1::handle_play);
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(83, 22);
			this->toolStripMenuItem5->Text = L"4";
			this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &Form1::handle_play);
			// 
			// toolStripMenuItem6
			// 
			this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
			this->toolStripMenuItem6->Size = System::Drawing::Size(83, 22);
			this->toolStripMenuItem6->Text = L"5";
			this->toolStripMenuItem6->Click += gcnew System::EventHandler(this, &Form1::handle_play);
			// 
			// toolStripMenuItem7
			// 
			this->toolStripMenuItem7->Name = L"toolStripMenuItem7";
			this->toolStripMenuItem7->Size = System::Drawing::Size(83, 22);
			this->toolStripMenuItem7->Text = L"6";
			this->toolStripMenuItem7->Click += gcnew System::EventHandler(this, &Form1::handle_play);
			// 
			// toolStripMenuItem8
			// 
			this->toolStripMenuItem8->Name = L"toolStripMenuItem8";
			this->toolStripMenuItem8->Size = System::Drawing::Size(83, 22);
			this->toolStripMenuItem8->Text = L"7";
			this->toolStripMenuItem8->Click += gcnew System::EventHandler(this, &Form1::handle_play);
			// 
			// toolStripMenuItem9
			// 
			this->toolStripMenuItem9->Name = L"toolStripMenuItem9";
			this->toolStripMenuItem9->Size = System::Drawing::Size(83, 22);
			this->toolStripMenuItem9->Text = L"8";
			this->toolStripMenuItem9->Click += gcnew System::EventHandler(this, &Form1::handle_play);
			// 
			// toolStripMenuItem10
			// 
			this->toolStripMenuItem10->Name = L"toolStripMenuItem10";
			this->toolStripMenuItem10->Size = System::Drawing::Size(83, 22);
			this->toolStripMenuItem10->Text = L"9";
			this->toolStripMenuItem10->Click += gcnew System::EventHandler(this, &Form1::handle_play);
			// 
			// contextMenuStrip2
			// 
			this->contextMenuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->resetijToolStripMenuItem});
			this->contextMenuStrip2->Name = L"contextMenuStrip2";
			this->contextMenuStrip2->Size = System::Drawing::Size(125, 26);
			// 
			// resetijToolStripMenuItem
			// 
			this->resetijToolStripMenuItem->Name = L"resetijToolStripMenuItem";
			this->resetijToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->resetijToolStripMenuItem->Text = L"取消填入";
			this->resetijToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::resetijToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(674, 592);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(460, 460);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"数独";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->contextMenuStrip2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void 管理ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			Hide();
			f_admin->Show();
		 }
private: System::Void label1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 Graphics^ dc = e->Graphics;
			 float a = 360; // 绘制数独区域的边长
			 if(label1->Width > 900 && label1->Height > 900)
				 a = 800;
			 else if(label1->Width > 400 && label1->Height > 400)
				 a = float(min(label1->Width, label1->Height) * 0.9);
			 // 以上为大小自适应代码
			 float x = (label1->Width - a) / 2;
			 float y = (label1->Height - a) / 2; // 数独区域左上角坐标
			 for(int i=0;i<10;++i)
			 {
				 // 黑色线画边框九宫格，灰色线画内部小格
				 dc->DrawLine(i%9 ? Pens::LightGray : Pens::Black, x, y + i*a/9, x + a, y + i*a/9);
				 dc->DrawLine(i%9 ? Pens::LightGray : Pens::Black, x + i*a/9, y, x + i*a/9, y + a);
			 }
			 
			 Algorithm::Board board = p_sd->get();
			 System::Drawing::Font^ font = gcnew System::Drawing::Font("You yuan", a/18);
			 StringFormat^ sf = gcnew StringFormat;
			 sf->LineAlignment = StringAlignment::Center;
			 sf->Alignment = StringAlignment::Center;
			 for(int i=0;i<9;++i)
			 {
				 for(int j=0;j<9;++j)
				 {
					 if(i && board[j+1][i+1].group != board[j+1][i].group)
						 dc->DrawLine(Pens::Black, x+i*a/9, y+j*a/9, x+i*a/9, y+(j+1)*a/9); // 用粗线画左边框
					 if(j && board[j+1][i+1].group != board[j][i+1].group)
						 dc->DrawLine(Pens::Black, x+i*a/9, y+j*a/9, x+(i+1)*a/9, y+j*a/9); // 用粗线画上边框
					 System::Drawing::Brush^ brush = Brushes::Black;
					 if(board[j+1][i+1].who == 1)
						 brush = Brushes::Blue;
					 else if(board[j+1][i+1].who == 2)
						 brush = Brushes::Green;
					 else if(board[j+1][i+1].who == 3)
						 brush = Brushes::Red;
					 if(board[j+1][i+1].num)
						dc->DrawString(board[j+1][i+1].num.ToString(), font, brush, Rectangle(int(x+i*a/9+2), int(y+j*a/9+2), int(a/9), int(a/9)), sf);
				 }
			 }
			 delete font;
			 delete sf;
		 }
private: System::Void label1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 float a = 360;
			 if(label1->Width > 900 && label1->Height > 900)
				 a = 800;
			 else if(label1->Width > 400 && label1->Height > 400)
				 a = float(min(label1->Width, label1->Height) * 0.9);
			 float x = (label1->Width - a) / 2;
			 float y = (label1->Height - a) / 2;
			 if(e->X < x || e->Y < y)
				 return;
			 int i = int((e->X - x)/(a/9)) + 1;
			 int j = int((e->Y - y)/(a/9)) + 1;
			 if(i<1 || i>9 || j<1 || j>9)
				 return;
			 Algorithm::SD sd = p_sd->get()[j][i];
			 this->i = j;
			 this->j = i;
			 if(sd.num)
			 {
				 if(sd.who)
					contextMenuStrip2->Show(label1, e->X, e->Y);
			 }
			 else if(mi_is_showtip->Checked)
			 {
				 System::Windows::Forms::ContextMenuStrip^ context = gcnew System::Windows::Forms::ContextMenuStrip();
				 context->Name = L"contextMenu";
				 context->Size = System::Drawing::Size(97*sd.range+1, 26);
				 for(int k=1;k<10;++k)
				 {
					 if(sd.is[k])
					 {
						 System::Windows::Forms::ToolStripItem^ item = gcnew System::Windows::Forms::ToolStripMenuItem();
						 item->Size = System::Drawing::Size(97, 22);
						 item->Name = L"context_item_" + k.ToString();
						 item->Text = k.ToString();
						 item->Click += gcnew System::EventHandler(this, &Form1::handle_play);
						 context->Items->AddRange(gcnew cli::array<ToolStripItem^ >(1){ item });
					 }
				 }
				 context->Show(label1, e->X, e->Y);
			 }
			 else
				 contextMenuStrip1->Show(label1, e->X, e->Y);
		 }
private: System::Void mi_is_showtip_Click(System::Object^  sender, System::EventArgs^  e) {
			 mi_is_showtip->Checked = !mi_is_showtip->Checked;
		 }
private: System::Void handle_play(System::Object^  sender, System::EventArgs^  e) {
			 int k = int::Parse(sender->ToString());
			 p_sd->play(i, j, k);
			 this->Text = "数独 - " + %String(p_sd->status_string());
			 Invalidate(true);
		 }
private: System::Void mi_restart_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(p_sd->status() == Algorithm::Status::Loaded)
				 return;
			 if(MessageBox::Show(L"游戏数据将被丢弃，确认重新开始吗？", L"重新开始", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning)
				 == System::Windows::Forms::DialogResult::OK)
			 {
				 p_sd->reset();
				 this->Text = "数独 - " + %String(p_sd->status_string());
				 Invalidate(true);
			 }
		 }
private: System::Void resetijToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 p_sd->reset(i, j);
			 this->Text = "数独 - " + %String(p_sd->status_string());
			 Invalidate(true);
		 }
private: System::Void solveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 switch(p_sd->solve(false))
			 {
			 case Algorithm::Status::Error:
				 MessageBox::Show(L"当前状态不能使用本功能", L"提示");
				 break;
			 case Algorithm::Status::Wrong:
				 MessageBox::Show(L"当前状态没有可行解", L"提示");
				 break;
			 }
			 this->Text = "数独 - " + %String(p_sd->status_string());
			 Invalidate(true);
		 }
private: System::Void answerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 switch(p_sd->solve(true))
			 {
			 case Algorithm::Status::Error:
				 MessageBox::Show(L"当前状态不能使用本功能", L"提示");
				 break;
			 case Algorithm::Status::Wrong:
				 MessageBox::Show(L"当前状态没有可行解", L"提示");
				 break;
			 }
			 this->Text = "数独 - " + %String(p_sd->status_string());
			 Invalidate(true);
		 }
};
}

