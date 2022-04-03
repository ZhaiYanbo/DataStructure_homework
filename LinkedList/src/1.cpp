/*
*文件名称：				1.cpp
*项目名称：				线性表
*创建者：				翟衍博
*创建时间：				2020.3.28
*最后修改时间：			2020.4.2
*功能：				   对单链表的一些基本操作进行验证
*文件中的函数：		    showmenu(菜单函数)
                        creatL、destoryL、lengthL、emptyL、getL、showL、insertL、deleteL、findL(验证链表操作的函数，详见函数定义说明)
*与其他文件的依赖关系：	引入了了"LinkedList.h"头文件
*/
#include"LinkedList.h"

//显示菜单
void showmenu(int& number)
{
    // system("cls");
    // cout<<"menu：\n"
    //     <<"1.creat a linkedlist using array\n"
    //     <<"2.destory this linkedlist\n"
    //     <<"3.get the length of linkedlist\n"
    //     <<"4.judge whether the linkedlist is empty or not\n"
    //     <<"5.get element by index(from 0 start)\n"
    //     <<"6.show linkedlist\n"
    //     <<"7.insert a element in linkedlist\n"
    //     <<"8.delete a element from linkedlist\n"
    //     <<"9.search a certain element from linkedlist and get the index\n"
    //     <<"0.exit\n"
    //     <<"------------------------------------------------------------------\n"
    //     <<"please input a integer form 0 to 9:";
    cout<<"这是菜单"<<endl;
    
    while(!(number>=0&&number<=9))
        cin>>number;
}

//创建链表
void creatL(LinkedList<int>& l)
{
    // system("cls");
    int a[100],length;
    cout<<"please input the size of array:";
    cin>>length;
    cout<<"please input numbers:";
    for(int i=0;i<length;i++)
    {
        cin>>a[i];
    }
    l.creatLinkedList(a,length);
    cout<<"create sucess"<<endl;
}

//销毁链表
void destoryL(LinkedList<int>& l)
{
    // system("cls");
    l.destoryLinkedList();
    cout<<"destory success"<<endl;
}

//获取链表长度
void lengthL(LinkedList<int>& l)
{
    // system("cls");
    cout<<"length："<<l.getLength()<<endl;
}

//判断链表是否为空
void emptyL(LinkedList<int>& l)
{
    // system("cls");
    if(l.isEmpty()) 
        cout<<"Null"<<endl;
    else
        cout<<"Not null"<<endl;
}

//获得链表元素
void getL(LinkedList<int>& l)
{
    // system("cls");
    cout<<"please input index:";
    int loc;
    cin>>loc;
    cout<<"data:"<<l.getVal(loc);
}

//展示链表
void showL(LinkedList<int>& l)
{
    // system("cls");
    cout<<"all data：";
    l.display();
}

//插入元素
void insertL(LinkedList<int>& l)
{
    // system("cls");
    int loc,data;
    cout<<"please input the data you want to insert:";
    cin>>data;
    cout<<"\nplease input the index you want to insert:";
    cin>>loc;
    l.insert(data,loc);
    cout<<"insert success"<<endl;
    l.display();
}

//删除元素
void deleteL(LinkedList<int>& l)
{
    // system("cls");
    cout<<"please input the index you want to delete:";
    int loc;
    cin>>loc;
    l.del(loc);
    cout<<"delete success"<<endl;
    l.display();
}

//查找元素
void findL(LinkedList<int>& l)
{
    // system("cls");
    cout<<"please input data you want to find:";
    int target;
    cin>>target;
    if(l.find(target)==-1)
    {
        cout<<"无此元素"<<endl;
        return;
    } 
    cout<<"the index of data:"<<  l.find(target)<<endl;
}

int main()
{
    
    LinkedList<int> l;
    while(1)
    {
        int number=-1;
        showmenu(number);
        switch (number)
        {
        case 1:
            creatL(l);
            break;
        case 2:
            destoryL(l);
            break;
        case 3:
            lengthL(l);
            break;
        case 4:
            emptyL(l);
            break;
        case 5:
            getL(l);
            break;
        case 6:
            showL(l);
            break;
        case 7:
            insertL(l);
            break;
        case 8:
            deleteL(l);
            break;
        case 9:
            findL(l);
            break;
        case 0:
            cout<<"感谢您的使用……"<<endl;
            exit(0);
        
        default:
            break;
        }
        //system("pause");
    }

    return 0;
}