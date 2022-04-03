/*
*文件名称：				3.cpp
*项目名称：				线性表
*创建者：				翟衍博
*创建时间：				2020.4.2
*最后修改时间：			2020.4.2
*功能：				   完成实验指导书对约瑟夫环问题的模拟
*文件中的函数：		    main()函数
*与其他文件的依赖关系：	引入了了"CirLinkedList.h"头文件
*/

#include "CirLinkedList.h"

int main()
{
    //生成循环链表对象
    CirLinkedList c1;

    //用户输入数据
    cout<<"please input m (The initial countoff limit)：";
    int m;
    cin>>m;
    cout<<"please input the number of peopele:";
    int n;
    cin>>n;

    //创建循环链表
    c1.creatCir(n);

    //进行约瑟夫操作
    doJosephus(c1,m);

    return 0;
}