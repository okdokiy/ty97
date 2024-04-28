#pragma once   //防止头文件重复包含
#include<iostream>
using namespace std;
#include<string>
#include<iostream>
#include "worker.h"

//当头文件在源文件中去实现的时候需要在函数的前面加上类名

class Boss : public Worker {
public:
	Boss(int id, string name, int did);

	void showinfo();

	string getDeptName();

};