#include "stdafx.h"

Form1::Form1()
{
	InitializeComponent();
	//
	//TODO: 在此处添加构造函数代码
	//
	f_admin = gcnew Admin(this);
	f_add_sudoku = gcnew AddSudoku(this);
	p_sd = new Sudoku();
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
	if(p_sd->set(data, group) != Status::Ok)
	{
	}
}

System::Void Form1::管理ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Hide();
	f_admin->reload();
	f_admin->Show();
}

System::Void Form1::label1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	Graphics^ dc = e->Graphics;
	float a = 360; // 绘制数独区域的边长
	if(label1->Width > 900 && label1->Height > 900)
		a = 800;
	else if(label1->Width > 400 && label1->Height > 400)
		a = float(min(label1->Width, label1->Height) * 0.9);
	// 以上为大小自适应代码
	float x = (label1->Width - a) / 2;
	float y = (label1->Height - a) / 2; // 数独区域左上角坐标

	Pen^ pen = gcnew Pen(Color::Black, 3);

	for(int i=0;i<10;++i)
	{
		// 黑色线画边框，灰色线画内部小格
		dc->DrawLine(i%9 ? Pens::LightGray : pen, x + i*a/9, y, x + i*a/9, y + a);
		dc->DrawLine(i%9 ? Pens::LightGray : pen, x, y + i*a/9, x + a, y + i*a/9);
	}
			 
	Board board = p_sd->get();
	System::Drawing::Font^ font = gcnew System::Drawing::Font("You yuan", a/18);
	StringFormat^ sf = gcnew StringFormat;
	sf->LineAlignment = StringAlignment::Center;
	sf->Alignment = StringAlignment::Center;
	for(int i=0;i<9;++i)
	{
		for(int j=0;j<9;++j)
		{
			Rectangle rect = Rectangle(int(x+i*a/9+2+0.5), int(y+j*a/9+2+0.5), int(a/9-1), int(a/9-1));
			/*switch(board[j+1][i+1].group)
			{
			case 1:
				dc->FillRectangle(Brushes::Pink, rect);
				break;
			}*/
			if(i && board[j+1][i+1].group != board[j+1][i].group)
				dc->DrawLine(pen, x+i*a/9, y+j*a/9, x+i*a/9, y+(j+1)*a/9); // 用粗线画左边框
			if(j && board[j+1][i+1].group != board[j][i+1].group)
				dc->DrawLine(pen, x+i*a/9, y+j*a/9, x+(i+1)*a/9, y+j*a/9); // 用粗线画上边框
			System::Drawing::Brush^ brush = Brushes::Black;
			if(board[j+1][i+1].who == 1)
				brush = Brushes::Blue;
			else if(board[j+1][i+1].who == 2)
				brush = Brushes::Green;
			else if(board[j+1][i+1].who == 3)
				brush = Brushes::Red;
			if(board[j+1][i+1].num)
			dc->DrawString(board[j+1][i+1].num.ToString(), font, brush, rect, sf);
		}
	}
	delete pen;
	delete font;
	delete sf;
}

System::Void Form1::label1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if(p_sd->status() == Status::Win)
		return;
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
	SD sd = p_sd->get()[j][i];
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

System::Void Form1::handle_play(System::Object^  sender, System::EventArgs^  e)
{
	int k = int::Parse(sender->ToString());
	p_sd->play(i, j, k);
	this->Text = "数独 - " + %String(p_sd->status_string());
	Invalidate(true);
	if(p_sd->status() == Status::Win)
		MessageBox::Show(L"恭喜你完成了整个数独！", L"游戏结束");
}

System::Void Form1::mi_restart_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(p_sd->status() == Status::Loaded)
		return;
	if(MessageBox::Show(L"游戏状态将被丢弃，确认重新开始吗？", L"重新开始", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning)
		== System::Windows::Forms::DialogResult::OK)
	{
		p_sd->reset();
		this->Text = "数独 - " + %String(p_sd->status_string());
		Invalidate(true);
	}
}

System::Void Form1::resetijToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	p_sd->reset(i, j);
	this->Text = "数独 - " + %String(p_sd->status_string());
	Invalidate(true);
}

System::Void Form1::solveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	switch(p_sd->solve(false))
	{
	case Status::Error:
		MessageBox::Show(L"当前状态不能使用本功能", L"提示");
		break;
	case Status::Wrong:
		MessageBox::Show(L"当前状态没有可行解", L"提示");
		break;
	}
	this->Text = "数独 - " + %String(p_sd->status_string());
	Invalidate(true);
}

System::Void Form1::answerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	switch(p_sd->solve(true))
	{
	case Status::Error:
		MessageBox::Show(L"当前状态不能使用本功能", L"提示");
		break;
	case Status::Wrong:
		MessageBox::Show(L"当前状态没有可行解", L"提示");
		break;
	}
	this->Text = "数独 - " + %String(p_sd->status_string());
	Invalidate(true);
}

System::Void Form1::addsudokuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	f_add_sudoku->Show();
	f_add_sudoku->Focus();
}