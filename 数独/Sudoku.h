#pragma once

namespace Algorithm
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
	
	enum class Status // enum class ��ʽ 
	{
		Empty, // ��ʾ��δ����������Դ
		Bad,   // ��ʾ�����ص������д����޷��ṩ����
		Loaded,// �ռ��ز���ʼ����������
		Ok,    // ��ʾһ������
		Wrong, // ��ʾ��ǰ״̬�д�������
		Error, // �����������
		Win    // ��ʾȫ����������ȷ
	};
	
	class Sudoku
	{
		struct 
		{
			short x;
			short y;
			bool is[10];
		}n_map[10]; // ��n�����С��
		bool row[10][10]; // row[i][k] -- ��i���Ƿ�kռ��
		bool col[10][10]; // col[j][k] -- ��j���Ƿ�kռ��
		bool group[10][10]; // group[g][k] -- ��g�鱻kռ��
	protected:
		SD data[10][10];
		Status _status; // enum class ��ʽ
	public:
		Sudoku()
		{
			_status = Status::Empty;
		}
		Board get() const // ��ȡ����
		{
			return data;
		}
		Status status() const // ��ȡ״̬
		{
			return _status;
		}
		Status set(Res res, Res group=0); // groupΪ0ʱ��ʾĬ�ϱ�׼����
		Status set(Board res);
		Status play(int x, int y, int k);
		void reset();
		int solve(bool isreset=false);
	protected:
		void clear(); // �����ǰ�������ݣ�׼������������
		bool can(int x, int y, int k) // �ж�x��y���ܷ���k
		{
			if(data[x][y].num)
				return false;
			if(row[x][k] || col[y][k] || group[data[x][y].group][k])
				return false;
			return true;
		}
		Status scan(); // ɨ�貢����ÿ�����ӿ���������n�����С��
	};
}