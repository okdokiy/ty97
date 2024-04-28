#pragma once   //防止头文件重复包含
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"


class Manager : public Worker
{
public:
	Manager(int id, string name, int did);
	

	void showinfo();
	
	string getDeptName();


};