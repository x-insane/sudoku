#include "StdAfx.h"
#include "Admin.h"

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
		listView1->Items->AddRange(gcnew cli::array<System::Windows::Forms::ListViewItem^>(1) { gcnew System::Windows::Forms::ListViewItem(files[i]->Name) });
}

System::Void Admin::listView1_DrawItem(System::Object ^ sender, System::Windows::Forms::DrawListViewItemEventArgs ^ e)
{
	/*
	Rectangle rect = e->Bounds;
	rect.Height -= 8;
	if (!sdList[e->ItemIndex])
		sdList[e->ItemIndex] = gcnew SDoc("Games\\" + e->Item->Text);
	DSS dss;
	dss.a = float(e->Bounds.Width - 8);
	dss.type = DSS::DS_Admin;
	dss.left = float(e->Bounds.Left + 4);
	dss.top = float(e->Bounds.Top);
	dss.penw = 2;
	sdList[e->ItemIndex]->sd()->Draw(e->Graphics, dss);

	Drawing::Font^ font = gcnew Drawing::Font("You yuan", 12);
	StringFormat^ sf = gcnew StringFormat;
	sf->LineAlignment = StringAlignment::Far;
	sf->Alignment = StringAlignment::Center;
	e->Graphics->DrawString(e->Item->Text->Substring(0, e->Item->Text->Length - 3), font, Brushes::Black, rect, sf);
	*/
	Rectangle rect = e->Bounds;
	rect.Height -= 6;
	BufferedGraphicsContext^ currentContext = BufferedGraphicsManager::Current;
	BufferedGraphics^ myBuffer = currentContext->Allocate(e->Graphics, e->Bounds);
	Graphics^ g = myBuffer->Graphics;
	g->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
	g->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighSpeed;
	g->Clear(listView1->BackColor);

	if (!sdList[e->ItemIndex])
		sdList[e->ItemIndex] = gcnew SDoc("Games\\" + e->Item->Text);
	DSS dss;
	dss.a = float(e->Bounds.Width - 8);
	dss.type = DSS::DS_Admin;
	dss.left = float(e->Bounds.Left + 4);
	dss.top = float(e->Bounds.Top + 4);
	dss.penw = 2;
	sdList[e->ItemIndex]->sd()->Draw(g, dss);

	Drawing::Font^ font = gcnew Drawing::Font("You yuan", 12);
	StringFormat^ sf = gcnew StringFormat;
	sf->LineAlignment = StringAlignment::Far;
	sf->Alignment = StringAlignment::Center;
	g->DrawString(e->Item->Text->Substring(0, e->Item->Text->Length - 3), font, Brushes::Black, rect, sf);

	myBuffer->Render(e->Graphics);

	if(e->State.HasFlag(ListViewItemStates::Selected))
		e->DrawFocusRectangle();

	delete g;
	delete myBuffer; //ÊÍ·Å×ÊÔ´
}

System::Void Admin::listView1_DoubleClick(System::Object ^ sender, System::EventArgs ^ e)
{
	if (listView1->CheckedItems->Count)
	{
		f_parent->doc->open("Games\\" + listView1->CheckedItems[0]->Text);
		Close();
	}
}
