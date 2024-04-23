#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"
#include "memory.h"

void print_name(struct record *);
void print_number(struct record *);
void print_data(char *, int);

// data
struct record * data = NULL; // Initially NULL.


void init()
{
  init_pool();
}


void add(char *name, char *number)
{
    struct record* new_record = new_node();
    if (new_record == NULL)
    {
        printf("add() was not implemented.\n");
        return 0;
    }
    else
    {
        strucpy(new_record->name,name, 3);
        strucpy(new_record->number, number, 4);
        new_record->next = data;
        data = new_record;

    }

  printf("add() was not implemented.\n");
  // Error Message for overflow:
  // printf("Can't add.  The address book is full!\n");
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
  printf("delete() is not implemented.\n");
  // Error Message:
  // printf("Couldn't find the name.\n");
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
  printf("print_list() was not implemented.\n");
}
