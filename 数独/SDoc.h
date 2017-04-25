#pragma once

namespace Document
{
	struct SD // 设计数独小格
	{
		short num;
		short group;
		// 1-9，表示所属分组
		short who;
		// 0 -- 数独原有数字，默认
		// 1 -- 玩家添入数字
		// 2 -- 解数独时填入数字
		// 3 -- 玩家错填数字
		short range; // 表示能填数的个数
		bool is[10]; // 表示该格能否填1-9的数
	};

	typedef const SD(*Board)[10];
	typedef const int(*Res)[10];

	class SDoc
	{
	protected:
		Res data;
		Res map;
		char name[256];
		char author[256];
		unsigned long long time;
	public:
		static bool save();
		static bool read();
	};
}
