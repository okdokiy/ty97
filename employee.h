#pragma once   //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"

//��������ͷ�ļ���д���಻��Ҫд����ʵ��  ����Դ�ļ��в�д�� ֱ��д����ǰ׺�ĺ�������
// 
// 
//˵���� ʵ���Ͼ�����ǰ��һ���ļ���д�Ķ�̬�����ڷ�Ϊ�������ļ� һ����ͷ�ļ��е�ֻ���캯�� 
//һ������Դ�ļ���ֻʵ�ֺ��� Ȼ���ڹ���ϵͳֱ�Ӿ�������

class Employee : public Worker
{
public:
	Employee(int id,string name,int Did);    //�������������employee��worker֮��Ķ�̬ 
	//�����ж������������� ��������ͷ�ļ��� ����ֱ��Ҫ�����͹���

	virtual void showinfo();


	//��ȡ��λ����
	virtual string getDeptName(); 


};