/*
*文件名称：				LinkedList.h
*项目名称：				线性表
*创建者：				翟衍博
*创建时间：				2020.3.28
*最后修改时间：			2020.4.2
*功能：				    单链表数据结构的实现
*文件中的类与结构体：	结点结构体和单链表类
*文件中的独立函数：		无
*与其他文件的依赖关系：	具体使用在1.cpp文件中
*/

#ifndef LinkedList_
#define LinkedList_

#include<iostream>
using namespace std;

template<typename T>
class ListNode{
public:
    T val;
    ListNode<T>* next;
};

template<typename T>
class LinkedList
{
private:
    /* data */
    ListNode<T>* head;                      
public:
    /* function */
    LinkedList<T>();                           //创建
    ~LinkedList<T>();                          

    bool creatLinkedList(T nums[],int n);
    void destoryLinkedList();   
    int getLength();                        //获得长度
    bool isEmpty();                         //判断是否为空
    T getVal(int index=0);                    //获得指定位置的元素，索引从0开始
    void display();                         //打印链表
    void insert(T num,int index=0);         //在指定位置插入元素，默认为头插
    void del(int index=0);                  //删除指定元素，默认为头删
    int find(T target);                     //查找元素，找到返回元素位置，找不到返回-1

};

template <typename T>
LinkedList<T>::LinkedList()
{
    head=new ListNode<T>;
    head->val=0;
    head->next=NULL;
}

template <typename T>
LinkedList<T>::~LinkedList<T>()
{
    destoryLinkedList();
}

template <typename T>
void LinkedList<T>::destoryLinkedList()
{
    ListNode<T>* pre;
    ListNode<T>* temp;
    pre=head;
    while(pre)
    {
        temp=pre->next;
        pre->next=NULL;
        delete pre;
        pre=temp;
    }
    
}

template<typename T>
bool LinkedList<T>::creatLinkedList(T nums[],int n)
{
    head->val=n;
    head->next=NULL;
    ListNode<T>* rear=head;              //使用的是尾插法，因此要使用一个尾指针
    for(int i=0;i<n;i++)
    {
        ListNode<T>* temp=new ListNode<T>();
        if(! temp)  return false;       //申请失败
        temp->val=nums[i];                //数据域赋值
        rear->next=temp;                
        rear=temp;                      //更新尾指针的值
    }
    rear->next=NULL;
    return true;
}

    template<typename T>
    int LinkedList<T>::getLength()
    {
        return int(head->val);
    }

template<typename T>
bool LinkedList<T>::isEmpty()
{
    return int(head->val)==0;
}

    template<typename T>
    T LinkedList<T>::getVal(int index)
    {
        if(index<0||index>=int(head->val))
        {
            cout<<"getVal函数传递的参数不合理"<<endl;
            exit(0);
        } 
        ListNode<T>* p= head->next;
        while(index--)
        {
            p=p->next;
        }
        return p->val;
    }

template<typename T>
void LinkedList<T>::display()
{
    if(this->isEmpty())
    {
        cout<<"此链表为空"<<endl;
        return ;
    }
    ListNode<T>* p=head->next;
    cout<<"链表的值为：";
    while(p)
    {
        cout<<p->val<<",";
        p=p->next;
    }
    cout<<endl;
}

template<typename T>
void LinkedList<T>::insert(T num,int index)
{
    if(index<0||index>int(head->val))
    {
        cout<<"insert函数传递的参数不合理"<<endl;
        return;
    }
    
    ListNode<T>* p=head;
    while(index--)                          //找到待插入位置的前驱
    {
        p=p->next;
    }
    ListNode<T>* temp=new ListNode<T>();    //申请新节点
    temp->val=num;                          //新节点的数据域赋值
    temp->next=p->next;                     //原先节点的后继作为新节点的后继
    p->next=temp;                           //新节点作为原先节点的后继

    head->val++;

    //this->display();
}

template<typename T>
void LinkedList<T>::del(int index)
{
    if(index<0||index>int(head->val))
    {
        cout<<"del函数传递的参数不合理"<<endl;
        return;
    }

    ListNode<T>* p=head;
    while(index--)         //找到待删除节点的前驱，使用后删
    {
        p=p->next;
    }
    ListNode<T>* temp=p->next;  //记录被删节点
    //T delval=temp->val;       //记录被删元素
    p->next=p->next->next;      //拆链     
    delete temp;                //释放被删节点
    temp=NULL;                  //!delete后一定要指控

    head->val--;

    //this->display();
}

template<typename T>
int LinkedList<T>::find(T target)
{
    int res=0;
    ListNode<T>* p=head->next;
    while(p!=NULL&&p->val!=target)
    {
        p=p->next;
        res++;
    }
    return p==NULL?0:res;
}

#endif