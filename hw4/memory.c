#include <stdio.h>
#include "memory.h"
#include "backend.c"
#include "backend.h"
//#include "memory.c"

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
  if (top == NULL) 
  {
      printf("Can't allocate new node. Memory pool is empty!\n");
      return NULL;
  }

    struct record *new_record = top;
    top = top->next;
    return new_record;
  printf("new_node() was not implemented.\n");
}


// Push a node to the pool.
void free_node(struct record *r)
{
  r->next=top;
  top=r;
}

