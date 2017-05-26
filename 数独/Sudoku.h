#pragma once
	
class Sudoku
{
	struct NMap
	{
		short x;
		short y;
		bool is[10];
	}n_map[10]; // ��n�����С��
	short map[10][10]; // ÿ��group�����г�Ա
	bool row[10][10]; // row[i][k] -- ��i���Ƿ�kռ��
	bool col[10][10]; // col[j][k] -- ��j���Ƿ�kռ��
	bool group[10][10]; // group[g][k] -- ��g�鱻kռ��
protected:
	SD data[10][10];
	Status _status; // enum class ��ʽ
public:
	Sudoku();
	Sudoku(const Sudoku& sd);
	virtual bool check();
	Board get() const // ��ȡ����
	{
		return data;
	}
	Status status() const // ��ȡ״̬
	{
		return _status;
	}
	const char* status_string() const
	{
		switch(_status)
		{
		case Status::Bad:
			return "����";
		case Status::Empty:
			return "δ����";
		case Status::Error:
			return "����";
		case Status::Loaded:
			return "����";
		case Status::Ok:
			return "����";
		case Status::Win:
			return "���";
		case Status::Wrong:
			return "�д���";
		}
		return "";
	}
	Status set(Res res, Res group=0); // groupΪ0ʱ��ʾĬ�ϱ�׼����
	Status set(Board res);
	Status play(int x, int y, int k, bool is_solve=false);
	Status reset();
	Status reset(int x, int y, bool is_solve=false);
	Status solve(bool is_reset=false);
	virtual void Draw(Graphics^ dc, DSS dss);
	virtual bool Serialize(BinaryWriter^ bw);
	virtual bool Serialize(BinaryReader^ br);
protected:
	void setBoard(int x, int y, int k);
	void setGroup(int x, int y, int g);
	friend ref class Modify; // ����Modify���ڶ��������ݽ����޸�
protected:
	void init();
	bool can(int x, int y, int k) // �ж�x��y���ܷ���k
	{
		if(data[x][y].num)
			return false;
		if(row[x][k] || col[y][k] || group[data[x][y].group][k])
			return false;
		return true;
	}
	Status scan(); // ɨ�貢����ÿ�����ӿ���������n�����С��
	virtual bool Callback()
	{
		return true;
	}
};