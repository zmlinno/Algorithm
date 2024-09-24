#include"Stack.h"
#include"Queue.h"
#include<iostream>

//栈的实现

// int main()
// {
//     Stack stack;
//     stack.push(10);
//     stack.push(20);
//     stack.push(30);
//     stack.push(40);

//     cout<<"栈顶元素: "<<stack.peel()<<endl;
//     cout<<"出栈元素: "<<stack.pop()<<endl;
//     cout<<"出栈元素: "<<stack.pop()<<endl;

//     if(stack.isEmpty())
//     {
//         cout<<"栈为空"<<endl;
//     }
//     return 0;
// }




int main()
{
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    cout<<"队列头部元素: "<<queue.peek()<<endl;
    cout<<"出队元素: "<<queue.dequeue()<<endl;
    cout<<"出队元素: "<<queue.dequeue()<<endl;

    if(queue.isEmpty())
    {
        cout<<"队列为空"<<endl;
    }
    return 0;
}