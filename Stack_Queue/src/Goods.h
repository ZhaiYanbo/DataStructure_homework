/*
*文件名称：				Goods.h
*项目名称：				商品货架管理
*创建者：				翟衍博
*创建时间：				2022.4.19
*最后修改时间：			2022.4.19
*功能：				    实现货物类
*类中的函数：		    1.setdate：设置日期   
                        2.operator>：重载>运算符，用于货物间的比较    
                        3.showdate：展示货物的日期
*文件中单独定义的函数： 1.pushGoods函数：用于货架上放货物
                       2.showGoods函数：用于展示货架上货物的信息
*与其他文件的依赖关系：	引入了了"seqstack.h"头文件
*/
#pragma once
#include"seqstack.h"


//货物类
class Goods
{
private:
    int year;
    int month;
    int day;
public:
    bool setdate(int year,int month,int day);   //设置日期
    bool operator>(Goods d);     //重载比较运算符，用于日期间的比较
    void showdate();            //展示日期
};


//设置日期
bool Goods::setdate(int year,int month,int day)
{
    if(year<2010||year>2022||month<1||month>12
    ||day<1||day>30)
        return false;
    this->year=year;
    this->month=month;
    this->day=day;
    
    return true;
}

//重载比较运算符，用于日期间的比较
bool Goods::operator>(Goods d)
{
    return (this->year>d.year)
        || (this->year==d.year)&&(this->month>d.month)
        || (this->year==d.year)&&(this->month==d.month)&&(this->day>d.day);
}

//展示日期
void Goods::showdate()
{
    cout<<this->year<<"年"<<this->month<<"月"<<this->day<<"日"<<endl;
}

//货架上放置货物
void pushGoods(Seqstack<Goods>& shelf,Goods g)
{
    Seqstack<Goods>temp(shelf.length());  //临时栈，用于倒货架
    Goods gd;
    //有栈顶元素并且日期比g小（就是比g旧），那么让栈顶元素出栈，放入临时栈中
    while(shelf.top_(gd)&&g>gd) 
    {
        temp.push(gd);
        shelf.pop();
    }
    shelf.push(g);  
    //然后将临时栈中的元素再全部放入shelf货架上
    
    while(!temp.isempty())
    {
        temp.top_(gd);
        temp.pop();
        shelf.push(gd);
    }
}

//在货架上从前到后（从栈顶到栈底）展示货物
void showGoods(Seqstack<Goods>& shelf)
{
    if(shelf.isempty())
    {
        cout<<"该货架为空"<<endl;
        return ;
    }
    cout<<"该货架上商品的生产日期依次为：";
    Goods gd;
    while(!shelf.isempty())
    {
        shelf.top_(gd);
        gd.showdate();
        shelf.pop();
    }
        
}
