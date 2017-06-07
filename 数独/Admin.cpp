#include "StdAfx.h"
#include "Admin.h"


void Admin::InitializeComponent(void)
{
	this->listView1 = (gcnew System::Windows::Forms::ListView());
	this->listView1 = gcnew MyListView();
	this->SuspendLayout();
	// 
	// listView1
	// 
	this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
		| System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->listView1->BackColor = System::Drawing::SystemColors::Window;
	this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
	this->listView1->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(134)));
	this->listView1->Location = System::Drawing::Point(15, 0);
	this->listView1->Margin = System::Windows::Forms::Padding(10);
	this->listView1->Name = L"listView1";
	this->listView1->OwnerDraw = true;
	this->listView1->ShowItemToolTips = true;
	this->listView1->Size = System::Drawing::Size(1106, 717);
	this->listView1->TabIndex = 0;
	this->listView1->TileSize = System::Drawing::Size(202, 227);
	this->listView1->UseCompatibleStateImageBehavior = false;
	this->listView1->View = System::Windows::Forms::View::Tile;
	this->listView1->DrawItem += gcnew System::Windows::Forms::DrawListViewItemEventHandler(this, &Admin::listView1_DrawItem);
	this->listView1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Admin::listView1_MouseClick);
	this->listView1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Admin::listView1_MouseDoubleClick);
	// 
	// Admin
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::SystemColors::Window;
	this->ClientSize = System::Drawing::Size(1121, 717);
	this->Controls->Add(this->listView1);
	this->Name = L"Admin";
	this->Padding = System::Windows::Forms::Padding(0, 15, 0, 0);
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	this->Text = L"数独管理器";
	this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Admin::Admin_FormClosing);
	this->ResumeLayout(false);

}

System::Void Admin::Admin_FormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e)
{
	e->Cancel = true;
	Hide();
	f_parent->TopMost = true;
	f_parent->Show();
	f_parent->TopMost = false;
}

System::Void Admin::reload()
{
	if (sdList)
		delete[] sdList;
	listView1->Clear();
	if (!Directory::Exists("Games"))
	{
		Directory::CreateDirectory("Games");
		return;
	}
	DirectoryInfo^ folder = gcnew DirectoryInfo("Games");
	array<FileInfo^>^ files = folder->GetFiles("*.sd");
	sdList = gcnew array<SDoc^>(files->Length);
	for (int i = 0; i < files->Length; ++i)
	{
		ListViewItem^ item =  gcnew ListViewItem(files[i]->Name);
		item->ToolTipText = files[i]->Name;
		listView1->Items->Add(item);
	}
}

System::Void Admin::listView1_DrawItem(System::Object ^ sender, System::Windows::Forms::DrawListViewItemEventArgs ^ e)
{
	Rectangle rect = e->Bounds;
	rect.Height -= 6;
	BufferedGraphicsContext^ currentContext = BufferedGraphicsManager::Current;
	BufferedGraphics^ myBuffer = currentContext->Allocate(e->Graphics, e->Bounds);
	Graphics^ g = myBuffer->Graphics;
	g->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighSpeed;
	g->Clear(listView1->BackColor);

	if (listView1->SelectedIndices->Contains(e->ItemIndex))
	{
		Rectangle r(int(e->Bounds.Left + 2.5), e->Bounds.Top + 5, e->Bounds.Width - 6, e->Bounds.Height - 6);
		SolidBrush^ br = gcnew SolidBrush(Color::FromArgb(0xFFCCE8FF));
		g->FillRectangle(br, r);
		g->DrawRectangle(gcnew Pen(Color::FromArgb(0xFF99D1FF)), r);
	}

	if (!sdList[e->ItemIndex])
		sdList[e->ItemIndex] = gcnew SDoc("Games\\" + e->Item->Text);
	DSS dss;
	dss.a = float(e->Bounds.Width - 15);
	dss.type = DSS::DS_Admin;
	dss.left = float(e->Bounds.Left + 6.5);
	dss.top = float(e->Bounds.Top + 9);
	dss.penw = 1.5;
	sdList[e->ItemIndex]->sd()->Draw(g, dss);

	Drawing::Font^ font = gcnew Drawing::Font("You yuan", 12);
	StringFormat^ sf = gcnew StringFormat;
	sf->LineAlignment = StringAlignment::Far;
	sf->Alignment = StringAlignment::Center;
	sf->FormatFlags = StringFormatFlags::NoWrap;
	g->DrawString(e->Item->Text->Substring(0, e->Item->Text->Length - 3), font, Brushes::Black, rect, sf);

	myBuffer->Render(e->Graphics);

	delete g;
	delete myBuffer; //释放资源
}

