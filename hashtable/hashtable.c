#include <stdlib.h>
#include <openssl/sha.h>

#include "hashtable.h"
#include "../list/list.h"

struct hash_table_tag {
  size_t size; size_t item_count;
  list_node *table;
};

hash_table hashtable_create(int size) {
  hash_table new = malloc(sizeof *new);
  new->size = size; new->item_count = 0;

  new->table = malloc(size * sizeof(list_node *));
  for (int i = 0; i < size; i++)
    new->table[i] = NULL;

  return new;
}

void hashtable_destroy(hash_table ht) {
  for(size_t i = 0; i < ht->size; i++)
    list_free(ht->table[i]);
  free(ht->table); free(ht);
}

hash_table hashtable_insert(keyType key, valueType value, hash_table ht) {
  size_t index = hash(key) % ht->size;
  ht->table[index] = list_push(key, value, ht->table[index]);
  ht->item_count++;

  if(hashtable_load_factor(ht) > 0.75)
    ht = hashtable_resize(ht);

  return ht;
}

list_node hashtable_get(keyType key, hash_table ht) {
  size_t index = hash(key) % ht->size;
  return list_find(key, ht->table[index]);
}

hash_table hashtable_resize(hash_table ht) {
  hash_table new = hashtable_create(ht->size * 2);
  for(size_t i = 0; i < ht->size; i++) {
    list_node current = ht->table[i];
    while(current != NULL) {
      new = hashtable_insert(list_key(current), list_value(current), new);
      current = list_next(current);
    }
  }

  hashtable_destroy(ht);
  return new;
}

size_t hashtable_size(hash_table ht) { return ht->size; }
size_t hashtable_item_count(hash_table ht) { return ht->item_count; }

float hashtable_load_factor(hash_table ht) {
  return (float)hashtable_item_count(ht) / (float)hashtable_size(ht);
}

size_t hash(keyType key) {
  unsigned char hash_array[SHA_DIGEST_LENGTH];
  SHA1((unsigned char *)key, strlen(key), hash_array);
  return (size_t)hash_array[0]; // first 8 bits of SHA1 key
}