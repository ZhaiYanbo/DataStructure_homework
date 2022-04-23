/*
*文件名称：				seqstack.h
*项目名称：			    顺序栈的实现
*创建者：				翟衍博
*创建时间：				2022.4.18
*最后修改时间：			2022.4.18
*功能：				    实现顺序栈的基本操作
*文件中的类与结构体：	Seqstack类
*与其他文件的依赖关系：	测试在test1.cpp中，具体使用在Goods.h，parking.cpp文件中
*/

//相当于 #ifndef #def ...   #endif
#pragma once

#include<iostream>
using namespace std;
template<typename T>
class Seqstack
{
private:
    int maxsize;//栈的最大容量
    int top;    //栈顶
    T* element; //动态数组
public:
    Seqstack(int maxsize);  //构造函数，创建栈
    ~Seqstack();           //析构函数，销毁栈
    bool isempty();     //判断栈是否为空
    bool isFull();      //栈是否已满
    int length();       //获取栈中元素个数
    bool push(const T&x);   //入栈，成功返回true
    bool top_(T& a);     //获取栈顶元素，成功返回true
    bool pop();         //删除栈顶元素，成功返回true
    void show();        //将栈顺序输出
};

//构造函数
template<typename T>
Seqstack<T>::Seqstack(int maxsize)
{
    this->maxsize=maxsize;
    element=new T[maxsize];
    if(!element)
    {
        cout<<"内存申请失败！";
        exit(0);
    }
    this->top=0;    //栈顶指针指向栈顶元素的上方一个位置，因此top初值为0

}

//析构函数
template<typename T>
Seqstack<T>::~Seqstack()
{
    delete []element;
    //将申请的空间释放掉
}

//判断栈是否为空
template<typename T>
bool Seqstack<T>::isempty()
{
    return (this->top==0);
}

//判断栈是否为满
template<typename T>
bool Seqstack<T>::isFull()
{
    return (this->top==this->maxsize);
}

//获取栈中元素个数
template<typename T>
int Seqstack<T>::length()
{
    return this->top;
}

//入栈
template<typename T>
bool Seqstack<T>::push(const T &x)
{
    if(this->isFull())    return false;
    element[top++]=x;
    return true;
}

//获取栈顶元素
template<typename T>
bool Seqstack<T>::top_(T& a)
{
    if(this->isempty())   return false;
    a= element[top-1];
    return true;
}

//出栈
template<typename T>
bool Seqstack<T>::pop()
{
    if(this->isempty())   return false;
    top--;
    return true;
}

