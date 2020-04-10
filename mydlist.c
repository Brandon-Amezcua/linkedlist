
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node node;
struct node {
  int data;
  node* next;
  node* prev;
};

node* node_create(int data, node* next, node* prev) {
  node* p = (node*)malloc(sizeof(node));
  p->data = data;
  p->next = next;
  p->prev = prev;

  return p;
}

typedef struct dlist dlist;
struct dlist {
  node* head;
  node* tail;
  size_t size;
};

dlist* dlist_create() {
  dlist* p = (dlist*)malloc(sizeof(dlist));
  p->head = NULL;
  p->tail = NULL;
  p->size = 0;

  return p;
}

bool dlist_empty(dlist* list) {return list->size == 0;}

size_t dlist_size(dlist* list) {return list->size;}

void dlist_popfront(dlist* list) {
  if (dlist_empty(list)) { printf("List is empty\n"); return;}
  node*p = list->head;
  list->head = list->head->next;
  list->head->prev = NULL;
  free(p);
  --list->size;
}

void dlist_popback(dlist* list) {
  if (dlist_size(list) == 1) {dlist_popfront(list); return;}

  node*p = list->head;
  while (p->next != list->tail) { p = p->next; }
  p->next = NULL;
  free(list->tail);
  list->tail = p;
  --list->size;
}

void dlist_pushfront(dlist* list, int data) {
  node* p = node_create(data, list->head, NULL);
  list->head = p;
  if (list->size == 0) { list->tail = p;}
  ++list->size;
}

void dlist_pushback(dlist* list, int data) {
  if (list->size == 0) {dlist_pushfront(list, data); }
  node* p = node_create(data, NULL, list->tail->prev);
  list->tail->next = p;
  list->tail = p;
  ++list->size;
}

void dlist_clear(dlist* list) {
  while(!dlist_empty(list)) {
    dlist_popfront(list);
  }
}

void dlist_print(dlist* list, const char* msg) {
  printf("%s\n", msg);
  if (dlist_empty(list)) { printf("List is empty\n"); return; }

  node* p = list->head;
  while (p != NULL) {
    printf("%d --> %p\n", p->data, p->next);
    p = p->next;
  }
}

int dlist_front(dlist* list) {
  if (dlist_empty(list)) { printf(stderr, "List is empty\n"); exit(1);}
  return list->head->data;
}

int dlist_back(dlist* list) {
  if (dlist_empty(list)) { printf(stderr, "List is empty\n"); exit(1);}
  return list->tail->data;
}

void dlist_test() {
  dlist* list = dlist_create();
  for (int i = 10; i < 50; i += 10) {
    dlist_pushfront(list, i);
  }
  dlist_print(list, "list is created and is ...");
  printf("list size is: %zu\n", dlist_size(list));
  printf("list is empty? %d\n", dlist_empty(list));


}

int main(int argc, const char* argv[]) {

  dlist_test;
  return 0;
}
