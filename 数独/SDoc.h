#pragma once

namespace Document
{
	struct SD // �������С��
	{
		short num;
		short group;
		// 1-9����ʾ��������
		short who;
		// 0 -- ����ԭ�����֣�Ĭ��
		// 1 -- �����������
		// 2 -- ������ʱ��������
		// 3 -- ��Ҵ�������
		short range; // ��ʾ�������ĸ���
		bool is[10]; // ��ʾ�ø��ܷ���1-9����
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
