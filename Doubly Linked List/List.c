#include"List.h"

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>


ListNode *Tnit(LTDataType x)
{
    ListNode *newnode = (ListNode*)malloc(sizeof(ListNode*));
    if(newnode == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    newnode->_data = x;
    newnode->_next = NULL;
    newnode->_prev = NULL;

    return newnode;
}


// 创建返回链表的头结点.
ListNode* ListCreate()
{
    ListNode *phead = Tnit(-1);

    phead->_next = phead;
    phead->_prev = phead;

    return phead;
}



//双向链表销毁
void ListDestory(ListNode* pHead)
{
    assert(pHead);
    ListNode *cur = pHead->_next;
    while(cur != pHead)
    {
        ListNode *next = cur->_next;
        free(cur);
        cur = next;
    }
    free(pHead);
}


// 双向链表打印
void ListPrint(ListNode* pHead)
{
    assert(pHead);
    ListNode *cur = pHead->_next;
    while(cur != NULL)
    {
        
        printf("%d ",cur->_data);
        cur = cur->_next;

    }
    printf("\n");

}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
    assert(pHead);
     ListNode *tail = pHead->_prev;
     ListNode *NewNode = Tnit(x);

     tail->_next = NewNode;
     NewNode->_prev = tail;
     NewNode->_next = pHead;
     pHead->_prev = NewNode;
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
    assert(pHead);
    ListNode *tail = pHead->_prev;
    ListNode *tailPrev = tail->_prev;

    free(tail);
    tailPrev->_next = pHead;
    pHead->_next = tailPrev;

}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
    assert(pHead && pHead->_next);

    ListNode *phead =pHead->_next;
    ListNode *NewNode = Tnit(x);

    pHead->_next = NewNode;
    NewNode->_prev = pHead;
    NewNode->_next = phead;
    phead->_prev = NewNode;
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
    assert(pHead && pHead->_next != pHead);
    ListNode *frist = pHead->_next;
    ListNode *frist2 = frist->_next;

    pHead->_next = frist2;
    frist2->_prev = pHead;
    free(frist);
    frist = NULL;
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListNode *phead = pHead->_next;
    while(phead != pHead)
    {
        if(phead->_data == x)
        {
            return phead;
        }
        else
        {
            phead = phead->_next;
        }
        return NULL;
    }
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);

    ListNode *PosPrev = pos->_prev;
    ListNode *NewNode = Tnit(x);

    PosPrev->_next = NewNode;
    NewNode->_prev = PosPrev;
    NewNode->_next = pos;
    pos->_prev = NewNode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
    assert(pos);
    ListNode *PosPrev = pos->_prev;
    ListNode *PosNext = pos->_next;

    PosPrev->_next = PosNext;
    PosNext->_prev = PosPrev;
    free(pos);
}


