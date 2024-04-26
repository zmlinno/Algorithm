#include <stdio.h>
#include "memory.h"

#define POOL_SIZE 10

// pool of memory
struct record pool[POOL_SIZE]; 
struct record * top=pool;  // pool is constant; a pointer to the stack top.

void init_pool() // Initialize the pool
{
  int i;
  struct record *r=pool;
  struct record *s;

  pool[POOL_SIZE-1].next=NULL;  

  for(i=1;i<POOL_SIZE;i++) { 
    s=r++;
    s->next=r;
  }
}


// Gets a node from the pool. Returns NULL if pool is empty. (A BETTER DESIGN)
struct record * new_node()  
{
    struct record* new_record = (struct record*)malloc(sizeof(new_record));

    if (new_record != NULL)
    {
        new_record->next = NULL;
        new_record->name[0] = '\0';
        new_record->number[0] = '\0';
    }
    return new_record;
  printf("new_node() was not implemented.\n");
}


// Push a node to the pool.
void free_node(struct record *r)
{
  r->next=top;
  top=r;
}

