#include<iostream>
//栈的实现
#define MAX_SIZE 100 //栈的最大容量
using namespace std;
class Stack
{
private:
    int arr[MAX_SIZE]; //用数组来实现栈
    int top;

public:
    Stack():top(-1){}

    //判断栈是否为空
    bool isEmpty()
    {
        return top == -1;

    }

    //判断栈是否已满
    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    //入栈操作
    void push(int data)
    {
        if(isFull())
        {
            cout<<"栈已满，无法入栈"<<endl;
            return;
        }
        arr[++top] = data;
    }

    //出栈操作
    int pop()
    {
        if(isEmpty())
        {
            cout<<"栈为空,无法出栈! "<<endl;
            return -1;
        }
        return arr[top--];
    }

    //查看栈顶元素
    int peel()
    {
        if(isEmpty())
        {
            cout<<"栈为空，没有栈顶元素!"<<endl;
            return -1;
        }
        return arr[top];
    }
};