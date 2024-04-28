#include "workmanager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<string>
#include<iostream>
#include<fstream>



//在与头文件相对应的头文件处写上函数的具体实现
//构造函数
workmanager::workmanager()
{
    //下面都是初始化 操作 也就是分文件中有人和文件中无人的情况进行操作;


    //1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->isEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    //2 文件存在 并且里面没有记录
    char ch;
    ifs >> ch;       //读取ch
    if (ifs.eof())
    {
        cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        this->isEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }


    //3.文件存在并且有记录
    int num = this->get_EmpNum();
    cout << "职工人数为" << num << endl;

    this->m_EmpNum = num;  //初始化人数
    this->m_EmpArray = new Worker * [this->m_EmpNum]; //初始化空间

    //把文件中总职工开辟一个空间
    //然后在下面一步 把这些人储存到一个数组中 方便后续维护和操作
    //将文件中的数据储存到数组中

    this->init_Emp();
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        cout << "职工编号:  " << this->m_EmpArray[i]->m_Id
            << " 姓名:  " << this->m_EmpArray[i]->m_Name
            << " 部门编号:   " << this->m_EmpArray[i]->m_DeptId << endl;
    }
}
//显示目录

void workmanager::Show_Menu()
{
    cout << "********************************************" << endl; 
    cout << "************ 欢迎使用职工管理系统************" << endl;	
    cout << "************ 0.退出管理系统 ************"<<endl;
    cout << "************ 1.增加职工信息 ************"<<endl;
    cout << "************ 2.显示职工信息 ************" << endl;
    cout << "************ 3.删除离职员工 ************" << endl;
    cout << "************ 4.修改职工信息 ************" << endl;
    cout << "************ 5.查找职工信息 ************" << endl;
    cout << "************ 6.按照编号排序 ************" << endl;
    cout << "************ 7.清空所有文档 ************" << endl;
    cout << "********************************************" << endl;
}

//退出系统
void workmanager::ExieSystem()
{
    cout << "欢迎下次使用" << endl; 
    system("pause");
    exit(0);  //记住 这个代码就是退出程序
}



//添加员工
void workmanager::Add_Emp()
{
    cout << "请输入添加的职工的数量" << endl;

    int addNum = 0;  

    cin >> addNum; 

    if (addNum > 0)
    {
        //添加

        //计算添加的新的人数
        int newSize = this->m_EmpNum + addNum; 
        
        //因为你输入的有各种各样的职位 但是一个数组中只能储存一个类型的数据
        //所以你要创造一个一个数组存储不同的员工数组new Worker*[员工数量]这样的话就把新加入的员工/老板/经理分配到不同的数组中了 
        //使用Worker ** newspace = new worker*[newSize]  在堆区创造newspace来储存这些人的数组指针 newspace储存1了很多数组的指针
        //work*[newsize]是一个数组储存着各个类型的人 这时候用一个二级指针来储存各种各样的worker 每个worker都是一个数组
        Worker ** newSpace = new Worker*[newSize];  

        if (this->m_EmpArray != NULL)
        {
            //如果原来的数据不为空 就把原来的数据全部加入newspace中
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

            //输入新数据
        for (int i = 0; i < addNum ; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "请输入第" << i + 1 << "个职工编号" << endl;
            cin >> id;

            cout << "请输入第" << i + 1 << "个职工姓名" << endl;
            cin >> name;

            cout << "请输入该职工的岗位" << endl;	
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl; 
            cin >> dSelect;

            Worker * worker = NULL; //上下结合就是Worker * worker = new Employee(id, name, 1); 即多态之后就是worker使用Employee内的所有函数和内容
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }

                //将创造职工 保存到数组中
                //EmpNum是原来有多少个人 newSize是新的总人数 addNum是新加入的人数
                newSpace[this->m_EmpNum + i] = worker;
        }


        //释放堆区空间
        delete[] this->m_EmpArray;

        //下面是三项workermanager中的参数更新
        //更改新空间的指向
        this->m_EmpArray = newSpace; //这里就知道了 让原本的二级指针=newSpace 储存新的数组指针

        //更新新的职工人数
        this->m_EmpNum = newSize;

        this->isEmpty = false;

        //保存数据
        this->save();

        //提示成功添加
        cout << "成功添加了" << addNum << "名新职工" << endl;
        //释放堆区空间 -> 指向新的堆区空间->更新人数 ->保存数据->提示成功
    }
    else
    {
        cout << "您输入的数字有误" << endl; 
    }

    system("pause");
    system("cls");
     
}
//这个函数还没完 只写到这儿之后没有生成文件去储存你写的人 这时候就需要下一步了;

void workmanager::save()
{
    //写文件步骤 创建文件流 打开文件 写文件 关闭文件 
    ofstream ofs; 
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
        << this->m_EmpArray[i]->m_Name << " "
        << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}








//下面两个函数 是初始化数据也就是读数据的过程
int workmanager::get_EmpNum()  //获取文件中的人数
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);


    int id; 
    string name;
    int did; 

    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        num++; 
    }
    ifs.close();
    return num;
}
void workmanager::init_Emp() //将文件中的人储存到数组中 这个是已经写入了人之后的操作
{
    ifstream  ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int did;

    int index = 0;  
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        Worker* worker = NULL;
        if(did == 1 ) //普通职工
        {
            worker = new Employee(id, name, did);
        }
        else if (did == 2)
        {
            worker = new Manager(id, name, did);
        }
        else
        {
            worker = new Boss(id, name, did);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }

    ifs.close();

}










void workmanager::Show_Emp()
{
    if (this->isEmpty)
    {
        cout << "文件为空或者不存在" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showinfo(); //** m_EmpArrayy[i]是个体对象
        }
    }
    system("pause");
    system("cls");
}








