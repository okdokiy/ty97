#include "workmanager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<string>
#include<iostream>
#include<fstream>



//����ͷ�ļ����Ӧ��ͷ�ļ���д�Ϻ����ľ���ʵ��
//���캯��
workmanager::workmanager()
{
    //���涼�ǳ�ʼ�� ���� Ҳ���Ƿ��ļ������˺��ļ������˵�������в���;


    //1.�ļ�������
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        this->m_EmpNum = 0;
        this->isEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    //2 �ļ����� ��������û�м�¼
    char ch;
    ifs >> ch;       //��ȡch
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ��" << endl;
        this->m_EmpNum = 0;
        this->isEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }


    //3.�ļ����ڲ����м�¼
    int num = this->get_EmpNum();
    cout << "ְ������Ϊ" << num << endl;

    this->m_EmpNum = num;  //��ʼ������
    this->m_EmpArray = new Worker * [this->m_EmpNum]; //��ʼ���ռ�

    //���ļ�����ְ������һ���ռ�
    //Ȼ��������һ�� ����Щ�˴��浽һ�������� �������ά���Ͳ���
    //���ļ��е����ݴ��浽������

    this->init_Emp();
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        cout << "ְ�����:  " << this->m_EmpArray[i]->m_Id
            << " ����:  " << this->m_EmpArray[i]->m_Name
            << " ���ű��:   " << this->m_EmpArray[i]->m_DeptId << endl;
    }
}
//��ʾĿ¼

void workmanager::Show_Menu()
{
    cout << "********************************************" << endl; 
    cout << "************ ��ӭʹ��ְ������ϵͳ************" << endl;	
    cout << "************ 0.�˳�����ϵͳ ************"<<endl;
    cout << "************ 1.����ְ����Ϣ ************"<<endl;
    cout << "************ 2.��ʾְ����Ϣ ************" << endl;
    cout << "************ 3.ɾ����ְԱ�� ************" << endl;
    cout << "************ 4.�޸�ְ����Ϣ ************" << endl;
    cout << "************ 5.����ְ����Ϣ ************" << endl;
    cout << "************ 6.���ձ������ ************" << endl;
    cout << "************ 7.��������ĵ� ************" << endl;
    cout << "********************************************" << endl;
}

//�˳�ϵͳ
void workmanager::ExieSystem()
{
    cout << "��ӭ�´�ʹ��" << endl; 
    system("pause");
    exit(0);  //��ס �����������˳�����
}



