#include "../../../acutest/acutest.h"

#include "hashtable.h"
#include "../../node/node.h"

void test_hashtable_insert(void) {
  hash_table_ring ht = hashtable_create_ring(10);
  
  keyType ip1 = random_ip();
  nodeType node1 = node_create(ip1);
  free(ip1);

  keyType ip2 = random_ip();
  nodeType node2 = node_create(ip2);
  free(ip2);

  ht = hashtable_insert_ring(node1, ht);

  TEST_CHECK(hashtable_get_ring(node_id(node1), ht) == node1);

  ht = hashtable_insert_ring(node2, ht);

  TEST_CHECK(hashtable_get_ring(node_id(node2), ht) == node2);

  hashtable_destroy_ring(ht);
}

void test_hashtable_get(void) {
  hash_table_ring ht = hashtable_create_ring(10);
  
  keyType ip1 = random_ip();
  nodeType node1 = node_create(ip1);
  free(ip1);

  keyType ip2 = random_ip();
  nodeType node2 = node_create(ip2);
  free(ip2);

  ht = hashtable_insert_ring(node1, ht);
  ht = hashtable_insert_ring(node2, ht);

  TEST_CHECK(hashtable_get_ring(node_id(node1), ht) != NULL);
  TEST_CHECK(hashtable_get_ring(node_id(node2), ht) != NULL);
  TEST_CHECK(hashtable_get_ring("EMPTY", ht) == NULL);

  hashtable_destroy_ring(ht);
}

void test_hashtable_size(void) {
  hash_table_ring ht = hashtable_create_ring(10);
  TEST_CHECK(hashtable_size_ring(ht) == 10);

  hashtable_destroy_ring(ht);
}

void test_hashtable_item_count(void) {
  hash_table_ring ht = hashtable_create_ring(10);

  keyType ip1 = random_ip();
  nodeType node1 = node_create(ip1);
  free(ip1);

  keyType ip2 = random_ip();
  nodeType node2 = node_create(ip2);
  free(ip2);

  ht = hashtable_insert_ring(node1, ht);
  ht = hashtable_insert_ring(node2, ht);

  TEST_CHECK(hashtable_item_count_ring(ht) == 2);

  hashtable_destroy_ring(ht);
}

TEST_LIST = {
  { "hashtable_insert", test_hashtable_insert },
  { "hashtable_get", test_hashtable_get },
  { "hashtable_size", test_hashtable_size },
  { "hashtable_item_count", test_hashtable_item_count },
  { NULL, NULL }
};