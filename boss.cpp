#include"boss.h"
#include<string>
#include<iostream>
	Boss::Boss(int id, string name, int did)
	{
		this->m_Id = id;
		this->m_Name = name;
		this->m_DeptId = did;
	}

	void Boss::showinfo()
	{
		cout << "ְ�����: " << this->m_Id
			<< "\tְ������:  " << this->m_Name
			<< "\t��λ: " << this->getDeptName()
			<< "\t��λְ��:������˾�����е�����" << endl;
	}

	string Boss::getDeptName()
	{
		return string("�ϰ�");
	}

