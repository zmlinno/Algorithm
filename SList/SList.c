//
//  SList.c
//  SList
//
//  Created by 张木林 on 3/7/24.
//

#include "SList.h"


SListNode* BuySListNode(SLTDateType x)
{
   // SListNode* node = (SListNode*)malloc(sizeof(SListNode));
    SListNode *node = (SListNode*)malloc(sizeof(SListNode));
    node->data = x;
    node->next = NULL;
    //动态申请
    return node;
    
}

void SListPrint(SListNode* plist)
{
    SListNode *cur = plist;
    while(cur != NULL)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}


//单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
    SListNode *newnode = BuySListNode(x);
    if(*pplist == NULL)
    {
        *pplist = newnode;
    }
    else
    {
        SListNode *tail = *pplist;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
    
}




//单链表头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
    SListNode *newnode = BuySListNode(x);
    if(*pplist == NULL)
    {
        *pplist = newnode;
    }
    
    else
    {
        newnode->next = *pplist;
        *pplist = newnode;
        
    }
}



//单链表尾删
void SListPopBack(SListNode** pplist)
{
    SListNode *prev = NULL;
    SListNode *tail = *pplist;
    if (tail == NULL || tail->next == NULL)
    {
        free(tail);
        *pplist = NULL;
    }
    else
    {
        while(tail->next)
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        tail = NULL;
        prev->next = NULL;
        
    }
    
}



//单链表头删
void SListPopFront(SListNode** pplist)
{
    SListNode *tail = *pplist;
    SListNode *prev = NULL;
  
    if(tail == NULL)
    {
        return;
    }
    else if(tail->next == NULL)
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        SListNode *frist = tail->next;
        free(tail);
        *pplist = frist;
    }
}


//单链表查找
//SListNode *SListFind(SListNode* plist, SLTDateType x);
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
    SListNode *cur = plist;
    while(cur)
    {
        if(cur -> data == x)
        {
            return cur;
        }
        else
        {
            cur = cur->next;
        }
    
    }
    
    return NULL;
}

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
    assert(pos);
    assert(pos->next);
    
    SListNode *newnode = BuySListNode(x);
    pos->next = newnode;
    newnode->next = pos->next;
}


// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
    assert(pos);
    SListNode *tmp = pos->next;
    pos->next = pos->next->next;
    free(tmp);
    tmp = NULL;
}


//在pos前面插入
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDateType x)
{
    assert(pos);
    assert(pphead);
    assert(*pphead);
    
    if(*pphead == pos)
    {
        SListPushFront(pphead, x);
    }
    else
    {
        SListNode *prev = *pphead;
        
        while(prev->next != pos)
        {
            prev = prev->next;
        }
        SListNode *newnode = BuySListNode(x);
        prev->next = newnode;
        newnode->next = pos;
        
    }
    
}
void SLTErase(SListNode** pphead, SListNode* pos)
{
    assert(pphead);
    assert(*pphead);
    assert(pos);

    // 10:20继续
    if (*pphead == pos)
    {
        // 头删
        SListPopFront(pphead);
    }
    else
    {
        SListNode *prev = *pphead;
        while (prev->next != pos)
        {
            prev = prev->next;
        }

        prev->next = pos->next;
        free(pos);
        pos = NULL;
    }
}


void SLTDestroy(SListNode** pphead)
{
    assert(pphead);

    SListNode *cur = *pphead;
    while (cur)
    {
        SListNode *next = cur->next;
        free(cur);
        cur = next;
    }

    *pphead = NULL;
}
