//
//  SList.cpp
//  Algorithm
//
//  Created by 张木林 on 10/7/24.
//



//这是单链表的增删查改
//#include "SList.h"
#include<iostream>
using namespace std;

typedef int SLTDateType;

struct SListNode
{
    SLTDateType data;
    SListNode* next;
    
    SListNode(SLTDateType x):data(x),next(nullptr){}//构造函数初始化节点
    
};

//动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
    return new SListNode(x); //使用new分配节点
}

//单链表打印
void SListPrint(SListNode* plist)
{
    SListNode* cur = plist;
    while(cur)
    {
        cout<<cur->data<<" -> ";
        cur = cur->next;
    }
    cout<<"nullptr"<<endl;
}

//单链表尾插
void SListPushBack(SListNode*& plist,SLTDateType x)
{
    SListNode* newNode = BuySListNode(x);
    if(plist == nullptr)
    {
        plist = newNode;//链表为空时，直接插入第一个节点
    }
    else
    {
        SListNode* tail = plist;
        while(tail->next)
        {
            tail = tail->next;//找到最后一个节点
            
        }
        tail->next = newNode; //尾插
    }
}


//单链表的头插
void SListPushFront(SListNode*& plist,SLTDateType x)
{
    SListNode* newNode = BuySListNode(x);
    newNode->next = plist;
    plist = newNode;//更新头指针
}


//单链表的尾删
void SListPopBack(SListNode*& plist)
{
    if(plist == nullptr)
    {
        return; //空链表直接返回
        
    }
    if(plist->next == nullptr)
    {
        delete plist;//只有一个节点，直接删除
        plist = nullptr;
    }
    else
    {
        SListNode* cur = plist;
        while(cur->next->next)
        {
            cur = cur->next;//找到倒数第二个节点
        }
        delete cur->next;//删除最后一个节点
        cur->next = nullptr;//更新尾节点指针
    }
}


//单链表头删
void SListPopFront(SListNode*& plist)
{
    if(plist == nullptr)
    {
        return;
    }
    SListNode* nextNode = plist->next;
    delete plist;//删除头节点
    plist = nextNode;//更新头指针
}


//单链表查找
SListNode* SListFind(SListNode* plist,SLTDateType x)
{
    SListNode* cur = plist;
    while(cur)
    {
        if(cur->data == x)
        {
            return cur;//找到值为x的节点
        }
        cur = cur->next;
        
    }
    return nullptr;//未找到
}


//单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos,SLTDateType x)
{
    if(pos == nullptr)
    {
        return;
    }
    SListNode* newNode = BuySListNode(x);
    newNode->next = pos->next;
    pos->next = newNode;
}

//单链表删除pos位置之后单值
void SListEraseAfter(SListNode* pos)
{
    if(pos == nullptr || pos->next == nullptr)
    {
        return;//pos为空或pos是最后一个节点时，无法删除
    }
    SListNode* temp = pos->next;
    pos->next = temp->next;
    delete temp; //删除pos之后的节点
}

//在pos的前面插入
void SLTInsert(SListNode*& plist,SListNode* pos,SLTDateType x)
{
    if(plist == nullptr || pos == plist)
    {
        //如果链表为空或者插入位置是头节点
        SListPushFront(plist,x);
        return;
    }
    SListNode* cur = plist;
    while(cur->next && cur->next != pos)
    {
        cur = cur->next;//找到pos前一个节点
    }
    if(cur->next == pos)
    {
        SListNode* newNode = BuySListNode(x);
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

//删除pos位置
void SLTErase(SListNode*& plist,SListNode* pos)
{
    if(plist == nullptr || pos == nullptr)
    {
        return;
    }
    if(plist == pos)
    {
        SListPopFront(plist);//pos是头节点，直接头删
        return;
    }
    SListNode* cur = plist;
    while(cur->next && cur->next != pos)
    {
        cur = cur->next; //找到pos前一个节点
        
    }
    if(cur->next == pos)
    {
        cur->next = pos->next;
        delete pos;//删除pos节点
    }
}

//销毁整个链表
void SLTDestroy(SListNode*& plist)
{
    while(plist)
    {
        SListPopFront(plist);//不断头删，释放内存
    }
}
