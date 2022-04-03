/*
*文件名称：				CityLinkedList.h
*项目名称：				城市链表
*创建者：				翟衍博
*创建时间：				2020.3.31
*最后修改时间：			2020.4.2
*功能：				    城市链表数据结构的实现
*文件中的类与结构体：	结点结构体和单链表类
*文件中的独立函数：		无
*与其他文件的依赖关系：	具体使用在2.cpp文件中
*/

//相当于 #ifndef #def ...   #endif
#pragma once

#include "LinkedList.h"
#include<string>
#include<math.h>

struct Location
{
	double x;
	double y;
    //构造函数
    Location(){};
    Location(double x,double y)
    {
        this->x=x;
        this->y=y;
    }
};

//定义城市数据类型
class City
{
        private:
        string cname;   //城市名称
        Location p;     //位置坐标

    public:
    //构造函数
    City()
    {
        this->cname="undefined";
        this->p.x=0;
        this->p.y=0;
    }
    City(string cname, double x, double y)
    {
        this->cname=cname;
        this->p.x=x;
        this->p.y=y;
    }

    //更新位置坐标
    void update(double x,double y)
    {
        this->p.x=x;
        this->p.y=y;
    }

    //重载==、！=运算符，方便后后续的查找需要
    bool operator==(City c)
    {
        return this->cname==c.cname||this->p.x==c.p.x&&this->p.y==c.p.y;
    }

    bool operator!=(City c)
    {
        return !(this->cname==c.cname||this->p.x==c.p.x&&this->p.y==c.p.y);
    }

    //重载输入运算符
    friend istream& operator>>(istream& in,City &c)
    {
         in >> c.cname >> c.p.x>>c.p.y;
        return in;
    }
    

    //重载输出运算符，为了兼容cout<<val
    friend ostream& operator<<(ostream& out , City &c)
    {
        cout<<c.cname<<"("<<c.p.x<<","<<c.p.y<<")";
        return out;
    }

   //以下4个运算符重载（对++、--、=、int（））都是为了兼容头节点的数据域表示链表长 
    //重载++、--运算符
    City operator++(int n)      //有参数n的为++后置形式
    {
        this->p.x++;
        return *this;
    }

    City operator--(int n)      //有参数n的为--后置形式
    {
        this->p.x--;
        return *this;
    }

    //定义City到int的类型转换
	operator int() 
    { return int(this->p.x); }

    //重载赋值运算
    City operator=(int x) 
	{ this->p.x = x;  return *this; }
    //距离函数
    double getDistance(Location p2)
    {
        return sqrt((this->p.x-p2.x)*(this->p.x-p2.x)+(this->p.y-p2.y)*(this->p.y-p2.y));
    }

};






