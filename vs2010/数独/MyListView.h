#pragma once

ref class MyListView :
	public ListView
{
public:
	MyListView();
protected:
	virtual void OnNotifyMessage(Message m) override;
};

