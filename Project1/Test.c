#include <stdio.h>
#include "SeqList.h"
void Test1()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);


	SLPushFront(&sl, 10);
	SLPushFront(&sl, 20);
	SLPushFront(&sl, 30);
	SLPrint(&sl);

	SLDestroy(&sl);
}


void Test2()
{
	SL sl;
	SLInit(&sl);
	//如果在这里不输入这个函数的话，
	//那么久会产生空间冲突，导致数据无法访问。
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLPopBack(&sl);
	SLPrint(&sl);

	//尾删的意思
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);


	SLPushFront(&sl, 10);
	SLPushFront(&sl, 20);
	SLPushFront(&sl, 30);
	SLPushFront(&sl, 40);
	SLPrint(&sl);

	SLDestroy(&sl);



	//SLDestroy(&sl);
}


//头部删除
void Test3()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	//SLPopFront(&sl);
	//SLPrint(&sl);
}


//任意插入
void Test4()
{
	//SL* ptr = NULL;
	//SLInit(ptr);

	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLInsert(&sl, 2, 20);
	SLPrint(&sl);

	SLInsert(&sl, 6, 20);
	SLPrint(&sl);

	SLInsert(&sl, 0, 20);
	SLPrint(&sl);

	SLInsert(&sl, 10, 20);
	SLPrint(&sl);

	SLDestroy(&sl);
}



//任意删除
void Test5()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLErase(&sl, 3);
	SLPrint(&sl);

	SLErase(&sl, 3);
	SLPrint(&sl);

	//SLErase(&sl, 3);
	//SLPrint(&sl);
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();

	return 0;
}