//���Ա��
void workmanager::Add_Emp()
{
    cout << "��������ӵ�ְ��������" << endl;

    int addNum = 0;  

    cin >> addNum; 

    if (addNum > 0)
    {
        //���

        //������ӵ��µ�����
        int newSize = this->m_EmpNum + addNum; 
        
        //��Ϊ��������и��ָ�����ְλ ����һ��������ֻ�ܴ���һ�����͵�����
        //������Ҫ����һ��һ������洢��ͬ��Ա������new Worker*[Ա������]�����Ļ��Ͱ��¼����Ա��/�ϰ�/������䵽��ͬ���������� 
        //ʹ��Worker ** newspace = new worker*[newSize]  �ڶ�������newspace��������Щ�˵�����ָ�� newspace����1�˺ܶ������ָ��
        //work*[newsize]��һ�����鴢���Ÿ������͵��� ��ʱ����һ������ָ����������ָ�����worker ÿ��worker����һ������
        Worker ** newSpace = new Worker*[newSize];  

        if (this->m_EmpArray != NULL)
        {
            //���ԭ�������ݲ�Ϊ�� �Ͱ�ԭ��������ȫ������newspace��
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

            //����������
        for (int i = 0; i < addNum ; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "�������" << i + 1 << "��ְ�����" << endl;
            cin >> id;

            cout << "�������" << i + 1 << "��ְ������" << endl;
            cin >> name;

            cout << "�������ְ���ĸ�λ" << endl;	
            cout << "1.��ְͨ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl; 
            cin >> dSelect;

            Worker * worker = NULL; //���½�Ͼ���Worker * worker = new Employee(id, name, 1); ����̬֮�����workerʹ��Employee�ڵ����к���������
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

                //������ְ�� ���浽������
                //EmpNum��ԭ���ж��ٸ��� newSize���µ������� addNum���¼��������
                newSpace[this->m_EmpNum + i] = worker;
        }


        //�ͷŶ����ռ�
        delete[] this->m_EmpArray;

        //����������workermanager�еĲ�������
        //�����¿ռ��ָ��
        this->m_EmpArray = newSpace; //�����֪���� ��ԭ���Ķ���ָ��=newSpace �����µ�����ָ��

        //�����µ�ְ������
        this->m_EmpNum = newSize;

        this->isEmpty = false;

        //��������
        this->save();

        //��ʾ�ɹ����
        cout << "�ɹ������" << addNum << "����ְ��" << endl;
        //�ͷŶ����ռ� -> ָ���µĶ����ռ�->�������� ->��������->��ʾ�ɹ�
    }
    else
    {
        cout << "���������������" << endl; 
    }

    system("pause");
    system("cls");
     
}
//���������û�� ֻд�����֮��û�������ļ�ȥ������д���� ��ʱ�����Ҫ��һ����;

void workmanager::save()
{
    //д�ļ����� �����ļ��� ���ļ� д�ļ� �ر��ļ� 
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








//������������ �ǳ�ʼ������Ҳ���Ƕ����ݵĹ���
int workmanager::get_EmpNum()  //��ȡ�ļ��е�����
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
void workmanager::init_Emp() //���ļ��е��˴��浽������ ������Ѿ�д������֮��Ĳ���
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
        if(did == 1 ) //��ְͨ��
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
        cout << "�ļ�Ϊ�ջ��߲�����" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showinfo(); //** m_EmpArrayy[i]�Ǹ������
        }
    }
    system("pause");
    system("cls");
}








int workmanager::IsExist(int id)  //��ɾ��ְ������ �ж�Ҫɾ����ְ���Ƿ����
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
        cout << "�ļ�������" << endl;
    }
    else
    {
        cout << "������Ҫɾ����ְ�����" << endl;
        int id = 0;
        cin >> id; 
        
        int index = this->IsExist(id);

        if(index == -1)
        {
        
            cout << "ɾ��ʧ�ܣ���Ҫɾ�����˲�����" << endl; 
        }
        else
        {
            for (int i = index; i < this->m_EmpNum - 1; i++) //��������-- ɾ����index��Ŀ
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }

            this->m_EmpNum--;  //��������
            this->save();
            cout << "ɾ���ɹ�" << endl;
        }

    }
    system("pause");
    system("cls");
}












void workmanager::Mod_Emp()
{
    if (this->isEmpty)
    {
        cout << "�ļ������ڻ�û�м�¼!" << endl;
    }
    else
    {
        cout << "��������Ҫ�޸ĵ���Ա���" << endl;
        int id = 0;
        cin >> id; 

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = ""; 
            int dSelect = 0; 

            cout << "�鵽:" << id << "��Ա�����������µ�ְ����" << endl;
            cin >> newId;

            cout << "������������ " << endl;
            cin >> newName; 

            cout << "�������µĸ�λ" << endl;
            cout << "1.��ְͨ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
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
            cout << "�޸ĳɹ�" << endl; 
            this->save();

        }
        else
        {
            cout << "δ��ѯ����Ҫ�޸ĵ���Ա" << endl;
        }
    }
    system("pause");
    system("cls");

}






