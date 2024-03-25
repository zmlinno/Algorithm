#include"Queue.h"




// 初始化队列 
void QueueInit(Queue* q)
{
    assert(q);
    q->_front = q->_rear = NULL;
    q->size = 0;
    
}

//队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
    assert(q);
    QNode *NewNode = (QNode*)malloc(sizeof(QNode));
    if(NewNode == NULL)
    {
        printf("malloc fail");
        exit(-1);
    }
    NewNode->_data = data;
    NewNode->_next = NULL;
    if(q->_rear == NULL)
    {
        q->_front = q->_rear = NewNode;

    }
    else
    {
        q->_rear->_next = NewNode;
        q->_rear = NULL;
    }
}



// void QueuePush(Queue* q, int data) { // 假设数据类型为int
//     QNode* newNode = (QNode*)malloc(sizeof(QNode));
//     if (newNode == NULL) {
//         printf("Memory allocation failed.\n");
//         exit(EXIT_FAILURE);
//     }
//     newNode->_data = data;
//     newNode->_next = NULL;

//     if (q->_rear == NULL) {
//         q->_front = q->_rear = newNode;
//     } else {
//         q->_rear->_next = newNode;
//         q->_rear = newNode;
//     }
// }




// 队头出队列 
void QueuePop(Queue* q)
{
    assert(q);
    assert(q->_front->_next);
    Queue *del = q->_front;
    q->_front = q->_front->_next;
    free(del);

    del = NULL;
    if (q->_front == NULL)
    {
        q->_rear = NULL;
    }
    q->size--;
    
}





// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
    assert(q && q->_front);
    
    return q->_front->_data;
}


// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
    assert(q);
    assert(q->_rear);
    return q->_rear->_data;
}


// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
    assert(q);
    return q->size;
}



// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
    if(q->_front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// 销毁队列 
void QueueDestroy(Queue* q)
{
    assert(q);
    Queue *cur = q->_front;
    while(cur)
    {
        Queue *next = cur->_front->_next;
        free(cur);
        cur = next;

    }
    q->_front = q->_rear = NULL;
    q->size = 0;
}

