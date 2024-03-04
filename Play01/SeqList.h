//
//  SeqList.h
//  Play01
//
//  Created by 张木林 on 3/3/24.
//

#ifndef SeqList_h
#define SeqList_h


#endif /* SeqList_h */
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef SLDataType;

typedef struct SeqList
{
    SLDataType* a;
    int size;
    int capacity;
}SL;

void SLInit(SL* psl);
void SLDestroy(SL* psl);


void SLPrint(SL* psl);
void SLCheckCapacity(SL* psl);




//头尾删除和插入
void SLPushBack(SL* psl, SLDataType x);
void SLPushFront(SL* psl, SLDataType x);
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);




//任意下标位置的插入和删除
void SLInsert(SL* psl, int pos,SLDataType x);
void SLErase(SL* psl, int pos);
