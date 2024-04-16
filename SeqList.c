//#include"SeqList.h"
//
//void SLInit(SL* psl)
//{
//	assert(psl);
//	psl->a = NULL;
//	psl->capacity = 0;
//	psl->size = 0;
//
//}
//
//void SLCheckCapacity(SL* psl)
//{
//	assert(psl);
//	if (psl->size == psl->capacity)
//	{
//		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
//		SLDataType* tmp = (SLDataType*)realloc(psl->a,sizeof(SLDataType) * newCapacity);
//		if (tmp == NULL)
//		{
//			perror("realloc mail");
//			return;
//		}
//		psl->a = tmp;
//		psl->capacity = newCapacity;
//	}
//	
//}
//
//
//void SLDestroy(SL* psl)
//{
//	assert(psl);
//	if (psl->a != NULL)
//	{
//		free(psl->a);
//		psl->capacity = 0;
//		psl->a = NULL;
//		psl->size = 0;
//	}
//}
//
//
//void SLPrint(SL* psl)
//{
//	assert(psl);
//	for (int i = 0; i <=psl->size; i++)
//	{
//		printf("%d ", psl->a[i]);
//	}
//}
//
//
//
//
//void SLPushBack(SL* psl, SLDataType x)
//{
//	assert(psl);
//
//	SLCheckCapacity(psl);
//
//	psl->a[psl->size] = x;
//	psl->size++;
//}
//
//
////头差
//void SLPushFront(SL* psl, SLDataType x)
//{
//	assert(psl);
//	SLCheckCapacity(psl);
//	int end = psl->size - 1;
//	while (end >= 0)
//	{
//		psl->a[end + 1] = psl->a[end];
//		--end;
//	}
//	psl->a[0] = x;
//	psl->size++;
//}
//
//
//
//void SLPopBack(SL* psl)
//{
//	assert(psl);
//	psl->size--;
//}
//
//
//
//void SLPopFront(SL* psl)
//{
//	assert(psl);
//	int begin = 1;
//	while (begin < psl->size)//这里为什么不能用<=
//	{
//		psl->a[begin - 1] = psl->a[begin];
//		begin++;
//	}
//}
//
//
//
//void SLInsert(SL* psl, int pos, SLDataType x)
//{
//	assert(psl);
//	assert(pos >= 0 && pos <= psl->size);
//	SLCheckCapacity(psl);
//	int end = psl->size - 1;
//	while (end >= pos)
//	{
//		psl->a[end + 1] = psl->a[end];
//		--end;
//	}
//	psl->a[pos] = x;
//	psl->size++;
//	
//	
//}
//
//
//
//
//
//void SLErase(SL* psl, int pos)
//{
//	assert(psl);
//	assert(pos >= 0 && pos <= psl->size);
//	int begin = pos + 1;
//	while (begin < psl->size)//这里为什么也不是<=
//	{
//		psl->a[begin - 1] = psl->a[begin];
//		begin++;
//	}
//	psl->size--;
//	
//}




#include"SeqList.h"

void SLInit(SL* psl)
{
	assert(psl);

	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

void SLDestroy(SL* psl)
{
	assert(psl);

	if (psl->a != NULL)
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

	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

void SLCheckCapacity(SL* psl)
{
	assert(psl);

	if (psl->size == psl->capacity)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		psl->a = tmp;
		psl->capacity = newCapacity;
	}
}

// 10：37
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

	// 挪动数据
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

	// 空
	// 温柔的检查
	/*if (psl->size == 0)
	{
		return;
	}*/

	// 暴力检查
	assert(psl->size > 0);

	//psl->a[psl->size - 1] = -1;
	psl->size--;
}

// 10:47
void SLPopFront(SL* psl)
{
	assert(psl);

	// 暴力检查
	assert(psl->size > 0);

	int begin = 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		++begin;
	}

	psl->size--;
}

// 注意pos是下标
// size是数据个数，看做下标的话，他是最后一个数据的下一个位置
void SLInsert(SL* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);

	SLCheckCapacity(psl);

	// 挪动数据
	int end = psl->size - 1;
	while (end >= pos)
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

	// 挪动覆盖
	int begin = pos + 1;
	while (begin < psl->size)
	{
		psl->a[begin - 1] = psl->a[begin];
		++begin;
	}

	psl->size--;
}