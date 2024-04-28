#pragma once   //防止头文件重复包含
#include<iostream>
using namespace std; 
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>				//为写文件准备的
#define FILENAME "empFile.txt"			//意思就是FILENAME 为后面的文件 没有将会创造文件


class workmanager
{
public:
	//构造函数
	workmanager();

	///展示菜单
	void Show_Menu();
	//退出系统
	void ExieSystem();


	//添加职工人数
	void Add_Emp(); //添加完职工后 一个是要写入文件 保员工的储存 一个是要读文件

	//写文件
	void save(); 







	//下面两行代码 说是初始化数据 也就是为了所谓的读数据 
	//读文件 分三种情况 //读文件的时候又要分三种情况 1.文件不存在（!ifs.isopen) 引入一个变量bool isempty 
	// 2.文件存在但是没有数据(ifs.eof)
	// 3.文件存在并且有数据 int num = this->get_Emp 然后让 this->Empnum  = num;
	int get_EmpNum(); 

	//初始化员工  
	//虽然上一步 我们把人都储存到了数据中 Empnum已经记录了人数了
	//但是加上这一步void init_Emp 把这些人放入数组中 可以帮助我们操控这些人
	void init_Emp();








	void Show_Emp();


	int IsExist(int id);
	void Del_Emp();

	void Mod_Emp();

	void Find_Emp();

	void Sort_Emp();

	void Clean_File();


	~workmanager(); 




	//判断是否为空
	bool isEmpty;
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker ** m_EmpArray; //不同的职工存于不同的数组中
};


//workmanager();
//void Show_Menu();
//void ExieSystem();
//void Add_Emp(); 
// 
//void save(); 

//	int get_EmpNum(); 
//	void init_Emp();
//	~workmanager(); 
//
//	bool isEmpty;
//	int m_EmpNum;
//  Worker ** m_EmpArray;