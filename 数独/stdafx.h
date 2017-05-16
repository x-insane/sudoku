#pragma once

#define min(a ,b) ((a)<(b)?(a):(b))

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
