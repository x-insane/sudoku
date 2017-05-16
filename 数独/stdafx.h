#pragma once

#define min(a ,b) ((a)<(b)?(a):(b))

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

enum class Status // enum class ��ʽ 
{
	Empty, // ��ʾ��δ����������Դ
	Bad,   // ��ʾ�����ص������д����޷��ṩ����
	Loaded,// �ռ��ز���ʼ���������ݣ���û�н����κ���������
	Ok,    // ��ʾһ������
	Wrong, // ��ʾ��ǰ״̬�д�������
	Error, // �����������
	Win    // ��ʾȫ����������ȷ
};

typedef const SD(*Board)[10];
typedef const int(*Res)[10];

ref class Form1;
ref class Admin;
ref class AddSudoku;
class Sudoku;
class SDoc;
struct SD;

#include "Form1.h"
#include "AddSudoku.h"
#include "Admin.h"

#include "SDoc.h"
#include "Sudoku.h"
