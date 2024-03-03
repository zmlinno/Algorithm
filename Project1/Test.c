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
	//��������ﲻ������������Ļ���
	//��ô�û�����ռ��ͻ�����������޷����ʡ�
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLPopBack(&sl);
	SLPrint(&sl);

	//βɾ����˼
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


//ͷ��ɾ��
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


//�������
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



//����ɾ��
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