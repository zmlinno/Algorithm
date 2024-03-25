#include"Queue.h"

void Test()
{
    Queue Q;
    QueueInit(&Q);
    QueuePush(&Q,1);
    QueuePush(&Q,2);
    QueuePush(&Q,3);
    printf("%d ",QueueFront(&Q));
    //QueuePop(&Q);

}


int main()
{
    Test();

    return 0;
}