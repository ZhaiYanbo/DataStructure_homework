/*
*文件名称：				2.cpp
*项目名称：				线性表
*创建者：				翟衍博
*创建时间：				2020.3.31
*最后修改时间：			2020.4.2
*功能：				   完成实验指导书对城市链表的一些基本操作
*文件中的函数：		    showmenu(菜单函数)
                       以及菜单中8个功能所对应的8个函数，详见函数声明
*与其他文件的依赖关系：	引入了了"CityLinkedList.h"头文件
*/
#include "CityLinkedList.h"

//显示菜单
void showMenu()
{
    // system("cls");
    // cout<<"menu：\n"
    //     <<"1.creat city linkedlist\n"
    //     <<"2.insert city node\n"
    //     <<"3.search by city name\n"
    //     <<"4.search by city location\n"
    //     <<"5.delete city (by city name or by city location)\n"
    //     <<"6.update city (by city name or by city location)\n"
    //     <<"7.display all city information\n"
    //     <<"8.show all cities whose distance from location P below D\n"
    //     <<"0.exit\n"
    //     <<"------------------------------------------------------------------\n"
    //     <<"please input a integer:";
	cout<<"这是菜单"<<endl;
}

//功能1：创建城市链表
void createC(LinkedList<City>& cities)
{
	// system("cls");
    cout<<"please input the number of cities:";
	int num=0;
	cin>>num;
	cout<<"please input"<<num<<" cities name and  location(2 dimension) one by one:";
	while(num--)
	{
		City c;
		cin>>c;
		cities.insert(c);
	}

	cout<<"creat success"<<endl;
}

//功能2：插入城市节点
void insertC(LinkedList<City>& cities)
{
	// system("cls");
	cout<<"please input the city name and  location(2 dimension) you want to insert:";
	City c;
	cin>>c;
	cities.insert(c);
	cout<<"insert success"<<endl;
}

//功能3：通过城市名查找
void searchByName(LinkedList<City>& cities)
{
	// system("cls");
	string targetname;
	cout<<"please input city name you want to search:";
	cin>>targetname;
	City temp(targetname,-1,-1);	//创建临时的city对象，便于查找,
									//因为location的两个分量只有正数才有意义，所以一定是由于城市名相等才返回的
	int index=cities.find(temp);
	//未找到
	if(index==-1)
	{
		cout<<"no information you are looking for."<<endl;
		return;
	}
	//找到了
	City tempc=cities.getVal(index);
	cout<<"the city you are looking for:"<<tempc;
}

//功能4：通过城市位置查找
void searchByLoc(LinkedList<City>& cities)
{
	// system("cls");
	double targetx,targety;
	cout<<"please input city location you want to search:";
	cin>>targetx>>targety;
	City temp("*#*#*",targetx,targety);	//创建临时的city对象，便于查找,

	int index=cities.find(temp);
	//未找到
	if(index==-1)
	{
		cout<<"no information you are looking for."<<endl;
		return;
	}
	//找到了
	City tempc=cities.getVal(index);
	cout<<"the city you are looking for:"<<tempc;
}

//功能5：删除城市信息（按城市名称/城市位置）
void deleteC(LinkedList<City>& cities)
{
	// system("cls");
	cout<<"Do you want to delete by city name(0)/city location(1)?";
	bool ch;
	cin>>ch;
	int index;
	//按城市名称删除
	if(!ch)
	{	
		string targetname;
		cout<<"please input city name you want to delete:";
		cin>>targetname;
		City temp(targetname,-1,-1);	//创建临时的city对象，便于查找,
										//因为location的两个分量只有正数才有意义，所以一定是由于城市名相等才返回的
		int index=cities.find(temp);
		//未找到
		if(index==-1)
		{
			cout<<"no existence."<<endl;
			return;
		}
		cities.del(index);
		cout<<"delete seccess"<<endl;
	}

	//按城市位置删除
	else
	{
		double targetx,targety;
		cout<<"please input city location you want to delete:";
		cin>>targetx>>targety;
		City temp("*#*#*",targetx,targety);	//创建临时的city对象，便于查找
		int index=cities.find(temp);
		//未找到
		if(index==-1)
		{
			cout<<"no existence."<<endl;
			return;
		}
		cities.del(index);
		cout<<"delete seccess"<<endl;
	}
	cities.display();
}

//功能6：更新城市信息（按城市名称/城市位置）
void updateC(LinkedList<City>& cities)
{
	// system("cls");
	cout<<"Do you want to update by city name(0)/city location(1)?";
	bool ch;
	cin>>ch;
	int index;
	//按城市名称更新
	if(!ch)
	{	
		string targetname;
		cout<<"please input city name you want to update:";
		cin>>targetname;
		City temp(targetname,-1,-1);	//创建临时的city对象，便于查找,
										//因为location的两个分量只有正数才有意义，所以一定是由于城市名相等才返回的
		int index=cities.find(temp);
		//未找到
		if(index==-1)
		{
			cout<<"no existence."<<endl;
			return;
		}

		City tempc=cities.getVal(index);
		cout<<"the city you want to update:"<<tempc;
		cout<<"please input the new information(cityname and city location):";
		cin>>tempc;
		//先删再插
		cities.del(index);
		cities.insert(tempc,index);
		cout<<"update seccess"<<endl;
	}

	//按城市位置更新
	else
	{
		double targetx,targety;
		cout<<"please input city location you want to update:";
		cin>>targetx>>targety;
		City temp("*#*#*",targetx,targety);	//创建临时的city对象，便于查找
		int index=cities.find(temp);
		//未找到
		if(index==-1)
		{
			cout<<"no existence."<<endl;
			return;
		}
		City tempc=cities.getVal(index);
		cout<<"the city you want to update:"<<tempc;
		cout<<"please input the new information(cityname and city location):";
		cin>>tempc;
		//先删再插
		cities.del(index);
		cities.insert(tempc,index);
		cout<<"update seccess"<<endl;
	}
	cities.display();
}

//功能7：显示城市链表
void displayC(LinkedList<City>& cities)
{
	// system("cls");
	cities.display();
}

//功能8：显示距位置P的距离小于D的所有城市
void dis_below(LinkedList<City>& cities)
{
	double px,py,d;
	cout<<"please input the location of p and distance D:";
	cin>>px>>py>>d;
	Location P(px,py);
	LinkedList<City>* closer=new LinkedList<City>();
	for (int i = 0; i < cities.getLength(); i++)
	{
		City c=cities.getVal(i);

		//如果在指定范围内就插入匹配链表
		if (c.getDistance(P) <= d)
		{
			closer->insert(c);
		}
	}
	closer->display();
}


int main()
{
	LinkedList<City> cities;
    while (true)
	{
		//显示菜单
		showMenu();
		//读取用户输入
		int choose;
		cin >> choose;
		//跳转
		switch (choose)
		{
			//建立城市链表
			case 1:
			{
				createC(cities);
				break;
			}

			//插入城市数据
			case 2:
			{
				insertC(cities);
				break;
			}

			//根据名称查找城市
			case 3:
			{
				searchByName(cities);
				break;
			}

			//查找城市经纬度
			case 4:
			{
				searchByLoc(cities);
				break;
			}

			//删除城市信息
			case 5:
			{
				deleteC(cities);
				break;
			}

			//更新城市信息
			case 6:
			{
				updateC(cities);
				break;
			}

			//显示所有城市信息
			case 7:
			{
				displayC(cities);
				break;
			}

			case 8:
			{
				dis_below(cities);
				break;
			}

			//按0退出
			case 0:
			{
			    exit(0);
				break;
			}

			default:
				break;
		}

		//system("pause");
	}
}