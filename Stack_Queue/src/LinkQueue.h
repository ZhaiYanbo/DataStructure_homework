/*
*文件名称：				LinkQueue.h
*项目名称：			    链队列的实现
*创建者：				翟衍博
*创建时间：				2022.4.19
*最后修改时间：			2022.4.20
*功能：				    实现链队列的基本操作
*文件中的类与结构体：	LinkQueue类
*与其他文件的依赖关系：	测试在test3.cpp中，具体使用在parking.cpp文件中
*/

#pragma once
#include<iostream>
using namespace std;

//节点类
template<typename T>
class ListNode{
public:
    T data;
    ListNode<T>* next;
};

//链队列类
template<typename T>
class LinkQueue
{
private:
    //带尾指针的循环链表来表示
    ListNode<T>* rear;
    /*带尾指针的链队列，队列的头为链表头，队列尾为链表尾
       这样，尾插和头删的复杂度均为O(1)*/
public:
    LinkQueue<T>();     //构造函数
    ~LinkQueue<T>();    //析构函数
    bool isempty();     //判断是否为空
    bool enqueue(const T& x);   //入队
    bool dequeue(T& x);         //出队
};

//构造函数
template<typename T>
LinkQueue<T>::LinkQueue()
{
    rear=new ListNode<T>;
    if(!rear)
    {
        cout<<"空间申请失败！";
        exit(0);
    }
    //rear->data=0;
    rear->next=rear;
}


//析构函数
template<typename T>
LinkQueue<T>::~LinkQueue()
{
    ListNode<T>* temp=rear->next;
    while (temp!=rear)
    {
        rear->next=temp->next;
        temp->next=nullptr;
        delete temp;
        temp=rear->next;
    }
    temp->next=nullptr;
    delete temp;
}

//判断是否为空
template<typename T>
bool LinkQueue<T>::isempty()
{
    return (rear->next==rear);
}

//入队
template<typename T>
bool LinkQueue<T>::enqueue(const T& x)
{
    ListNode<T>* temp=new ListNode<T>;
    if(!temp)   return false;
    //<!忘记数据域赋值，Debug时找出的问题>
    temp->data=x;
    temp->next=rear->next;
    rear->next=temp;
    rear=temp;
    
    return true;
}

//出队
template<typename T>
bool LinkQueue<T>::dequeue(T& x)
{
    //先判空
    if(rear->next==rear)    return false;
    
    ListNode<T>* p=rear->next;
    ListNode<T>* temp=p->next;  //记录被删节点
    //<!**Debug时发现的问题>
    if(temp==rear)  rear=p;     //可能引起尾指针的更新

    x=temp->data;               //记录被删元素
    p->next=p->next->next;      //拆链
    temp->next=nullptr;
    delete temp;                //释放被删节点

    return true;
}