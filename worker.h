#pragma once   //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include<string>




class Worker {
public:
	// ��ʾ������Ϣ
	virtual void showinfo() = 0; 
	//��ȡ��λ����
	virtual string getDeptName() = 0; 

	//ְ�����
	int m_Id; 
	//ְ������
	string m_Name; 
	//���ű��
	int m_DeptId; 
};