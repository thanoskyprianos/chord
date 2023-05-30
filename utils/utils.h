#pragma once

#include <string.h>

#define MAXNODENUMBER 256 // 2^8 -> 8 bit key
#define equal(a, b) (strcmp(a, b) == 0)

typedef char *keyType;
typedef int valueType;
typedef struct nodeType_tag *nodeType;

typedef struct hash_table_tag *hash_table;

typedef struct list_node_tag *list_node;