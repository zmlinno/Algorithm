#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    priority_queue<int>maxHeap;

    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);

    cout<<"Max-Heap Elements:\n";

    while(!maxHeap.empty())
    {
        cout<<maxHeap.top()<<" "; //输出最大元素
        maxHeap.pop();  //移除堆顶
    }
    cout<<endl;
    return 0;
}