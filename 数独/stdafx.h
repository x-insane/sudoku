#pragma once

#define min(a ,b) ((a)<(b)?(a):(b))

// 预声明所有结构、类和接口
ref class Form1;
ref class Admin;
// ref class AddSudoku;
ref class Modify;
ref class SDoc;
ref class MyListView;
class Sudoku;
class XSudoku;
class PSudoku;

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

typedef struct DrawSudokuStruct
{
	float left, top;
	float a;
	float penw = 3;

	enum // 窗口类型
	{
		DS_Main,
		DS_Modify,
		DS_Admin
	}type;

	float sfontw = 8; // Modify窗口专用
	bool is_draw_group = true; // Modify窗口专用
	bool is_show_tip = false; // Main窗口专用
}DSS;

enum class Status // enum class 方式 
{
	Empty, // 表示还未加载数独资源
	Bad,   // 表示所加载的数据有错误，无法提供功能
	Loaded,// 刚加载并初始化数独数据，还没有进行任何填数操作
	Ok,    // 表示一切正常
	Wrong, // 表示当前状态有错误填数
	Error, // 传入参数错误
	Win    // 表示全部填满且正确
};

// 数独种类
enum
{
	SD_Standard,
	SD_X,
	SD_Percent
};

// 预声明类型别名
typedef const SD(*Board)[10];
typedef const int(*Res)[10];

public interface class IModify // 修改数独后请求重新载入
{
	void modify_ok(System::String^ filename);
	void modify_cancel();
	// SDoc^ sdoc();
};

// 预加载所有头文件
#include "Form1.h"
// #include "AddSudoku.h"
#include "Admin.h"
#include "Modify.h"

#include "Sudoku.h"
#include "XSudoku.h"
#include "PSudoku.h"
#include "SDoc.h"
#include "MyListView.h"
