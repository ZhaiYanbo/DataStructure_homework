/*
*文件名称：				parking.cpp
*项目名称：				停车场管理
*创建者：				翟衍博
*创建时间：				2022.4.19
*最后修改时间：			2022.4.20
*功能：				   实现停车场管理的模拟
*文件中的函数：		    
*与其他文件的依赖关系：	引入了了"Seqstack.h","LinkQueue.h"头文件
*/

#include"seqstack.h"    //顺序栈
#include"LinkQueue.h"   //链队列
#include<vector>
#define parking_size 2  //停车场规模

//汽车类
class Car
{
    int tag;            //汽车的牌照
    int arrival;        //汽车到达时间
    int depatrue;       //汽车离开时间
    public:
    Car():tag(0),arrival(0),depatrue(0){};  //构造函数
    Car(int tag,int arrival):tag(tag),arrival(arrival),depatrue(0){}
    bool operator>(Car c)   //运算符重载，用于比较车到达快慢
    {return this->arrival>c.arrival;}
    int gettag(){return tag;};   //获取牌照
    void setarrival(int arrival)    //设置到达时间
    {this->arrival=arrival;}
    void setdepatrue(int depatrue)    //设置离开时间
    {this->depatrue=depatrue;}
    int getduration()       //获取停留时间
    {return depatrue-arrival;}
};

//输入车辆信息
void inputInfo(Seqstack<Car>&parking,LinkQueue<Car>&sidewalk,vector<Car>&away)
{
    cout<<"请输入车辆状态信息："<<endl;
    while(true)
    {
        char p1,p2,cm,mode;
        int car_tag;
        int time;
        cin>>p1>>mode>>cm>>car_tag>>cm>>time>>p2;        
        //E表示程序终止
        if(mode=='E')
        {
            cout<<"输入状态已结束……"<<endl;
            break;
        }
        //A表示汽车到达
        else if(mode=='A')
        {
            Car newc(car_tag,time);
            //栈不满就入栈
            if(!parking.isFull())
                parking.push(newc);
            //栈满就入队
            else
                sidewalk.enqueue(newc);
        }
        //D表示汽车离去
        else if(mode=='D')
        {
            //先要找到目标元素
            Seqstack<Car>temp(parking_size);    //辅助栈
            Car a_car;
            while(parking.top_(a_car)&&a_car.gettag()!=car_tag)
            {
                parking.pop();
                temp.push(a_car);
            }
            //离开的元素将其放入away数组中
            parking.pop();
            a_car.setdepatrue(time);
            away.push_back(a_car);
            //再将辅助栈中的元素重新放入栈中
            while(temp.top_(a_car))
            {
                temp.pop();
                parking.push(a_car);
            }
            //如果链上有车等候，就让其进栈
            if(!sidewalk.isempty())
            {
                sidewalk.dequeue(a_car);
                a_car.setarrival(time);
                parking.push(a_car);
            }
        }
    }
}

//查询车辆信息
void SearchInfo(Seqstack<Car>&parking,LinkQueue<Car>&sidewalk,vector<Car>&away,const int price)
{
    while(1)
    {
        start:
        int target;
        cout<<"*************查询页面**************"<<endl;
        cout<<"请输入要查询的车牌号(输入0退出该界面):";
        cin>>target;
        if(!target) return;
        //在数组中（已经离开）查询
        for(int i=0;i<away.size();i++)
        {
            if(target==away[i].gettag())
            {
                cout<<"该车已离开停车场,停车时间为"<<away[i].getduration()<<",应交费用为"<<away[i].getduration()*price<<endl;
                goto start;
            }
        }
        //在栈中（停车场）查询
        Car a_car;
        int position=1;     //表示位置的变量
        Seqstack<Car>tempstack(parking_size);    //临时栈
        while(parking.top_(a_car)&&a_car.gettag()!=target)
        {
            parking.pop();
            tempstack.push(a_car);
            position++;
        }
        //在栈中找到了
        if(!parking.isempty())
        {
            cout<<"该车在停车场,停在第"<<parking_size+1-position<<"个车位（从北向南数）"<<endl;
            //再将辅助栈中的元素挪到parking栈中
            while(tempstack.top_(a_car))
            {
                tempstack.pop();
                parking.push(a_car);
            }
            goto start ;
        }
        while(tempstack.top_(a_car))
        {
            tempstack.pop();
            parking.push(a_car);
        }

        //在队列（便道）中找
        LinkQueue<Car> tempq;   //辅助队列
        position=1;
        while(sidewalk.dequeue(a_car)&&a_car.gettag()!=target)
        {
            tempq.enqueue(a_car);
            position++;
        }
        //在队列中找到了
        if(!sidewalk.isempty())
        {
            cout<<"该车在便道上，排在第"<<position<<"个元素的位置"<<endl;
            //再把便道剩余的车辆都移入辅助队列中
            while (sidewalk.dequeue(a_car))
                tempq.enqueue(a_car);
            //再将辅助队列的车辆移入便道上
            while (tempq.dequeue(a_car))
                sidewalk.enqueue(a_car);
            continue ;
        }
        while (tempq.dequeue(a_car))
                sidewalk.enqueue(a_car);
        //在队列中也没有找到
        cout<<"没有查询到此车相关信息"<<endl;
    }
}

//主函数
int main()
{
    double price;
    cout<<"***欢迎来到停车场管理系统***"<<endl;
    cout<<"请输入停车场单价：";
    cin>>price;
    Seqstack<Car>parking(parking_size);    //停车场
    LinkQueue<Car>sidewalk;                //便道
    vector<Car>away;                       //已经离开的
    //输入信息
    inputInfo(parking,sidewalk,away);
    //查询状态
    SearchInfo(parking,sidewalk,away,price);
    cout<<"谢谢您的使用……"<<endl;
    return 0;
}