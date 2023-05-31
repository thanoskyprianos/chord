#include "../../../acutest/acutest.h"

#include "list.h"

void test_list_push(void) {
  list_node_client head = NULL;

  head = list_push_client("John", 1, head);
  TEST_CHECK(equal(list_key_client(head), "John") && list_value_client(head) == 1);

  head = list_push_client("Peter", 2, head);
  TEST_CHECK(equal(list_key_client(head), "Peter") && list_value_client(head) == 2);

  list_free_client(head);
}

void test_list_find(void) {
  list_node_client head = NULL;

  head = list_push_client("John", 1, head);
  head = list_push_client("Peter", 2, head);

  TEST_CHECK(list_find_client("John", head) != NULL);
  TEST_CHECK(list_find_client("Peter", head) != NULL);
  TEST_CHECK(list_find_client("George", head) == NULL);

  list_free_client(head);
}

void test_list_key(void) {
  list_node_client head = NULL;

  head = list_push_client("John", 1, head);
  head = list_push_client("Peter", 2, head);

  TEST_CHECK(equal(list_key_client(head), "Peter"));
  TEST_CHECK(equal(list_key_client(list_next_client(head)), "John"));

  list_free_client(head);
}

void test_list_value(void) {
  list_node_client head = NULL;

  head = list_push_client("John", 1, head);
  head = list_push_client("Peter", 2, head);

  TEST_CHECK(list_value_client(head) == 2);
  TEST_CHECK(list_value_client(list_next_client(head)) == 1);
  
  list_free_client(head);
}

void test_list_next(void) {
  list_node_client head = NULL;

  head = list_push_client("John", 1, head);
  head = list_push_client("Peter", 2, head);

  TEST_CHECK(list_next_client(head) != NULL);
  TEST_CHECK(list_next_client(list_next_client(head)) == NULL);

  list_free_client(head);
}

TEST_LIST = {
  {"list_push", test_list_push},
  {"list_find", test_list_find},
  {"list_key", test_list_key},
  {"list_value", test_list_value},
  {"list_next", test_list_next},
  {NULL, NULL}
};