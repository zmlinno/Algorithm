
//队列的实现
#include<iostream>
#define MAX_SIZE 100
using namespace std;
class Queue
{
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;

public:
    Queue():front(0),rear(-1),size(0){}

    //判断队列是否为空
    bool isEmpty()
    {
        return size == 0;
    }

    //判断队列是否已满
    bool isFull()
    {
        return size == MAX_SIZE;
    }

    //入队操作
    void enqueue(int data)
    {
        if(isFull())
        {
            cout<<"队列已满，无法入队!"<<endl;
            return;
        }
        rear = (rear + 1)%MAX_SIZE;
        arr[rear] = data;
        size++;
    }

    //出队操作
    int dequeue()
    {
        if(isEmpty())
        {
            cout<<"队列为空，无法出队!"<<endl;
            return -1;
        }
        int data = arr[front];
        front = (front+1)%MAX_SIZE;
        size--;
        return data;
    }

    //查看队列头部元素
    int peek()
    {
        if(isEmpty())
        {
            cout<<"队列为空，没有头部元素!"<<endl;
            return -1;
        }
        return arr[front];
    }
};