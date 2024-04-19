#include"Heap.h"




void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
	//��ʼ��
}

void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = 0;
	php->size = php->capacity = 0;
}



void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (parent >= 0)
	//����
	//while(child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;//�������ʣ�ΪʲôҪ-1/2��
			
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	
	//1.�ڲ����ʱ��������
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit("-1");
		}
		
			php->a = tmp;
			php->capacity = newCapacity;
		}
		php->a[php->size] = x;
		php->size++;

		AdjustUp(php->a, php->size - 1);

	//���ǹ������ѵ�
}


void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child+1] <a[child])
		{
			//��һ�δ������жϣ��ĸ��ڵ��ֵ��С
			//���ж��Ƿ������ӽڵ㣬����еĻ��Ƚϴ�С������ұ߱����С�Ļ�
			//ͨ��++child����ôchild���ɸ�С��ֵ
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			//child = parent;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php && php->size > 0);

	Swap(&php->a[0], &php->size - 1);
	php->size--;
	AdjustDown(php->a, php->size, 0);

}


//�������ֱ�ӷ��ض�topԪ��
HPDataType HeapTop(HP* php)
{
	assert(php && php->size > 0);
	return php->a[0];
}


size_t HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

//
//bool HeapEmpty(HP* php)
//{
//	if (php->a == NULL)
//	{
//		return false;
//	}
//	else
//	{
//		true;
//	}
//}



bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}


void HeapPrint(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}