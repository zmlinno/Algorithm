//
//  main.c
//  SList
//
//  Created by 张木林 on 3/7/24.
//

#include <stdio.h>
#include "SList.h"


void Test01()
{
    //单链表尾插
    SListNode* plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    SListPrint(plist);
    
}


void Test02()
{
    //单链表头插
    SListNode *plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    
    SListPushFront(&plist, 1);
    SListPrint(plist);
}



void Test03()
{
    //尾删
    SListNode *plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    
    SListPopBack(&plist);
    SListPrint(plist);
}


void Test04()
{
    //头删
    SListNode *plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    
    SListPopFront(&plist);
    SListPrint(plist);
}


void Test05()
{
    SListNode *plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    SListPrint(plist);
    
    
    SListNode *pos = SListFind(plist, 1);
   // SListFind(&plist, 1);
    SLTErase(&plist, pos);
    SListPrint(plist);

    pos = SListFind(plist, 3);
    SLTErase(&plist, pos);
    SListPrint(plist);
    
}
int main()
{
    //Test01();
    //Test02();
    //Test03();
    //Test04();
    Test05();
    return 0;
}
