#include"Heap.h"

#include<stdio.h>
void Test1()
{
    HP heap;
    HeapInit(&heap);

    HeapPush(&heap, 1);
    HeapPush(&heap, 2);
    HeapPush(&heap, 3);
    HeapPush(&heap, 4);

    HeapPrint(&heap);
    HeapDestroy(&heap);


}

void Test2()
{
    HP heap;
    HeapInit(&heap);

    HeapPush(&heap, 1);
    HeapPush(&heap, 2);
    //HeapPrint(&heap);

    HeapPop(&heap);

    HeapPrint(&heap);
    HeapDestroy(&heap);

}
void PrintArray(HPDataType* a, int size) {
    printf("Array contents: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
	//Test1();
    //Test2();

        // 创建一个数组作为堆
    //HPDataType a[] = { 8,7,6,5,4, 3, 2, 1 };
    //HPDataType a[] = { 10,22,34,2,1,56,100 };
    HPDataType a[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(a) / sizeof(a[0]);

    printf("Original array: ");
    PrintArray(a, size);

    // 选择一个子节点进行向上调整
    int child = 2; // 选择索引为2的元素（值为2）进行向上调整

    // 调用 AdjustUp 函数
    //AdjustUp(a, child);
    AdjustDown(a, child);
    printf("Array after AdjustUp: ");
    PrintArray(a, size);
	return 0;
}