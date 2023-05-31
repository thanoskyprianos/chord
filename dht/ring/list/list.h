#pragma once

#include "../../node/node.h"

void list_free_ring(list_node_ring head);
list_node_ring list_push_ring(nodeType node, list_node_ring head);
nodeType list_find_ring(keyType key, list_node_ring head);

nodeType list_data_ring(list_node_ring node);
list_node_ring list_next_ring(list_node_ring node);

void list_print_ring(list_node_ring head);