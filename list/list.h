#pragma once

#include "../utils/utils.h"

void list_free(list_node head); /* frees a list */
list_node list_push(keyType key, valueType value, list_node head); /* prepends an item on the list */
list_node list_find(keyType key, list_node head); /* finds element on list */

keyType list_key(list_node node); /* returns key of node */
valueType list_value(list_node node); /* returns value of node */
list_node list_next(list_node node); /* returns next node */