int workmanager::IsExist(int id)  //和删除职工捆绑 判断要删除的职工是否存在
{
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            return i;
            break; 
        }
    }
    return -1;
}
void workmanager::Del_Emp()
{
    if (this->isEmpty)
    {
        cout << "文件不存在" << endl;
    }
    else
    {
        cout << "请输入要删除的职工编号" << endl;
        int id = 0;
        cin >> id; 
        
        int index = this->IsExist(id);

        if(index == -1)
        {
        
            cout << "删除失败，您要删除的人不存在" << endl; 
        }
        else
        {
            for (int i = index; i < this->m_EmpNum - 1; i++) //所有数据-- 删除第index项目
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }

            this->m_EmpNum--;  //更新人数
            this->save();
            cout << "删除成功" << endl;
        }

    }
    system("pause");
    system("cls");
}












void workmanager::Mod_Emp()
{
    if (this->isEmpty)
    {
        cout << "文件不存在或没有记录!" << endl;
    }
    else
    {
        cout << "请输入你要修改的人员编号" << endl;
        int id = 0;
        cin >> id; 

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = ""; 
            int dSelect = 0; 

            cout << "查到:" << id << "号员工，请输入新的职工号" << endl;
            cin >> newId;

            cout << "请输入新姓名 " << endl;
            cin >> newName; 

            cout << "请输入新的岗位" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect; 

            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1:worker = new Employee(newId, newName, dSelect);
                break; 
            case 2:worker = new Manager(newId, newName, dSelect);
                break;
            case 3:worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
           
            }
            this->m_EmpArray[ret] = worker;
            cout << "修改成功" << endl; 
            this->save();

        }
        else
        {
            cout << "未查询到您要修改的人员" << endl;
        }
    }
    system("pause");
    system("cls");

}






void  workmanager::Find_Emp() //两种查找方式 一种是按照职工编号 一种是按照职工姓名
{
    if (this->isEmpty)
    {
        cout << "文件不存在或记录为空 " << endl;
     }
    else
    {
        cout << "请输入查找的方式" << endl;
        cout << "1.按照职工的编号查找 " << endl;
        cout << "2.按照职工的姓名查找" << endl;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            //按照编号查找
            int id = 0; 
            cin >> id;
            int ret = this->IsExist(id);
            {
                if (ret != -1)
                {
                    cout << "查找成功,该职工的信息如下" << endl;

                    this->m_EmpArray[ret]->showinfo(); 
                    //当想一次性打印员工的所有信息的时候就用showinfo; 
                }
                else
                {
                    cout << "您查找的人员不存在!" << endl;
                }
            }
        }


        else if (select == 2)
        {

            bool flag = false;
            //按照姓名查找
            cout << "请输入员工的姓名" << endl;
            string name;
            cin >> name;

            for (int i = 0; i < m_EmpNum; i++)
            {
                if (this->m_EmpArray[i]->m_Name == name)
                {
                    cout << "查找成功,职工编号为" 
                        << this->m_EmpArray[i]->m_Id
                        <<"其职工信息为"<< endl;

                    this->m_EmpArray[i]->showinfo();

                    flag = true; 
                }
            }
            if (flag == false)
            {
                cout << "查找失败，查无此人" << endl;
            }
        }
        else
        {
            cout << "您输入的选项有误" << endl;
        }
    }

    system("pause");
    system("cls");
}








void workmanager::Sort_Emp()
{
    if (this->isEmpty)
    {
        cout << "文件不存在或内容为空" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序方式" << endl; 
        cout << "1.按照升序排序" << endl;
        cout << "2.按照降序排序" << endl;

        int select = 0;
        cin >> select; 
    
        for (int i = 0; i < m_EmpNum; i++)
        {
            int minOrmax = i;  //当第i个位置确定之后 即j即之后的数据遍历完了 这时候就需要重置minOrmax
            for (int j = i + 1; j < this->m_EmpNum; j++)
            {
                if (select == 1) //升序
                {
                    if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id)
                    {
                        minOrmax = j; //每次在找到比第i个数据更大的值的时候,就把minOrmax替换为j 记录下第i个位置按照升序应该是谁           
                    }
                }
                else if (select == 2) //降序
                {
                    if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id) //当前这个最大值没有后面j的这个值大 所以要更换最大值为j
                    {
                        minOrmax = j;
                    }
                }
                else
                {
                    cout << "您输入的选项有误" << endl;
                }
            }
            //上面只是说用minOrmax找到了本身各个位置按照升序或者降序应该存在的第j个数据 

            if (i != minOrmax) //如果后续找到的minOrmax=j   
                //也就是第j个数据 不是本身的原来的第i个数据的话 
            {
                Worker* temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
                this->m_EmpArray[minOrmax] = temp;
            }
            cout << "排序成功!排序后的结果为 " << endl;
            this->save();
            this->Show_Emp(); //因为这个函数包含了清屏 所以不需要再写
        }
    }
}








void workmanager::Clean_File()
{
    cout << "确认清空?" << endl;
    cout << "1.确认" << endl; 
    cout << "2.返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc); //打开模式trunc 如果存在就删除文件并且重新创建
        ofs.close();

        //上述只是把文件里面的内容重置了 但是堆区的空间仍然需要清理 


        if (this->m_EmpArray != NULL)
        {
            //清除堆区  EmpArray  中的每一个数据
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL) {
                    delete this->m_EmpArray[i];
                }
            }
            //清除完了堆区的数据 
            //更新三个数据
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->isEmpty = true;
        }
        cout << "清空成功 " << endl;
    }
    system("pause");
    system("cls");
}



//析构函数
workmanager::~workmanager()
{
    if (this->m_EmpArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArray[i] != NULL) {
                delete this->m_EmpArray[i];
            }
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}