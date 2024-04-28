#include"employee.h"
#include<string>
#include<iostream>

Employee::Employee(int id, string name, int Did) ///this 是用来区分成员变量和函数的变量的如果是(int m_Id, string >m_Name, int>m_DeptId) 
{
	this->m_Id = id; 
	this->m_Name = name;
	this->m_DeptId = Did; 
 
}


 void Employee::showinfo()
{
	 cout << "职工编号 " << this->m_Id
		 << "\t职工姓名 " << this->m_Name
		 << "\t岗位" << this->getDeptName()
		 << "\t岗位职责:完成经理交给的任务" << endl;
}

//获取岗位名称
 string Employee::getDeptName()
{
	 return string("员工");

}