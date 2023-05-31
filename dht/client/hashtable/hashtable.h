#pragma once

#include "../../../utils/utils.h"

hash_table_client hashtable_create_client(int size); /* creates a hashtable */
void hashtable_destroy_client(hash_table_client ht); /* frees a hashtable */
hash_table_client hashtable_insert_client(keyType key, valueType value, hash_table_client ht); /* inserts an item on the hashtable */
list_node_client hashtable_get_client(keyType key, hash_table_client ht); /* finds element on hashtable */
hash_table_client hashtable_resize_client(hash_table_client ht); /* resizes hashtable */

size_t hashtable_size_client(hash_table_client ht); /* returns the size of the hashtable */
size_t hashtable_item_count_client(hash_table_client ht); /* returns the number of items in the hashtable */
float hashtable_load_factor_client(hash_table_client ht); /* returns the load factor of the hashtable */

void hashtable_print_client(hash_table_client ht); /* prints hashtable */