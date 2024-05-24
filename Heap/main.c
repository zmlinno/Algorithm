//
//  main.c
//  Heap
//
//  Created by 张木林 on 5/24/24.
//


#include <stdio.h>
#include <assert.h>
void HeapSort(int* a, int n);
void BuildHeap(int* a,int n);
void Heapify(int* a, int n, int i);

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int* a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    
    if (left < n && a[left] > a[largest])
        largest = left;

    
    if (right < n && a[right] > a[largest])
        largest = right;

    
    if (largest != i) {
        
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        
        Heapify(a, n, largest);
    }
}

void BuildHeap(int* a,int n)
{
    int startIdx = n/2-1;
    
    for(int i = startIdx; i>=0;i--)
    {
        Heapify(a, n, i);
    }
}
//void HeapSort(int* a, int n)
//{
//   // assert(a);
//    BuildHeap(a, n);
//    for(int i = n-1;i>0;i--)
//    {
//        int temp = a[0];
//        a[0] = a[i];
//        a[i] = temp;
//        Heapify(a, i, 0);
//    }
//    
//}

void HeapSort(int* a,int n)
{
    BuildHeap(a, n);
    for(int i = n-1;i>0;i--)
    {
        swap(&a[0],&a[i]);
        Heapify(a, i, 0);
    }
}

void printArray(int* a,int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);

    HeapSort(a, n);

//    printf("Sorted array is \n");
//    for (int i = 0; i < n; i++)
//    printf("%d ", a[i]);
//    printf("\n");
    
    printf("Sorted array is\n");
    printArray(a,n);

    return 0;
}
