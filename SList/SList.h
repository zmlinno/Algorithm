//
//  SList.h
//  SList
//
//  Created by 张木林 on 3/7/24.
//
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



// slist.h
typedef int SLTDateType;
typedef struct SListNode
{
    SLTDateType data;
    struct SListNode* next;
}SListNode;

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
// 单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);

// 单链表查找
void SListNode *SListFind(SListNode* plist, SLTDateType x);




// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);

// 在pos的前面插入
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDateType x);
// 删除pos位置
void SLTErase(SListNode** pphead, SListNode* pos);
void SLTDestroy(SListNode** pphead);

