/*
*文件名称：				CirQueue.h
*项目名称：			    循环队列
*创建者：				翟衍博
*创建时间：				2022.4.18
*最后修改时间：			2022.4.18
*功能：				    实现循环队列的基本操作
*文件中的类与结构体：	CirQueue类
*与其他文件的依赖关系：	测试在test2.cpp文件中
*/

#pragma once
#include<iostream>
#define MaxQueueSize 10
using namespace std;

template<typename T>
class CirQueue
{
private:
    T data[MaxQueueSize]; 
    int front;
    int rear;
    int count;
public:
    CirQueue();     //构造函数
    ~CirQueue();    //析构函数
    bool isempty(); //判断循环队列是否为空
    bool isfull();  //判断循环队列是否为满
    int getlength();//获取循环队列中元素个数
    bool enqueue(const T& x);   //入队
    bool dequeue(T &x);         //出队
    bool getfront(T &x);        //取队首元素
};

//构造函数
template<typename T>
CirQueue<T>::CirQueue()
{
    this->front=0;  //队首指针
    this->rear=0;   //队尾指针
    this->count=0;  //元素个数
    /*
        这里的count记录队列中元素的个数，
        不用浪费一个空间，
        通过判断count=0还是count=MaxQueueSize即可
    */
}

//析构函数
template<typename T>
CirQueue<T>::~CirQueue()
{}

//判断循环队列是否为空
template<typename T>
bool CirQueue<T>::isempty()
{
    return this->count==0;
}

//判断循环队列是否为满
template<typename T>
bool CirQueue<T>::isfull()
{
    return this->count==MaxQueueSize;
}

//获取循环队列中元素个数
template<typename T>
int CirQueue<T>::getlength()
{
    return this->count;
}

//入队
template<typename T>
bool CirQueue<T>::enqueue(const T& x)
{
    if(this->isfull())  return false;
    data[rear]=x;
    rear=(rear+1)%MaxQueueSize;
    count++;
    return true;
}

//出队
template<typename T>
bool CirQueue<T>::dequeue(T& x)
{
    if(this->isempty())  return false;
    x=data[front];
    front=(front+1)%MaxQueueSize;
    return true;
}

//取队首元素
template<typename T>
bool CirQueue<T>::getfront(T &x)
{
    if(this->isempty())  return false;
    x=data[front];
    return true;
}
