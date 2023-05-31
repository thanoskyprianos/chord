#pragma once

#include "../../../utils/utils.h"

hash_table_client hashtable_create_client(size_t size);
void hashtable_destroy_client(hash_table_client ht);
hash_table_client hashtable_insert_client(keyType key, valueType value, hash_table_client ht);
list_node_client hashtable_get_client(keyType key, hash_table_client ht);
hash_table_client hashtable_resize_client(hash_table_client ht);

size_t hashtable_size_client(hash_table_client ht);
size_t hashtable_item_count_client(hash_table_client ht);
float hashtable_load_factor_client(hash_table_client ht);

void hashtable_print_client(hash_table_client ht); // for debugging