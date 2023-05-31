#pragma once

#include <stdlib.h>

#include "../client/hashtable/hashtable.h"
#include "../../utils/utils.h"

typedef struct nodeType_tag *nodeType;

nodeType node_create(keyType id);
void node_free(nodeType node);
nodeType node_copy(nodeType node);
keyType node_id(nodeType node);
hash_table_client node_hashtable(nodeType node);
nodeType node_finger_at(nodeType node, size_t i);

void node_print(nodeType node); // for debugging