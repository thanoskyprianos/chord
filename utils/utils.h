#pragma once

#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAXNODENUMBER 256  // 2^8 -> 8 bit key
#define IDLENGTH 8         // 8 bits
#define MAXKEYNUMBER 65536 // 256^2

#define EMPTY INT_MIN

#define equal(a, b) (strcmp(a, b) == 0)

typedef char *keyType;
typedef int valueType;

typedef struct hash_table_client_tag *hash_table_client;
typedef struct hash_table_ring_tag *hash_table_ring;

typedef struct list_node_client_tag *list_node_client;
typedef struct list_node_ring_tag *list_node_ring;

void string_copy(char **dest, char *src);
keyType random_ip(void);
size_t hash(keyType key);
bool is_prime(size_t n);
size_t next_prime(size_t n);

#define CYAN "\033[0;96m"
#define RED "\033[0;91m"
#define GREEN "\033[0;92m"
#define RESET "\033[0m"

#define CLIENTS_PER_SCREEN 16

void clear_previous_input(void);
void clear_screen(void);
void wait_for_enter(void);