#include<string>
#include<iostream>
using namespace std; 
#include"workmanager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
//普工 经理 老板 
//退出管理系统 增加职工信息 显示职工信息 删除离职职工 修改职工信息 查找职工信息 按照编号排序 清空所有文档
//案例过于复杂 需要反复观看

int main()
{
	//实验对象
	/*Worker* employee = new Employee(1, "柳二", 1);
	employee->showinfo();
	employee->getDeptName();
	delete employee; 

	Worker * manager = new Manager(2, "李四", 4);
	manager->showinfo();
	manager->getDeptName();
	delete manager;

	Worker* boss = new Boss(3, "王五", 3);
	boss->showinfo();
	boss->getDeptName();
	delete boss;*/



	workmanager wm;
	int choice = 0;

	while (true)
	{
		wm.Show_Menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: wm.ExieSystem();
			break;
		case 1: wm.Add_Emp();
			break;
		case 2:wm.Show_Emp(); //先判断有没有
			break;
		case 3:wm.Del_Emp();  //先判断有没有
		break;
		case 4:wm.Mod_Emp();  // 先判断有没有
			break;
		case 5:wm.Find_Emp(); //先判断有没有
			break;
		case 6:wm.Sort_Emp();//先判断有没有  并且在判断中加上清空 因为下面的有一个showmenu中涵盖的就有清空操作
			break;
		case 7:wm.Clean_File();
			break;
		default:
			break;
			system("cls");
		}
	}
	
	
	system("pause");
	return 0;
}