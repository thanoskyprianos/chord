#pragma once

#include "../../../utils/utils.h"

void list_free_client(list_node_client head);
list_node_client list_push_client(keyType key, valueType value, list_node_client head);
list_node_client list_find_client(keyType key, list_node_client head);

keyType list_key_client(list_node_client node);
valueType list_value_client(list_node_client node);
list_node_client list_next_client(list_node_client node);

void list_print_client(list_node_client head); // for debugging