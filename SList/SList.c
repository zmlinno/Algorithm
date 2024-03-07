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
SListNode *SListFind(SListNode* plist, SLTDateType x);
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


