#include<string>
#include<iostream>
using namespace std; 
#include"workmanager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
//�չ� ���� �ϰ� 
//�˳�����ϵͳ ����ְ����Ϣ ��ʾְ����Ϣ ɾ����ְְ�� �޸�ְ����Ϣ ����ְ����Ϣ ���ձ������ ��������ĵ�
//�������ڸ��� ��Ҫ�����ۿ�

int main()
{
	//ʵ�����
	/*Worker* employee = new Employee(1, "����", 1);
	employee->showinfo();
	employee->getDeptName();
	delete employee; 

	Worker * manager = new Manager(2, "����", 4);
	manager->showinfo();
	manager->getDeptName();
	delete manager;

	Worker* boss = new Boss(3, "����", 3);
	boss->showinfo();
	boss->getDeptName();
	delete boss;*/



	workmanager wm;
	int choice = 0;

	while (true)
	{
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: wm.ExieSystem();
			break;
		case 1: wm.Add_Emp();
			break;
		case 2:wm.Show_Emp(); //���ж���û��
			break;
		case 3:wm.Del_Emp();  //���ж���û��
		break;
		case 4:wm.Mod_Emp();  // ���ж���û��
			break;
		case 5:wm.Find_Emp(); //���ж���û��
			break;
		case 6:wm.Sort_Emp();//���ж���û��  �������ж��м������ ��Ϊ�������һ��showmenu�к��ǵľ�����ղ���
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