System::Void Admin::listView1_MouseClick(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	if (e->Button == ::MouseButtons::Right && listView1->SelectedItems->Count)
	{
		System::Windows::Forms::ContextMenuStrip^ context = gcnew System::Windows::Forms::ContextMenuStrip();
		context->Name = L"contextMenu";
		int num = 0;

		System::Windows::Forms::ToolStripItem^ item;

		if (listView1->SelectedItems->Count == 1)
		{
			item = gcnew System::Windows::Forms::ToolStripMenuItem();
			item->Size = System::Drawing::Size(97, 22);
			item->Name = L"context_item_open";
			item->Text = "打开";
			item->Click += gcnew System::EventHandler(this, &Admin::handle_open);
			context->Items->Add(item);
			num++;

			item = gcnew System::Windows::Forms::ToolStripMenuItem();
			item->Size = System::Drawing::Size(97, 22);
			item->Name = L"context_item_modify";
			item->Text = "修改";
			item->Click += gcnew System::EventHandler(this, &Admin::handle_modify);
			context->Items->Add(item);
			num++;
		}

		item = gcnew System::Windows::Forms::ToolStripMenuItem();
		item->Size = System::Drawing::Size(97, 22);
		item->Name = L"context_item_reload";
		item->Text = "刷新";
		item->Click += gcnew System::EventHandler(this, &Admin::handle_reload);
		context->Items->Add(item);
		num++;

		item = gcnew System::Windows::Forms::ToolStripMenuItem();
		item->Size = System::Drawing::Size(97, 22);
		item->Name = L"context_item_delete";
		item->Text = "删除";
		item->Click += gcnew System::EventHandler(this, &Admin::handle_delete);
		context->Items->Add(item);
		num++;

		context->Size = System::Drawing::Size(97 * num + 1, 26);
		context->Show(listView1, e->X, e->Y);
	}
}

System::Void Admin::listView1_MouseDoubleClick(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e)
{
	if (e->Button == ::MouseButtons::Left && listView1->SelectedItems->Count)
		handle_open(sender, e);
}

System::Void Admin::handle_reload(System::Object^  sender, System::EventArgs^  e)
{
	reload();
}

System::Void Admin::handle_delete(System::Object^  sender, System::EventArgs^  e)
{
	if (MessageBox::Show("确认永久删除选中的" + listView1->SelectedItems->Count.ToString() + "个数独吗？",
		"确认删除", MessageBoxButtons::OKCancel) == ::DialogResult::Cancel)
		return;
	for each (ListViewItem^ item in listView1->SelectedItems)
	{
		FileInfo^ fi = gcnew FileInfo("Games\\" + item->Text);
		if (fi->Exists)
			fi->Delete();
	}
	reload();
}

System::Void Admin::handle_open(System::Object^  sender, System::EventArgs^  e)
{
	f_parent->load("Games\\" + listView1->SelectedItems[0]->Text);
	Close();
}

System::Void Admin::handle_modify(System::Object^  sender, System::EventArgs^  e)
{
	Enabled = false;
	Modify^ m = gcnew Modify(this, "Games\\" + listView1->SelectedItems[0]->Text);
	m->Show();
}

void Admin::modify_ok(String^ filename)
{
	Enabled = true;
	reload();
}

void Admin::modify_cancel()
{
	Enabled = true;
}
