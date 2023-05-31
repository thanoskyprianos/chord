#include "../../../acutest/acutest.h"

#include "../hashtable/hashtable.h"
#include "../list/list.h"

void test_hashtable_insert(void) {
  hash_table_client ht = hashtable_create_client(10);

  ht = hashtable_insert_client("John", 1, ht);
  TEST_CHECK(list_value_client(hashtable_get_client("John", ht)) == 1);

  ht = hashtable_insert_client("Peter", 2, ht);
  TEST_CHECK(list_value_client(hashtable_get_client("Peter", ht)) == 2);

  hashtable_destroy_client(ht);
}

void test_hashtable_get(void) {
  hash_table_client ht = hashtable_create_client(10);

  ht = hashtable_insert_client("John", 1, ht);
  ht = hashtable_insert_client("Peter", 2, ht);

  list_node_client n1 = hashtable_get_client("John", ht);
  list_node_client n2 = hashtable_get_client("Peter", ht);
  list_node_client n3 = hashtable_get_client("George", ht);

  TEST_CHECK(n1 != NULL && equal(list_key_client(n1), "John") && list_value_client(n1) == 1);
  TEST_CHECK(n2 != NULL && equal(list_key_client(n2), "Peter") && list_value_client(n2) == 2);
  TEST_CHECK(n3 == NULL);

  hashtable_destroy_client(ht);
}

void test_hashtable_resize(void) {
  hash_table_client ht = hashtable_create_client(10);

  ht = hashtable_insert_client("John", 1, ht);
  ht = hashtable_insert_client("Peter", 2, ht);

  TEST_CHECK(hashtable_size_client(ht) == 10 && hashtable_item_count_client(ht) == 2);

  ht = hashtable_resize_client(ht);

  TEST_CHECK(hashtable_size_client(ht) == 20 && hashtable_item_count_client(ht) == 2);

  list_node_client n1 = hashtable_get_client("John", ht);
  list_node_client n2 = hashtable_get_client("Peter", ht);

  TEST_CHECK(n1 != NULL && equal(list_key_client(n1), "John") && list_value_client(n1) == 1);
  TEST_CHECK(n2 != NULL && equal(list_key_client(n2), "Peter") && list_value_client(n2) == 2);

  hashtable_destroy_client(ht);
}

void test_hashtable_size(void) {
  hash_table_client ht = hashtable_create_client(10);
  TEST_CHECK(hashtable_size_client(ht) == 10);

  hashtable_destroy_client(ht);
}

void test_hashtable_item_count(void) {
  hash_table_client ht = hashtable_create_client(10);

  ht = hashtable_insert_client("John", 1, ht);
  ht = hashtable_insert_client("Peter", 2, ht);

  TEST_CHECK(hashtable_item_count_client(ht) == 2);

  hashtable_destroy_client(ht);
}

TEST_LIST = {
  { "hashtable_insert", test_hashtable_insert },
  { "hashtable_get", test_hashtable_get },
  { "hashtable_resize", test_hashtable_resize },
  { "hashtable_size", test_hashtable_size },
  { "hashtable_item_count", test_hashtable_item_count },
  { NULL, NULL }
};