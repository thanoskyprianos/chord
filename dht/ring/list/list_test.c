#include "../../../acutest/acutest.h"

#include "list.h"
#include "../../node/node.h"

void test_list_push(void) {
  list_node_ring head = NULL;

  keyType ip1 = random_ip();
  nodeType node1 = node_create(ip1);
  free(ip1);

  keyType ip2 = random_ip();
  nodeType node2 = node_create(ip2);
  free(ip2);

  head = list_push_ring(node1, head);
  head = list_push_ring(node2, head);

  TEST_CHECK(list_data_ring(head) == node2);
  TEST_CHECK(list_data_ring(list_next_ring(head)) == node1);

  list_free_ring(head);
}

void test_list_find(void) {
  list_node_ring head = NULL;
  
  keyType ip1 = random_ip();
  nodeType node1 = node_create(ip1);
  free(ip1);

  keyType ip2 = random_ip();
  nodeType node2 = node_create(ip2);
  free(ip2);


  head = list_push_ring(node1, head);
  head = list_push_ring(node2, head);

  TEST_CHECK(list_find_ring(node_id(node1), head) == node1);
  TEST_CHECK(list_find_ring(node_id(node2), head) == node2);
  TEST_CHECK(list_find_ring("EMPTY", head) == NULL);

  list_free_ring(head);
}

void test_list_data(void) {
  list_node_ring head = NULL;

  keyType ip = random_ip();
  nodeType node = node_create(ip);
  free(ip);

  head = list_push_ring(node, head);

  nodeType head_data = list_data_ring(head);
  TEST_CHECK(head_data == node);

  list_free_ring(head);
}

void test_list_next(void) {
  list_node_ring head = NULL;

  keyType ip1 = random_ip();
  nodeType node1 = node_create(ip1);
  free(ip1);

  keyType ip2 = random_ip();
  nodeType node2 = node_create(ip2);
  free(ip2);

  head = list_push_ring(node1, head);
  head = list_push_ring(node2, head);

  TEST_CHECK(list_next_ring(head) != NULL);
  TEST_CHECK(list_next_ring(list_next_ring(head)) == NULL);

  list_free_ring(head);
}

TEST_LIST = {
  {"list_push", test_list_push},
  {"list_find", test_list_find},
  {"list_data", test_list_data},
  {"list_next", test_list_next},
  {NULL, NULL}
};