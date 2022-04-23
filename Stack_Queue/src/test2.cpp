/*
*文件名称：				test2.cpp
*项目名称：				循环队列
*创建者：				翟衍博
*创建时间：				2022.4.19
*最后修改时间：			2022.4.19
*功能：				   测试循环队列
*文件中的函数：		    主函数main() 
*与其他文件的依赖关系：	引入了了"CirQueue.h"头文件
*/
#include"CirQueue.h"

int main()
{
    CirQueue<char>mycque;
    cout<<mycque.isempty()<<endl;
    cout<<mycque.getlength()<<endl;
    char ch;
    if (mycque.getfront(ch))    cout<<ch<<endl;
    else cout<<"队列为空，队首无元素"<<endl;

    mycque.enqueue('a');
    mycque.enqueue('b');
    mycque.enqueue('c');
    mycque.enqueue('e');
    mycque.enqueue('f');
    mycque.enqueue('g');
    mycque.enqueue('h');
    mycque.enqueue('i');
    cout<<mycque.getlength()<<endl;

    if (mycque.getfront(ch))    cout<<ch<<endl;
    else cout<<"队列为空，队首无元素"<<endl;

    mycque.dequeue(ch);
    mycque.dequeue(ch);
    if (mycque.getfront(ch))    cout<<ch<<endl;
    else cout<<"队列为空，队首无元素"<<endl;


    return 0;
}