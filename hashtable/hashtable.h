#pragma once

#include "../utils/utils.h"

hash_table hashtable_create(int size);
void hashtable_destroy(hash_table ht);
hash_table hashtable_insert(keyType key, valueType value, hash_table ht);
list_node hashtable_get(keyType key, hash_table ht);
hash_table hashtable_resize(hash_table ht);

size_t hashtable_size(hash_table ht);
size_t hashtable_item_count(hash_table ht);
float hashtable_load_factor(hash_table ht);

size_t hash(keyType key);