//
//  List.h
//  List
//
//  Created by 张木林 on 3/9/24.
//

#pragma one
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
    struct ListNode *next;
    struct ListNode *prev;
    LTDataType val;
}LTNode;

LTNode* LTInit();
//打印双向链表的值
void LTPrint(LTNode* phead);
//在双向链表的末尾添加一个值为x的新节点
void LTPushBack(LTNode* phead, LTDataType x);
//删除双向链表的末尾节点
void LTPopBack(LTNode* phead);
