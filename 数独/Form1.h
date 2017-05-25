#pragma once

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
	Admin^ f_admin;
	AddSudoku^ f_add_sudoku;
	int i,j;
public:
	Sudoku* p_sd;

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
private: System::Windows::Forms::ToolStripMenuItem^  addsudokuToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  modifysudokuToolStripMenuItem;

private: System::Windows::Forms::ToolStripMenuItem^  mi_manage;

public:
	Form1();

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
			this->addsudokuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->modifysudokuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->mi_game, this->mi_manage });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(674, 25);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mi_game
			// 
			this->mi_game->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->mi_restart,
					this->mi_is_showtip, this->solveToolStripMenuItem, this->answerToolStripMenuItem, this->addsudokuToolStripMenuItem, this->modifysudokuToolStripMenuItem
			});
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
			// addsudokuToolStripMenuItem
			// 
			this->addsudokuToolStripMenuItem->Name = L"addsudokuToolStripMenuItem";
			this->addsudokuToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->addsudokuToolStripMenuItem->Text = L"制作数独";
			this->addsudokuToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::addsudokuToolStripMenuItem_Click);
			// 
			// modifysudokuToolStripMenuItem
			// 
			this->modifysudokuToolStripMenuItem->Name = L"modifysudokuToolStripMenuItem";
			this->modifysudokuToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->modifysudokuToolStripMenuItem->Text = L"修改数独";
			this->modifysudokuToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::modifysudokuToolStripMenuItem_Click);
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
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->toolStripMenuItem2,
					this->toolStripMenuItem3, this->toolStripMenuItem4, this->toolStripMenuItem5, this->toolStripMenuItem6, this->toolStripMenuItem7,
					this->toolStripMenuItem8, this->toolStripMenuItem9, this->toolStripMenuItem10
			});
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
			this->contextMenuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->resetijToolStripMenuItem });
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
	private: System::Void 管理ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void label1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
	private: System::Void label1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void mi_is_showtip_Click(System::Object^  sender, System::EventArgs^  e) {
				 mi_is_showtip->Checked = !mi_is_showtip->Checked;
			 }
	private: System::Void handle_play(System::Object^  sender, System::EventArgs^  e);
	private: System::Void mi_restart_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void resetijToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void solveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void answerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void addsudokuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void modifysudokuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
};
