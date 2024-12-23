#include <stdio.h>
#include <stdlib.h>  // qsort
#include <string.h>  // strncmp
#include "backend2.h"     

#define NUMBER_OF_RECORDS 20

// record structure
struct record {
  char name[3];
  char number[4];
};

// Declaration of the array for the main data
struct record data[NUMBER_OF_RECORDS];

// index of the first empty slot
int k=0;  

// Declaration of functions visible only in this file.
int cmp_record(const void *, const void *);
int search_index(char [3]);
void print_name(int);
void print_number(int);
void print_data(char *, int);


void add(char *name, char *number)
{
  if (k<NUMBER_OF_RECORDS) {
    data[k].name[0]=name[0];
    data[k].name[1]=name[1];
    data[k].name[2]=name[2];
    data[k].number[0]=number[0];
    data[k].number[1]=number[1];
    data[k].number[2]=number[2];
    data[k].number[3]=number[3];
    print_name(k);
    printf(" : ");
    print_number(k);
    printf(" was successfully added!\n");
    k++;
  }
  else
    printf("Can't add.  Address book is full.\n");
}


// Returns the index of the found index.
// Returns -1, if not found.
int search_index(char name[3])  
{
    for (int i = 0; i < k; i++)
    {
        if (strncmp(data[i].name, name, 3) == 0)
            //strncmp是一个比较函数
            //在这个代码里面来比较data[i].name和name两个字符串的前三个字符是否相同
            //如果相同，strncmp函数返回0，条件成立，执行return
            return i;
    }
  printf("Search was not implemented yet.\n");
  return -1;
  //这个是作业已经完成。
}


void search(char name[3])  
{
  int s_result;

  s_result=search_index(name);
  if (s_result==-1) 
    printf("Couldn't find the name.\n");
  else {
    print_name(s_result);
    printf(" : ");
    print_number(s_result);
    printf(" was found.\n");
  }
}


void delete(char name[3])
{
    int index = search_index(name);
    if (index != -1)
    {
        for (int i = index; i < k; i++)
        {
            strcpy(data[i].name,data[i + 1].name);
            strcpy(data[i].number, data[i + 1].number);
            //strcpy是覆盖的意思
            //简单说就是i+1的元素把i+给覆盖了
            //然后k--，就删除了
        }
        k--;
    }
    else
    {
        // Use search_index()
        printf("Deletion was not implemented yet.\n");
    }
}


void sort_list()
{

    qsort(data, k, sizeof(struct record), cmp_record);

/*   qsort(array, array_size, sizeof(struct record),  */
/* 	(int (*)(const void*, const void*))cmp_record); */

  // The message for command 'T'.
  printf("Address Book is sorted now!\n");
}

int cmp_record(const void *r1, const void *r2)
{
  struct record * x = (struct record *) r1;
  struct record * y = (struct record *) r2;
  //在这个比较的意思是根据ASCLL值来排序
  // 成员的前三个字符在字典顺序来比较
  //如果r1<r2，返回负值
  //如果r1=r2，返回0
  //如果r1>r2，返回1
  return strncmp(x->name, y->name, 3);
}


void print_list()
{
  int i;
  for (i=0; i<k; i++) {
    print_name(i);
    printf(" : ");
    print_number(i);
    printf("\n");
  }
}

// Prints ith name.
void print_name(int i)
{
  print_data(data[i].name, 3);
}

// Prints ith number.
void print_number(int i)
{
  print_data(data[i].number, 4);
}

void print_data(char * s, int n)
{
  int i;
  for (i=0; i<n; i++)
    putchar(s[i]);
}

