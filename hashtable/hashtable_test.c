#include "../acutest/acutest.h"

#include "../hashtable/hashtable.h"
#include "../list/list.h"

void test_hashtable_insert(void) {
  hash_table ht = hashtable_create(10);

  ht = hashtable_insert("John", 1, ht);
  TEST_CHECK(list_value(hashtable_get("John", ht)) == 1);

  ht = hashtable_insert("Peter", 2, ht);
  TEST_CHECK(list_value(hashtable_get("Peter", ht)) == 2);

  hashtable_destroy(ht);
}

void test_hashtable_get(void) {
  hash_table ht = hashtable_create(10);

  ht = hashtable_insert("John", 1, ht);
  ht = hashtable_insert("Peter", 2, ht);

  list_node n1 = hashtable_get("John", ht);
  list_node n2 = hashtable_get("Peter", ht);
  list_node n3 = hashtable_get("George", ht);

  TEST_CHECK(n1 != NULL && equal(list_key(n1), "John") && list_value(n1) == 1);
  TEST_CHECK(n2 != NULL && equal(list_key(n2), "Peter") && list_value(n2) == 2);
  TEST_CHECK(n3 == NULL);

  hashtable_destroy(ht);
}

void test_hashtable_resize(void) {
  hash_table ht = hashtable_create(10);

  ht = hashtable_insert("John", 1, ht);
  ht = hashtable_insert("Peter", 2, ht);

  TEST_CHECK(hashtable_size(ht) == 10 && hashtable_item_count(ht) == 2);

  ht = hashtable_resize(ht);

  TEST_CHECK(hashtable_size(ht) == 20 && hashtable_item_count(ht) == 2);

  list_node n1 = hashtable_get("John", ht);
  list_node n2 = hashtable_get("Peter", ht);

  TEST_CHECK(n1 != NULL && equal(list_key(n1), "John") && list_value(n1) == 1);
  TEST_CHECK(n2 != NULL && equal(list_key(n2), "Peter") && list_value(n2) == 2);

  hashtable_destroy(ht);
}

void test_hashtable_size(void) {
  hash_table ht = hashtable_create(10);
  TEST_CHECK(hashtable_size(ht) == 10);

  hashtable_destroy(ht);
}

void test_hashtable_item_count(void) {
  hash_table ht = hashtable_create(10);

  ht = hashtable_insert("John", 1, ht);
  ht = hashtable_insert("Peter", 2, ht);

  TEST_CHECK(hashtable_item_count(ht) == 2);

  hashtable_destroy(ht);
}

void test_hash(void) {
  size_t hash1 = hash("John");
  char c = (char)hash1;

  TEST_CHECK((size_t)c == hash1);
}

TEST_LIST = {
  { "hashtable_insert", test_hashtable_insert },
  { "hashtable_get", test_hashtable_get },
  { "hashtable_resize", test_hashtable_resize },
  { "hashtable_size", test_hashtable_size },
  { "hashtable_item_count", test_hashtable_item_count },
  { "hash", test_hash },
  { NULL, NULL }
};