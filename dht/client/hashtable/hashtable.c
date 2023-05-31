#include <stdio.h> // delete later
#include <stdlib.h>
#include <openssl/sha.h>

#include "hashtable.h"
#include "../list/list.h"

struct hash_table_client_tag {
  size_t size; size_t item_count;
  list_node_client *table;
};

hash_table_client hashtable_create_client(int size) {
  hash_table_client new = malloc(sizeof *new);
  new->size = size; new->item_count = 0;

  new->table = malloc(size * sizeof(list_node_client *));
  for (int i = 0; i < size; i++)
    new->table[i] = NULL;

  return new;
}

void hashtable_destroy_client(hash_table_client ht) {
  for(size_t i = 0; i < ht->size; i++)
    list_free_client(ht->table[i]);
  free(ht->table); free(ht);
}

hash_table_client hashtable_insert_client(keyType key, valueType value, hash_table_client ht) {
  size_t index = hash(key) % ht->size;
  ht->table[index] = list_push_client(key, value, ht->table[index]);
  ht->item_count++;

  if(hashtable_load_factor_client(ht) > 0.75)
    ht = hashtable_resize_client(ht);

  return ht;
}

list_node_client hashtable_get_client(keyType key, hash_table_client ht) {
  size_t index = hash(key) % ht->size;
  return list_find_client(key, ht->table[index]);
}

hash_table_client hashtable_resize_client(hash_table_client ht) {
  hash_table_client new = hashtable_create_client(ht->size * 2);
  for(size_t i = 0; i < ht->size; i++) {
    list_node_client current = ht->table[i];
    while(current != NULL) {
      new = hashtable_insert_client(list_key_client(current), list_value_client(current), new);
      current = list_next_client(current);
    }
  }

  hashtable_destroy_client(ht);
  return new;
}

size_t hashtable_size_client(hash_table_client ht) { return ht->size; }
size_t hashtable_item_count_client(hash_table_client ht) { return ht->item_count; }

float hashtable_load_factor_client(hash_table_client ht) {
  return (float)hashtable_item_count_client(ht) / (float)hashtable_size_client(ht);
}

// for debugging
void hashtable_print_client(hash_table_client ht) {
  for(size_t i = 0; i < ht->size; i++) {
    printf("%zu: ", i);
    list_print_client(ht->table[i]);
    printf("\n");
  }
}