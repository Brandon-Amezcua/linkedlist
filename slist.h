
#ifndef slist_h
#define slist_h

#include <stdio.h>
#include <stdbool.h>


//-------------------------------------------------
typedef struct node node;
struct node {
  int data;
  node* prev;
  node* next;
};

typedef struct list list;
struct list {
  node* head;
  node* tail;
  size_t size;
};

//-------------------------------------------------
node* node_create(int data, node* next);
list* list_create(void);

bool list_empty(list* list);
size_t list_size(list* list);

void list_popfront(list* list);
void list_popback(list* list);

void list_pushfront(list* list, int data);
void list_pushback(list* list, int data);

void list_clear(list* list);
void list_print(list* list, const char* msg);

int list_front(list* list);
int list_back(list* list);

void list_test(void);


#endif /* dlist_h */
