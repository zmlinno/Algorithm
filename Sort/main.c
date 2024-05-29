//
//  main.c
//  Sort
//
//  Created by 张木林 on 5/28/24.
//

#include <stdio.h>

//插入排序
void insertionSort(int arr[],int n)
{
    for(int i = 1;i<n;i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j = j-1;
            
        }
        arr[j+1] = key;
        
    }
}

int partition(int arr[],int low,int high)
{
    int pviot = arr[high];
    int i = low-1;
    for(int j = low;j<=high-1;j++)
    {
        if(arr[j]<pviot)
        {
            i++;
            int temp = arr[j];
            arr[i] = arr[j];
            arr[j] = temp;
            
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return(i+1);
}

//快速排序
void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);
        partition(arr,low,pi-1);
        partition(arr,pi+1,high);
    }
}



//选择排序
void selectionSort(int arr[],int n)
{
    for(int i = 0;i<n-1;i++)
    {
        int mix_idx = i;
        for(int j = i+1;i<n;i++)
        {
            if(arr[j] < mix_idx)
            {
                mix_idx = j;
            }
        }
        if(mix_idx != i)
        {
            
        }
    }
}



//冒泡排序
void bubbleSort(int arr[],int n)
{
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0;j < n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                //交换arr[j]和arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



//希尔排序
void shellSort(int arr[],int n)
{
    for(int gap = n/2;gap>0;gap /= 2 )
    {
        for(int i = gap;i<n;i++)
        {
            int temp = arr[i];
            
            int j;
            for(j = i;j>=gap && arr[j-gap] > temp; j -= gap)
            {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}
void printArray(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main()
{
    int arr[]= {2,3,1,9,7,10,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("排序前的数组:\n");
    printArray(arr,n);
    
    //排序后的数组
    printf("插入排序后的数组:\n");
    insertionSort(arr, n);
    
    printArray(arr,n);
    
    
    int arr1[] = {2,3,1,9,7,10,8};
    //快排
    quickSort(arr1,0,n-1);
    printf("快排排序后的数组:\n");
    printArray(arr1, n);
    
    
    //冒泡排序
    int arr2[] = {2,3,1,9,7,10,8};
    bubbleSort(arr,n);
    printf("冒泡排序排序后的数组:\n");
    printArray(arr2, n);
    
    
    //选择排序
    int arr3[] = {2,3,1,9,7,10,8};
    selectionSort(arr, n);
    printf("选择排序排序后的数组:\n");
    printArray(arr3, n);
    
    
    //希尔排序
    int arr4[] = {2,3,1,9,7,10,8};
    shellSort(arr, n);
    printf("希尔排序排序后的数组:\n");
    printArray(arr4, n);
    return 0;
}
