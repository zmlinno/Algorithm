//
//  main.c
//  Play01
//
//  Created by 张木林 on 3/3/24.
//



#include <stdio.h>
#include "SeqList.h"
//void Test1()
//{
//    SL sl;
//    SLInit(&sl);
//    SLPushBack(&sl, 1);
//    SLPushBack(&sl, 2);
//    SLPushBack(&sl, 3);
//    SLPushBack(&sl, 4);
//    SLPushBack(&sl, 5);
//    SLPrint(&sl);
//
//
//    SLPushFront(&sl, 10);
//    SLPushFront(&sl, 20);
//    SLPushFront(&sl, 30);
//    SLPrint(&sl);
//
//    SLDestroy(&sl);
//}
//
//
//void Test2()
//{
//    SL sl;
//    SLInit(&sl);
//    //如果在这里不输入这个函数的话，
//    //那么久会产生空间冲突，导致数据无法访问。
//    SLPushBack(&sl, 1);
//    SLPushBack(&sl, 2);
//    SLPushBack(&sl, 3);
//    SLPushBack(&sl, 4);
//    SLPushBack(&sl, 5);
//    SLPrint(&sl);
//
//    SLPopBack(&sl);
//    SLPrint(&sl);
//
//    //尾删的意思
//    //SLPopBack(&sl);
//    //SLPopBack(&sl);
//    //SLPopBack(&sl);
//    //SLPopBack(&sl);
//    //SLPrint(&sl);
//
//
//    //SLPushFront(&sl, 10);
//    //SLPushFront(&sl, 20);
//    //SLPushFront(&sl, 30);
//    //SLPushFront(&sl, 40);
//    //SLPrint(&sl);
//
//    SLDestroy(&sl);
//
//
//
//    //SLDestroy(&sl);
//}
//
//
////头部删除
//void Test3()
//{
//    SL sl;
//    SLInit(&sl);
//    SLPushBack(&sl, 1);
//    SLPushBack(&sl, 2);
//    SLPushBack(&sl, 3);
//    SLPushBack(&sl, 4);
//    SLPushBack(&sl, 5);
//    SLPrint(&sl);
//
//    SLPopFront(&sl);
//    SLPrint(&sl);
//
//    SLPopFront(&sl);
//    SLPrint(&sl);
//
//    SLPopFront(&sl);
//    SLPrint(&sl);
//
//    SLPopFront(&sl);
//    SLPrint(&sl);
//
//    SLPopFront(&sl);
//    SLPrint(&sl);
//
//    //SLPopFront(&sl);
//    //SLPrint(&sl);
//}
//
//
////任意插入
//void Test4()
//{
//    //SL* ptr = NULL;
//    //SLInit(ptr);
//
//    SL sl;
//    SLInit(&sl);
//    SLPushBack(&sl, 1);
//    SLPushBack(&sl, 2);
//    SLPushBack(&sl, 3);
//    SLPushBack(&sl, 4);
//    SLPushBack(&sl, 5);
//    SLPrint(&sl);
//    
//    SLInsert(&sl, 1, 10);
//    SLPrint(&sl);
//
//    //SLInsert(&sl, 2, 20);
//    //SLPrint(&sl);
//
// 
//    //SLInsert(&sl, 0, 20);
//    //SLPrint(&sl);
//
//    //SLInsert(&sl, 10, 20);
//    //SLPrint(&sl);
//
//    //SLInsert(&sl, 4, 10);
//    //SLPrint(&sl);
//
//
//    SLDestroy(&sl);
//}
//
//
//
////任意删除
//void Test5()
//{
//    SL sl;
//    SLInit(&sl);
//    SLPushBack(&sl, 1);
//    SLPushBack(&sl, 2);
//    SLPushBack(&sl, 3);
//    SLPushBack(&sl, 4);
//    SLPushBack(&sl, 5);
//    SLPrint(&sl);
//
//    SLErase(&sl, 3);
//    SLPrint(&sl);
//
//    SLErase(&sl, 3);
//    SLPrint(&sl);
//
//    //SLErase(&sl, 3);
//    //SLPrint(&sl);
//}


void Test6()
{
    SL sl;
    SLInit(&sl);
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPushBack(&sl, 3);
    SLPrint(&sl);
    
   
    SLDestroy(&sl);
    
}


void Test7()
{
    SL sl;
    SLInit(&sl);
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPushBack(&sl, 3);
    SLPrint(&sl);
    
    
    SLPushFront(&sl, 10);
    SLPrint(&sl);
    
    SLDestroy(&sl);
}

void Test8()
{
    SL sl;
    SLInit(&sl);
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPushBack(&sl, 3);
    SLPrint(&sl);
    
    SLPopFront(&sl);
    SLPrint(&sl);
    SLDestroy(&sl);
}

void Test9()
{
    SL sl;
    SLInit(&sl);
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPushBack(&sl, 3);
    SLPrint(&sl);
    
    SLInsert(&sl,0,10);
    SLPrint(&sl);
    SLDestroy(&sl);
//    
    
}


void Test10()
{
    SL sl;
    SLInit(&sl);
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPushBack(&sl, 3);
    SLPrint(&sl);
    
    SLErase(&sl, 1);
    SLPrint(&sl);
    
    SLDestroy(&sl);
}
    
int main()
{
    //Test7();
    //Test8();
    //Test9();
    Test10();
    return 0;
}
