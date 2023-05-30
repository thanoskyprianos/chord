#include "../acutest/acutest.h"

#include "list.h"

void test_list_push(void) {
  list_node head = NULL;

  head = list_push("John", 1, head);
  TEST_CHECK(equal(list_key(head), "John") && list_value(head) == 1);

  head = list_push("Peter", 2, head);
  TEST_CHECK(equal(list_key(head), "Peter") && list_value(head) == 2);

  list_free(head);
}

void test_list_find(void) {
  list_node head = NULL;

  head = list_push("John", 1, head);
  head = list_push("Peter", 2, head);

  TEST_CHECK(list_find("John", head) != NULL);
  TEST_CHECK(list_find("Peter", head) != NULL);
  TEST_CHECK(list_find("George", head) == NULL);

  list_free(head);
}

void test_list_key(void) {
  list_node head = NULL;

  head = list_push("John", 1, head);
  head = list_push("Peter", 2, head);

  TEST_CHECK(equal(list_key(head), "Peter"));
  TEST_CHECK(equal(list_key(list_next(head)), "John"));

  list_free(head);
}

void test_list_value(void) {
  list_node head = NULL;

  head = list_push("John", 1, head);
  head = list_push("Peter", 2, head);

  TEST_CHECK(list_value(head) == 2);
  TEST_CHECK(list_value(list_next(head)) == 1);
  
  list_free(head);
}

void test_list_next(void) {
  list_node head = NULL;

  head = list_push("John", 1, head);
  head = list_push("Peter", 2, head);

  TEST_CHECK(list_next(head) != NULL);
  TEST_CHECK(list_next(list_next(head)) == NULL);

  list_free(head);
}

TEST_LIST = {
  {"list_push", test_list_push},
  {"list_find", test_list_find},
  {"list_key", test_list_key},
  {"list_value", test_list_value},
  {"list_next", test_list_next},
  {NULL, NULL}
};