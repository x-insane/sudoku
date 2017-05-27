#pragma once

ref class MyListView :
	public ListView
{
public:
	MyListView();
protected:
	void OnNotifyMessage(Message m) override;
};

