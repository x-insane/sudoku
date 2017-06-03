#pragma once

#define min(a ,b) ((a)<(b)?(a):(b))

// Ԥ�������нṹ����ͽӿ�
ref class Form1;
ref class Admin;
// ref class AddSudoku;
ref class Modify;
ref class SDoc;
ref class MyListView;
class Sudoku;
class XSudoku;
class PSudoku;

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

typedef struct DrawSudokuStruct
{
	float left, top;
	float a;
	float penw = 3;

	enum // ��������
	{
		DS_Main,
		DS_Modify,
		DS_Admin
	}type;

	float sfontw = 8; // Modify����ר��
	bool is_draw_group = true; // Modify����ר��
	bool is_show_tip = false; // Main����ר��
}DSS;

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

// ��������
enum
{
	SD_Standard,
	SD_X,
	SD_Percent
};

// Ԥ�������ͱ���
typedef const SD(*Board)[10];
typedef const int(*Res)[10];

public interface class IModify // �޸�������������������
{
	void modify_ok(System::String^ filename);
	void modify_cancel();
	// SDoc^ sdoc();
};

// Ԥ��������ͷ�ļ�
#include "Form1.h"
// #include "AddSudoku.h"
#include "Admin.h"
#include "Modify.h"

#include "Sudoku.h"
#include "XSudoku.h"
#include "PSudoku.h"
#include "SDoc.h"
#include "MyListView.h"
