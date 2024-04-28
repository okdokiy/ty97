#pragma once   //防止头文件重复包含
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"

//依旧是在头文件中写上类不需要写具体实现  ，在源文件中不写类 直接写加上前缀的函数即可
// 
// 
//说白了 实际上就是以前在一个文件中写的多态现在在分为了三个文件 一个是头文件中的只构造函数 
//一个是在源文件中只实现函数 然后在管理系统直接就用上了

class Employee : public Worker
{
public:
	Employee(int id,string name,int Did);    //这里就是利用了employee和worker之间的多态 
	//父类中定制了两个函数 由于是在头文件中 所以直需要声明就够了

	virtual void showinfo();


	//获取岗位名称
	virtual string getDeptName(); 


};