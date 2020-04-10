
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node node;
struct node {
  int data;
  node* next;
};

node* node_create(int data, node* next) {
  node* p = (node*)malloc(sizeof(node));
  p->data = data;
  p->next = next;

  return p;
}

typedef struct linked_list linked_list;
struct linked_list {
  node* head;
  node* tail;
  size_t size;
};

linked_list* linked_list_create() {
  linked_list* p = (linked_list*)malloc(sizeof(linked_list));
  p->head = NULL;
  p->tail = NULL;
  p->size = 0;

  return p;
}

bool linked_list_empty(linked_list* list) {return list->size == 0;}

size_t linked_list_size(linked_list* list) {return list->size;}

void linked_list_popfront(linked_list* list) {
  if (linked_list_empty(list)) { printf("List is empty\n"); return;}
  node*p = list->head;
  list->head = list->head->next;
  free(p);
  --list->size;
}

void linked_list_popback(linked_list* list) {
  if (linked_list_size(list) == 1) {linked_list_popfront(list); return;}

  node*p = list->head;
  while (p->next != list->tail) { p = p->next; }
  p->next = NULL;
  free(list->tail);
  list->tail = p;
  --list->size;
}

void linked_list_pushfront(linked_list* list, int data) {
  node* p = node_create(data, list->head);
  list->head = p;
  if (list->size == 0) { list->tail = p;}
  ++list->size;
}

void linked_list_pushback(linked_list* list, int data) {
  if (list->size == 0) {linked_list_pushfront(list, data); }
  node* p = node_create(data, NULL);
  list->tail->next = p;
  list->tail = p;
  ++list->size;
}

void linked_list_clear(linked_list* list) {
  while(!linked_list_empty(list)) {
    linked_list_popfront(list);
  }
}

void linked_list_print(linked_list* list, const char* msg) {
  printf("%s\n", msg);
  if (linked_list_empty(list)) { printf("List is empty\n"); return; }

  node* p = list->head;
  while (p != NULL) {
    printf("%d --> %p\n", p->data, p->next);
    p = p->next;
  }
}

int linked_list_front(linked_list* list) {
  if (linked_list_empty(list)) { printf(stderr, "List is empty\n"); exit(1);}
  return list->head->data;
}

int linked_list_back(linked_list* list) {
  if (linked_list_empty(list)) { printf(stderr, "List is empty\n"); exit(1);}
  return list->tail->data;
}

void linked_list_test() {
  linked_list* list = linked_list_create();
  for (int i = 10; i < 50; i += 10) {
    linked_list_pushfront(list, i);
  }
  linked_list_print(list, "list is created and is ...");
  printf("list size is: %zu\n", linked_list_size(list));
  printf("list is empty? %d\n", linked_list_empty(list));


}

int main(int argc, const char* argv[]) {

  linked_list_test;
  return 0;
}
