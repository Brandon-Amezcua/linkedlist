
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "slist.h"

node* node_create(int data, node* next) {
  node* p = (node*)malloc(sizeof(node));
  p->data = data;
  p->next = next;

  return p;
}

list* list_create() {
  list* p = (list*)malloc(sizeof(list));
  p->head = NULL;
  p->tail = NULL;
  p->size = 0;

  return p;
}

bool list_empty(list* list) {return list->size == 0;}

size_t list_size(list* list) {return list->size;}

void list_popfront(list* list) {
  if (list_empty(list)) { printf("List is empty\n"); return;}
  node*p = list->head;
  list->head = list->head->next;
  free(p);
  --list->size;
}

void list_popback(list* list) {
  if (list_size(list) == 1) {list_popfront(list); return;}

  node*p = list->head;
  while (p->next != list->tail) { p = p->next; }
  p->next = NULL;
  free(list->tail);
  list->tail = p;
  --list->size;
}

void list_pushfront(list* list, int data) {
  node* p = node_create(data, list->head);
  list->head = p;
  if (list->size == 0) { list->tail = p;}
  ++list->size;
}

void list_pushback(list* list, int data) {
  if (list->size == 0) {list_pushfront(list, data); }
  node* p = node_create(data, NULL);
  list->tail->next = p;
  list->tail = p;
  ++list->size;
}

void list_clear(list* list) {
  while(!list_empty(list)) {
    list_popfront(list);
  }
}

void list_print(list* list, const char* msg) {
  printf("%s\n", msg);
  if (list_empty(list)) { printf("List is empty\n"); return; }

  node* p = list->head;
  while (p != NULL) {
    printf("%d --> %p\n", p->data, p->next);
    p = p->next;
  }
}

int list_front(list* list) {
  if (list_empty(list)) { printf(stderr, "List is empty\n"); exit(1);}
  return list->head->data;
}

int list_back(list* list) {
  if (list_empty(list)) { printf(stderr, "List is empty\n"); exit(1);}
  return list->tail->data;
}
