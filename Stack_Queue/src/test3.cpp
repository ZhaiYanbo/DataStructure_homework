/*
*文件名称：				test3.cpp
*项目名称：				链队列
*创建者：				翟衍博
*创建时间：				2022.4.20
*最后修改时间：			2022.4.20
*功能：				   测试链队列
*文件中的函数：		    主函数main() 
*与其他文件的依赖关系：	引入了了"LinkQueue.h"头文件
*/

#include"LinkQueue.h"
int main()
{
    LinkQueue<char>lq;
    cout<<lq.isempty()<<endl;;
    char ch='f';
    cout<<lq.dequeue(ch)<<endl;
    cout<<ch<<endl;
    lq.enqueue('a');
    lq.enqueue('b');
    lq.dequeue(ch);
    cout<<ch<<endl;
    lq.enqueue('c');
    lq.enqueue('d');
    lq.enqueue('e');
    return 0;
}