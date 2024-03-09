//
//  List.c
//  List
//
//  Created by 张木林 on 3/9/24.
//

#include "List.h"

LTNode *CreateTNode(LTDataType x)
{
    
    LTNode *newnode = (LTNode*)malloc(sizeof(LTNode));
    
    if(newnode == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    newnode->val = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    
    return newnode;
    
}


LTNode *LTnit()
{
    LTNode *phead = CreateTNode(-1);
    phead->next =  phead;
    phead->prev =  phead;
    
    return phead;
}


void LTPushBack(LTNode* phead, LTDataType x)
{
    assert(phead);
    LTNode *tail = phead->prev;
    LTNode *newnode = CreateTNode(x);
    
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = phead;
    phead->prev = newnode;
    
}


void LTPopBack(LTNode* phead)
{
    assert(phead);
    assert(phead->next != phead);
    LTNode *tail = phead->prev;
    LTNode *tailPrev = tail->prev;
    free(tail);
    tailPrev->next = phead;
    phead->prev = tailPrev;
    
}
