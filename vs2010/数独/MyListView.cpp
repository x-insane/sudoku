#include "stdafx.h"
#include "MyListView.h"


MyListView::MyListView()
{
	// ¿ªÆôË«»º³å
	SetStyle(ControlStyles::OptimizedDoubleBuffer | ControlStyles::AllPaintingInWmPaint, true);
	SetStyle(ControlStyles::EnableNotifyMessage, true);
}


void MyListView::OnNotifyMessage(Message m)
{
	// ×èÖ¹ WM_ERASEBKGND ÏûÏ¢
	if (m.Msg != 0x14)
	{
		ListView::OnNotifyMessage(m);
	}
}
