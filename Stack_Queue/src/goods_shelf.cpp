/*
*文件名称：				goods_shelf.cpp
*项目名称：				商品货架管理
*创建者：				翟衍博
*创建时间：				2022.4.19
*最后修改时间：			2022.4.19
*功能：				   实现商品管理
*文件中的函数：		    showmenu(菜单函数)
                       fun1(向货架上添加货物的函数) 
*与其他文件的依赖关系：	引入了了"Goods.h"头文件
*/
#include"Goods.h"

//显示菜单
void showMenu()
{
    cout<<"*****欢迎来到商品货架管理系统*****"<<endl;
    cout<<"1.向货架上增添新货物"<<endl;
    cout<<"2.查看当前货架上货物信息"<<endl;
    cout<<"0.退出系统"<<endl;
    cout<<"请输入选择：";
}

//功能1：1.向货架上增添新货物
//之所以一个功能再写一个函数是为了处理一些异常的情况，让主函数看起来更加清爽
void fun1(Seqstack<Goods>&shelf)
{
    if(shelf.isFull())
    {
        cout<<"货架已满，无法添加"<<endl;
        return ;
    }
    Goods newgd;
    int year,month,day;
    cout<<"请输入新货物的生产日期"<<endl;
    cout<<"tip:依次输入年、月、日：";
    dateerr:
    cin>>year>>month>>day;
    if(!newgd.setdate(year,month,day))
    {
        cout<<"货物生产日期输入不当，请重新输入！"<<endl;
        goto dateerr;
    }
    pushGoods(shelf,newgd);
    cout<<"货物添加成功！"<<endl;
}


int main()
{
    Seqstack<Goods>shelf(10);
    while(true)
    {
        showMenu();
        int choose;
        cin>>choose;
        switch(choose)
        {
            //1.向货架上增添新货物
            case 1:
                fun1(shelf);
                break;
            //展示货架上货物信息
            case 2:
                showGoods(shelf);
                break;
            case 0:
                cout<<"感谢您的使用……"<<endl;
                exit(0);
            default:
                break;
        }
        
    }
    
    return 0;
}