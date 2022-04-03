/*
*文件名称：				CirLinkedList.h
*项目名称：			    线性表
*创建者：				翟衍博
*创建时间：				2020.4.2
*最后修改时间：			2020.4.2
*功能：				    解决约瑟夫环问题所需的循环链表功能实现
*文件中的类与结构体：	结点结构体和循环链表类
*文件中的独立函数：		无
*与其他文件的依赖关系：	具体使用在2.cpp文件中
*/

#include<iostream>
using namespace std;

//循环链表节点
struct CirListNode
{
    int number;         //序号
    int code;           //密码
    CirListNode* next;
};

class CirLinkedList
{
private:
    /* data */
    CirListNode* rear;  //带头结点的有尾指针的循环链表
public:
    CirLinkedList();
    ~CirLinkedList();
    void creatCir(int n);
    int getlen();
    bool empty();
    int del(int number);

    //友元函数，进行约瑟夫操作
    friend void doJosephus(CirLinkedList& c,int m);
};

//构造函数
CirLinkedList::CirLinkedList()
{
    rear=nullptr;
}

//析构函数
CirLinkedList::~CirLinkedList()
{
    CirListNode* p=rear;
    CirListNode* q=rear->next;
    while(p!=q)
    {
        p->next=p->next->next;
        q->next=nullptr;
        delete q;
        q=p->next;
    }
    q->next=nullptr;
    delete q;
    
}

//创建循环链表
void CirLinkedList::creatCir(int n)
{
    rear=new CirListNode();
    if(!rear)
    {
        cout<<"申请空间失败！"<<endl;
        return ;
    }
    
    rear->next=new CirListNode();   //头节点
    if(!rear->next) 
    {
        cout<<"申请空间失败！"<<endl;
        return ;
    }
    rear->next->next=rear;
    rear->next->code=n;
    rear->next->number=0;
    cout<<"please input "<<n<<" codes one by one:";
    rear->number=1;
    cin>>rear->code;
    //第一个节点在上面已经申请，因此从第二个结点开始
    for(int i=2;i<=n;i++)
    {
        //采用后插
        CirListNode* temp=new CirListNode();    //1.申请新节点
        if(!temp)
        {
            cout<<"申请空间失败！"<<endl;
            return ;
        }
        
        cin>>temp->code;                        //2.数据域赋值
        temp->number=i;
        temp->next=rear->next;                  //3.新节点的后继作为原先节点的后继
        rear->next=temp;                        //4.新节点作为原先节点的后继

        rear=rear->next;           //更新尾指针的
    }
}

//获取循环链表的长度
int CirLinkedList::getlen()
{
    return rear->next->code;
}

//判断循环链表是否为空
bool CirLinkedList::empty()
{
    return rear->next->code==0;
}

//删除指定号码的节点，并返回其密码
int CirLinkedList::del(int number)
{
    //异常情况，链表为空
    if(!rear)    return -1;

    CirListNode* p=rear;
    while(p->next->number!=number)
    {
        p=p->next;          //这是p指向了待删除元素的前驱节点
    }
    //后删节点
    CirListNode* q=p->next; //获取被删节点
    int res=q->code;        //获取被删元素
    p->next=q->next;        //拆链
    q->next=nullptr;

    //后删可能要更新尾指针，这是在一步步调试中发现的问题
    if(rear==q) 
        rear=p;
    delete q;               //释放被删节点

    rear->next->code--;
    return res;
}

//约瑟夫函数
void doJosephus(CirLinkedList& c,int m)
{
    cout<<"the order of departure:";
    CirListNode* pt=c.rear->next;
    int cnt=1;
    while(c.getlen()>1)
    {
        if(!pt->number)  //是头节点，直接跳过，指数器不加1
        {
            pt=pt->next;
        }
        else
        {
            pt=pt->next;
            cnt++;
            if(!pt->number)  //是头节点，直接跳过，指数器不加1
            {
                pt=pt->next;
            }
        }

        if(cnt==m)
        {
            cout<<pt->number<<" ";  //输出
            CirListNode* temp=pt->next; //临时保存pt
            m=c.del(pt->number);    //更新m
            pt=temp;
            if(!pt->number)  //是头节点，直接跳过，指数器不加1
            {
                pt=pt->next;
            }
            cnt=1;                 //更新cnt
        }   
        
    }
    //最后留下来的数
    cout<<c.rear->number;
}