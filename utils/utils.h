#pragma once

#include <string.h>

#define MAXNODENUMBER 256  // 2^8 -> 8 bit key
#define IDLENGTH 8         // 8 bits
#define MAXKEYNUMBER 65536 // 256^2

#define equal(a, b) (strcmp(a, b) == 0)

typedef char *keyType;
typedef int valueType;
typedef struct nodeType_tag *nodeType;

typedef struct hash_table_client_tag *hash_table_client;
typedef struct hash_table_ring_tag *hash_table_ring;

typedef struct list_node_client_tag *list_node_client;
typedef struct list_node_ring_tag *list_node_ring;

void string_copy(char **dest, char *src); /* copies src to dest */
char *random_ip(void);                    /* returns a random ip */
size_t hash(keyType key);                 /* returns the hash of the key */