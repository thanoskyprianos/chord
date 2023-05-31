#pragma once

#include "../../../utils/utils.h"
#include "../../node/node.h"

hash_table_ring hashtable_create_ring(size_t size);
void hashtable_destroy_ring(hash_table_ring ht);
hash_table_ring hashtable_insert_ring(nodeType node, hash_table_ring ht);
nodeType hashtable_get_ring(keyType key, hash_table_ring ht);

size_t hashtable_size_ring(hash_table_ring ht);
size_t hashtable_item_count_ring(hash_table_ring ht);

void hashtable_print_ring(hash_table_ring ht); // for debugging