#include"employee.h"
#include<string>
#include<iostream>

Employee::Employee(int id, string name, int Did) ///this ���������ֳ�Ա�����ͺ����ı����������(int m_Id, string >m_Name, int>m_DeptId) 
{
	this->m_Id = id; 
	this->m_Name = name;
	this->m_DeptId = Did; 
 
}


 void Employee::showinfo()
{
	 cout << "ְ����� " << this->m_Id
		 << "\tְ������ " << this->m_Name
		 << "\t��λ" << this->getDeptName()
		 << "\t��λְ��:��ɾ�����������" << endl;
}

//��ȡ��λ����
 string Employee::getDeptName()
{
	 return string("Ա��");

}