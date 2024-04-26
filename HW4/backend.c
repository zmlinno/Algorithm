#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"
#include "memory.h"
//#define _CRT_SECURE_NO_WARNINGS

void print_name(struct record *);
void print_number(struct record *);
void print_data(char *, int);


// comparison function for records
int compare(char key[3], struct record *);

// data
struct record * data = NULL; // Initially NULL.


void init()
{
  init_pool();
}
//
//struct record* new_record()
//{
//    struct record* new_record = (struct record*)malloc(sizeof(new_record));
//
//    if (new_record != NULL)
//    {
//        new_record->next = NULL;
//        new_record->name[0] = '\0';
//        new_record->number[0] = '\0';
//    }
//    return new_record;
//}


void add(char *name, char *number)
{
    struct record* newRecord = new_node();
    if (newRecord == NULL)
    {
        printf("Cat't add.Thr address book is full!\n");
        return;
    }

    strncpy_s(newRecord->name,4, name, 3);
    strncpy_s(newRecord->number,5, number, 4);
    newRecord->next = NULL;

    if (data == NULL)
    {
        data = newRecord;
    }
    else
    {
        struct record* current = data;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newRecord;
    }
  printf("add() was not implemented.\n");
  // Error Message for overflow:
  // printf("Can't add.  The address book is full!\n");
}


void search(char name[3])  
{
  struct record *r=data;
  int result;

  while(r!=NULL && (result=compare(name,r))!=0)
    r=r->next;
  if(r==NULL)
    printf("Couldn't find the name.\n");
  else {
    print_name(r);
    printf(" : ");
    print_number(r);
    printf(" was found.\n");
  }
}


void delete(char name[3])
{
    struct record* prev = NULL;
    struct record* current = data;

    while (current != NULL)
    {
        if (strncmp(name, current->name, 3) == 0)
        {
            if (prev != NULL)
            {
                prev->next = current->next;
            }
            else
            {
                data = current->next;
            }
            free_node(current);
            return;
        }
        prev = current;
        current = current->next;
    }
  printf("delete() is not implemented.\n");
  // Error Message:
  // printf("Couldn't find the name.\n");
}


/* Just a wrapper of strncmp(), except for the case r is NULL. 
Regard strncmp(a,b) as a-b, that is,
Negative value if key is less than r.
​0​ if key and r are equal.
Positive value if key is greater than r. */
int compare(char key[3], struct record *r)
{
  if (r==NULL)  
    return -1;
  else
    return strncmp(key, r->name, 3);
}

// Prints ith name.
void print_name(struct record *r)
{
  print_data(r->name, 3);
}

// Prints ith number.
void print_number(struct record *r)
{
  print_data(r->number, 4);
}

void print_data(char * s, int n)
{
  int i;
  for (i=0; i<n; i++)
    putchar(s[i]);
}

void print_list()
{
    struct record* current = data;
    while (current != NULL)
    {
        printf(" : ");
        print_number(current);
        printf("\n");
        current = current->next;
    }
  printf("print_list() was not implemented.\n");
}

