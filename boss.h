#pragma once   //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include<string>
#include<iostream>
#include "worker.h"

//��ͷ�ļ���Դ�ļ���ȥʵ�ֵ�ʱ����Ҫ�ں�����ǰ���������

class Boss : public Worker {
public:
	Boss(int id, string name, int did);

	void showinfo();

	string getDeptName();

};