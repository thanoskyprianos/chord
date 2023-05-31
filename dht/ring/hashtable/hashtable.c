#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"
#include "../list/list.h"
#include "../../node/node.h"


struct hash_table_ring_tag {
  size_t size; size_t item_count;
  list_node_ring *table;
};

hash_table_ring hashtable_create_ring(size_t size) {
  hash_table_ring new = malloc(sizeof *new);
  new->size = size; new->item_count = 0;

  new->table = malloc(size * sizeof(list_node_ring *));
  for (size_t i = 0; i < size; i++)
    new->table[i] = NULL;

  return new;
}

void hashtable_destroy_ring(hash_table_ring ht) {
  for(size_t i = 0; i < ht->size; i++)
    list_free_ring(ht->table[i]);
  free(ht->table); free(ht);
}

hash_table_ring hashtable_insert_ring(nodeType node, hash_table_ring ht) {
  size_t index = hash(node_id(node)) % ht->size;
  ht->table[index] = list_push_ring(node, ht->table[index]);
  ht->item_count++;

  return ht;
}

nodeType hashtable_get_ring(keyType key, hash_table_ring ht) {
  size_t index = hash(key) % ht->size;
  return list_find_ring(key, ht->table[index]);
}

size_t hashtable_size_ring(hash_table_ring ht) { return ht->size; }
size_t hashtable_item_count_ring(hash_table_ring ht) { return ht->item_count; }

void hashtable_print_ring(hash_table_ring ht) {
  for(size_t i = 0; i < ht->size; i++) {
    printf("%zu: ", i);
    list_print_ring(ht->table[i]);
    printf("\n");
  }
}