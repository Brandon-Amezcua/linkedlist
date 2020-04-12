//
//  list_test.c
//  linked_list
//
//  Created by William McCarthy on 084//20.
//  Copyright © 2020 William McCarthy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "slist.h"
#include "utils.h"

typedef struct list list;

//-------------------------------------------------
static void list_check_frontback(list* list, int front, int back) {
  printf("assert front of list is: %d\n", front);
  assert(list_front(list) == front);
  printf("assert back of list is: %d\n", back);
  assert(list_back(list) == back);
}

//-------------------------------------------------
static void list_test_once(list* list, int start, int end, int step, void (*fp)(struct list*, int)) {
  for (int i = start; i < end; i += step) {
    fp(list, i);
  }
  list_print(list, "list is created and is...");
  printf("list size is: %zu\n", list_size(list));
  printf("list is empty? %s\n\n", yesorno(list_empty(list)));

  int firstadded = start;
  int lastadded = start;
  while (lastadded + step < end) {
    lastadded += step;
  }
  if (fp == list_pushback)  { list_check_frontback(list, firstadded, lastadded);  }
  if (fp == list_pushfront) { list_check_frontback(list, lastadded, firstadded ); }

  list_clear(list);
  printf("after clearing the list, is the list is now empty? %s\n\n", yesorno(list_empty(list)));
}

//-------------------------------------------------
void list_test() {
  printf("\n//===================== TESTING list =========================\n\n");
  list* list = list_create();
  list_test_once(list, 10, 50, 10, list_pushfront);
  list_test_once(list, 10, 100, 20, list_pushback);

  printf("\n    All Assertions passed!...\n");
  free(list);
  printf("//===================== END TESTING list =========================\n\n");
}
