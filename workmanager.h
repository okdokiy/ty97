#pragma once   //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std; 
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>				//Ϊд�ļ�׼����
#define FILENAME "empFile.txt"			//��˼����FILENAME Ϊ������ļ� û�н��ᴴ���ļ�


class workmanager
{
public:
	//���캯��
	workmanager();

	///չʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ
	void ExieSystem();


	//���ְ������
	void Add_Emp(); //�����ְ���� һ����Ҫд���ļ� ��Ա���Ĵ��� һ����Ҫ���ļ�

	//д�ļ�
	void save(); 







	//�������д��� ˵�ǳ�ʼ������ Ҳ����Ϊ����ν�Ķ����� 
	//���ļ� ��������� //���ļ���ʱ����Ҫ��������� 1.�ļ������ڣ�!ifs.isopen) ����һ������bool isempty 
	// 2.�ļ����ڵ���û������(ifs.eof)
	// 3.�ļ����ڲ��������� int num = this->get_Emp Ȼ���� this->Empnum  = num;
	int get_EmpNum(); 

	//��ʼ��Ա��  
	//��Ȼ��һ�� ���ǰ��˶����浽�������� Empnum�Ѿ���¼��������
	//���Ǽ�����һ��void init_Emp ����Щ�˷��������� ���԰������ǲٿ���Щ��
	void init_Emp();








	void Show_Emp();


	int IsExist(int id);
	void Del_Emp();

	void Mod_Emp();

	void Find_Emp();

	void Sort_Emp();

	void Clean_File();


	~workmanager(); 




	//�ж��Ƿ�Ϊ��
	bool isEmpty;
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker ** m_EmpArray; //��ͬ��ְ�����ڲ�ͬ��������
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