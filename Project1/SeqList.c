#include "SeqList.h"

void SLInit(SL* psl)
{
	assert(psl);
	
	//首先在这里设置好初始化
	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

void SLDestroy(SL* psl)
{
	assert(psl);
	if (psl->a != NULL)
	{
		free(psl);
		psl->a = NULL;
		psl->size = 0;
		psl->capacity = 0;
	}
}


void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

void SLCheckCapacity(SL* psl)
{
	//检查空间和容量使用情况
	assert(psl);
	if (psl->size == psl->capacity)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;

		SLDataType* tmp = (SLDataType*)realloc(psl->a, sizeof(SLDataType)* newCapacity);

		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity = newCapacity;
	}
}



//这个是直接插入数据
void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);
	SLCheckCapacity(psl);
	psl->a[psl->size] = x;
	psl->size++;
}


void SLPushFront(SL* psl, SLDataType x)
{
	assert(psl);
	SLCheckCapacity(psl);

	//在这里挪动数据
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end];
		--end;
	}
	psl->a[0] = x;
	psl->size++;
}




void SLPopBack(SL* psl)
{
	assert(psl);
	psl->size--;
}


void SLPopFront(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);

	int begin = 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		begin++;

	}
	psl->size--;
}




void SLInsert(SL* psl, int pos,SLDataType x)
{
	assert(psl);
	assert(pos >= 0 && pos < psl -> size);


	SLCheckCapacity(psl);

	//挪动数据
	int end = psl->size - 1;
	while (end ＞= pos)
	{
		psl->a[end + 1] = psl->a[end];
		--end;

	}
	psl->a[pos] = x;
	psl->size++;
}


void SLErase(SL* psl, int pos)
{

	assert(psl);
	assert(pos >= 0 && pos < psl->size);

	//数据覆盖
	int begin = pos + 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		begin++;
	}
	psl->size--;

}



