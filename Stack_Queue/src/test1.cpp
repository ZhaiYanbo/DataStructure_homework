/*
*文件名称：				test1.cpp
*项目名称：				顺序栈
*创建者：				翟衍博
*创建时间：				2022.4.19
*最后修改时间：			2022.4.22
*功能：				   测试顺序栈
*文件中的函数：		    主函数main() 
*与其他文件的依赖关系：	引入了了"seqstack.h"头文件
*/
#include"seqstack.h"

int main()
{
    Seqstack<int>mystack(5);
    cout<<mystack.isempty()<<endl;
    cout<<mystack.isFull()<<endl;
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    
    cout<<mystack.isempty()<<endl;
    cout<<mystack.isFull()<<endl;
    cout<<mystack.length()<<endl;
    
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    
    int n;
    while(mystack.top_(n))
    {
        mystack.pop();
        cout<<n<<endl;
    }
    cout<<mystack.isFull()<<endl;
    cout<<mystack.length()<<endl;

    return 0;
}