void  workmanager::Find_Emp() //���ֲ��ҷ�ʽ һ���ǰ���ְ����� һ���ǰ���ְ������
{
    if (this->isEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�� " << endl;
     }
    else
    {
        cout << "��������ҵķ�ʽ" << endl;
        cout << "1.����ְ���ı�Ų��� " << endl;
        cout << "2.����ְ������������" << endl;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            //���ձ�Ų���
            int id = 0; 
            cin >> id;
            int ret = this->IsExist(id);
            {
                if (ret != -1)
                {
                    cout << "���ҳɹ�,��ְ������Ϣ����" << endl;

                    this->m_EmpArray[ret]->showinfo(); 
                    //����һ���Դ�ӡԱ����������Ϣ��ʱ�����showinfo; 
                }
                else
                {
                    cout << "�����ҵ���Ա������!" << endl;
                }
            }
        }


        else if (select == 2)
        {

            bool flag = false;
            //������������
            cout << "������Ա��������" << endl;
            string name;
            cin >> name;

            for (int i = 0; i < m_EmpNum; i++)
            {
                if (this->m_EmpArray[i]->m_Name == name)
                {
                    cout << "���ҳɹ�,ְ�����Ϊ" 
                        << this->m_EmpArray[i]->m_Id
                        <<"��ְ����ϢΪ"<< endl;

                    this->m_EmpArray[i]->showinfo();

                    flag = true; 
                }
            }
            if (flag == false)
            {
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        }
        else
        {
            cout << "�������ѡ������" << endl;
        }
    }

    system("pause");
    system("cls");
}








void workmanager::Sort_Emp()
{
    if (this->isEmpty)
    {
        cout << "�ļ������ڻ�����Ϊ��" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��ѡ������ʽ" << endl; 
        cout << "1.������������" << endl;
        cout << "2.���ս�������" << endl;

        int select = 0;
        cin >> select; 
    
        for (int i = 0; i < m_EmpNum; i++)
        {
            int minOrmax = i;  //����i��λ��ȷ��֮�� ��j��֮������ݱ������� ��ʱ�����Ҫ����minOrmax
            for (int j = i + 1; j < this->m_EmpNum; j++)
            {
                if (select == 1) //����
                {
                    if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id)
                    {
                        minOrmax = j; //ÿ�����ҵ��ȵ�i�����ݸ����ֵ��ʱ��,�Ͱ�minOrmax�滻Ϊj ��¼�µ�i��λ�ð�������Ӧ����˭           
                    }
                }
                else if (select == 2) //����
                {
                    if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id) //��ǰ������ֵû�к���j�����ֵ�� ����Ҫ�������ֵΪj
                    {
                        minOrmax = j;
                    }
                }
                else
                {
                    cout << "�������ѡ������" << endl;
                }
            }
            //����ֻ��˵��minOrmax�ҵ��˱������λ�ð���������߽���Ӧ�ô��ڵĵ�j������ 

            if (i != minOrmax) //��������ҵ���minOrmax=j   
                //Ҳ���ǵ�j������ ���Ǳ����ԭ���ĵ�i�����ݵĻ� 
            {
                Worker* temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
                this->m_EmpArray[minOrmax] = temp;
            }
            cout << "����ɹ�!�����Ľ��Ϊ " << endl;
            this->save();
            this->Show_Emp(); //��Ϊ����������������� ���Բ���Ҫ��д
        }
    }
}








void workmanager::Clean_File()
{
    cout << "ȷ�����?" << endl;
    cout << "1.ȷ��" << endl; 
    cout << "2.����" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc); //��ģʽtrunc ������ھ�ɾ���ļ��������´���
        ofs.close();

        //����ֻ�ǰ��ļ���������������� ���Ƕ����Ŀռ���Ȼ��Ҫ���� 


        if (this->m_EmpArray != NULL)
        {
            //�������  EmpArray  �е�ÿһ������
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] != NULL) {
                    delete this->m_EmpArray[i];
                }
            }
            //������˶��������� 
            //������������
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->isEmpty = true;
        }
        cout << "��ճɹ� " << endl;
    }
    system("pause");
    system("cls");
}



//��������
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