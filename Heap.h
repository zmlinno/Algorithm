#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
// 规定删除堆顶（根节点）
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
size_t HeapSize(HP* php);
bool HeapEmpty(HP* php);

