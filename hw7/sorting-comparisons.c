#include <stdio.h>

#define NN 25600  // big enough for buffer in mergesort and data0.
int C1, C2;  // number of comparisons and writings

void merge(int arr[], int l, int m, int r);
void mergesort(int arr[], int l, int r);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);

void testSortAlgorithms(int data[], int n);
void merge(int arr[], int l, int m, int r) // l<m<r
{
  int b[NN+1];  // buffer to store two sublists. 
  int i,j,k;

  // copy sublists to buffer
  for (i=l; i<=r; i++)
    {b[i]=arr[i];  C2++;}
  
  i=l; j=m+1; k=l; // reset indices.
  
  // merge sublists in buffer into arr[]
  while (i<=m && j<=r) {
    if (b[i]<=b[j]) 
      {arr[k++]=b[i++]; C2++;}
    else
      {arr[k++]=b[j++]; C2++;}
    C1++;
  }
  if (i>m)
    while (j<=r)
      {arr[k++]=b[j++]; C2++;}
  else
    while (i<=m)
      {arr[k++]=b[i++]; C2++;}
}

void mergesort(int arr[], int l, int r)
{
  int m;

  if (l < r) {
    m = (l+r)/2;
    mergesort(arr, l, m);
    mergesort(arr, m+1, r);
    merge(arr, l, m, r);
  }
}

void selectionSort(int arr[],int n)
{
  for(int i = 0;i<n-1;i++)
  {
    int min_idx = i;
    for(int j = i+1;j<n;j++)
    {
      C1++;
      if(arr[j] < arr[min_idx])
      {
        min_idx = 1;
      }
      if(min_idx != i)
      {
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        C2 += 3;
      }
    }
  }
}



void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        C2++; 
        while (j >= 0 && arr[j] > key) {
            C1++;
            arr[j + 1] = arr[j];
            C2++; 
            j = j - 1;
        }
        arr[j + 1] = key;
        C2++; 
    }
}



int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    C2++; 
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        C1++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            C2 += 3; 
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    C2 += 3; // 
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{
  int i, j;
  int data0[NN];

  int N[10];
  N[1]= 100;
  N[2]= 200;
  N[3]= 300;
  N[4]= 400;
  N[5]= 500;
  N[6]= 600;
  N[7]= 700;
  N[8]= 800;
  N[9]= 900;


  //printf("\n** Merge Sort **\n");
  printf("\n** quickSort **\n");
  //printf("\n** insertionSort **\n");

  
  for (i=1; i<10; i++) {  
    //read N[i] data
    for (j=0; j<N[i]; j++) {
      scanf("%d", &data0[j]); // read the input 
    }
    C1=C2=0;
    quickSort(data0,0,N[i]-1);
    
    printf("n = %d; C1 = %d; C2 = %d.\n", N[i], C1, C2);

    // printf("\n** quickSort **");
    // quickSort(data0,0,N[i]-1);
    // printf("n = %d; C1 = %d; C2 = %d.\n", N[i], C1, C2);
  }

}
