
#include<stdio.h>
#include"SeqList.h"
#include"SeqList.c"
//void Test1()
//{
//	SL s1;
//	SLInit(&s1);
//	SLPushBack(&s1, 1);
//	SLPushBack(&s1, 2);
//	SLPushBack(&s1, 3);
//	SLPushBack(&s1, 4);
//	SLPushBack(&s1, 5);
//	SLPrint(&s1);
//
//	SLDestroy(&s1);
//}

void TestSL5()
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
	TestSL5();
	return 0;
}