#include "stdafx.h"
#include "MyListView.h"


MyListView::MyListView()
{
	// ����˫����
	SetStyle(ControlStyles::OptimizedDoubleBuffer | ControlStyles::AllPaintingInWmPaint, true);
	SetStyle(ControlStyles::EnableNotifyMessage, true);
}


void MyListView::OnNotifyMessage(Message m)
{
	// ��ֹ WM_ERASEBKGND ��Ϣ
	if (m.Msg != 0x14)
	{
		ListView::OnNotifyMessage(m);
	}
}
