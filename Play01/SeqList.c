//
//  SeqList.c
//  Play01
//
//  Created by 张木林 on 3/3/24.
//

#include "SeqList.h"


void SLInit(SL* psl)
{
    assert(psl);
    psl->a = NULL;
    psl->size = 0;
    psl->capacity = 0;
    
}


//每次调用完之后数据重置
void SLDestroy(SL* psl)
{
    assert(psl);
    if(psl->a != NULL)
    {
        free(psl->a);
        psl->a = NULL;
        psl->size = 0;
        psl->capacity = 0;
        
    }
}


void SLPrint(SL* psl)
{
    assert(psl);
    for(int i = 0;i<psl->size;i++)
    {
        printf("%d ",psl->a[i]);
    }
    printf("\n");
}



void SLCheckCapacity(SL* psl)
{
    assert(psl);
    if(psl->size == psl->capacity)
    {
        int newCapacity = psl->capacity == 0 ? 4 : psl->capacity*2;
        SLDataType* tmp = (SLDataType*)realloc(psl->a,sizeof(SLDataType)*newCapacity);
        
    if(tmp == NULL)
    {
        perror("realloc fail");
        return;
    }
        psl->a = tmp;
        psl->capacity = newCapacity;
    }
}



void SLPushBack(SL* psl, SLDataType x)
{
    assert(psl);
    SLCheckCapacity(psl);
    psl->a[psl->size] = x;
    psl->size++;
}


//头插
void SLPushFront(SL* psl, SLDataType x)
{
    assert(psl);
    SLCheckCapacity(&psl);
    
    int end = psl->size - 1;
    while(end >= 0)
    {
        psl->a[end + 1] = psl->a[end];
        --end;
    }
    psl->a[0] = x;
    psl->size++;
}

//尾删
void SLPopBack(SL* psl)
{
    assert(psl && psl->size > 0);
    psl->size--;
    
    
}

//头删
void SLPopFront(SL* psl)
{
    assert(psl);
    assert(psl->size>0);
    //在这里因为如果不写size这个判断语句的话，
    //那么size = 0的话，就什么也无法删除了。
    int begin = 1;
    while(begin < psl->size)
    {
        psl->a[begin - 1] = psl->a[begin];
        begin++;
    }
    psl->size--;
    
}



//任意插入
void SLInsert(SL* psl, int pos,SLDataType x)
{
    assert(psl);
    assert(pos>=0 && pos<psl->size);
    SLCheckCapacity(psl);
    
    int end = psl->size - 1;
    while(end>=pos)
    {
        psl->a[end + 1] = psl->a[end];
        --end;
    }
    psl->a[pos] = x;
    psl->size++;
}



//任意删除
void SLErase(SL* psl, int pos)
{
    assert(psl);
    assert(pos>=0 && pos<psl->size);
   // SLCheckCapacity(psl);
    
    int begin = pos+1;
    while(begin<psl->size)
    {
        psl->a[begin - 1] = psl->a[begin];
        begin++;
    }
    psl->size--;
}
