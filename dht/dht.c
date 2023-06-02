#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dht.h"
#include "ring/hashtable/hashtable.h"
#include "client/list/list.h"

void sorted_insert(nodeType node, nodeType *nodes, size_t nodes_count) {
  size_t i = 0;
  while(i < nodes_count && hash(node_id(nodes[i])) < hash(node_id(node))) i++;

  for(size_t j = nodes_count; j > i; j--) nodes[j] = nodes[j - 1];
  nodes[i] = node;
}

hash_table_ring ring; // chord network
keyType ips[MAXNODENUMBER]; // ips of nodes 

void initialize(void) {
  ring = hashtable_create_ring(next_prime(MAXKEYNUMBER / MAXNODENUMBER));

  nodeType nodes[MAXNODENUMBER];
  for(int i = 0; i < MAXNODENUMBER; i++) nodes[i] = NULL;
  size_t nodes_count = 0;

  for(size_t i = 0; i < MAXNODENUMBER; i++) {
    keyType ip = random_ip();
    nodeType node = node_create(ip);
    string_copy(&(ips[i]), ip);
    free(ip);

    ring = hashtable_insert_ring(node, ring);

    sorted_insert(node, nodes, (nodes_count)++);
  }

  for(int i = 0; i < MAXNODENUMBER; i++)
    for(int j = 0; j < IDLENGTH; j++)
      node_set_finger_at(nodes[i], j, nodes[(i + (1 << j)) % MAXNODENUMBER]);
}

void terminate(void) {
  hashtable_destroy_ring(ring);
  for(int i = 0; i < MAXNODENUMBER; i++) free(ips[i]);
}

void insert(nodeType node, keyType key, valueType value) {

  nodeType successor = find_successor(node, hash(key) % hashtable_size_ring(ring));

  hashtable_insert_client(key, value, node_hashtable(successor));
}

valueType lookup(nodeType node, keyType key) {
  size_t client_index = hash(key) % hashtable_size_ring(ring);
  nodeType client = find_successor(node, client_index);

  return list_value_client(hashtable_get_client(key, node_hashtable(client)));
}

valueType smartLookup(nodeType node, keyType key) {
  size_t client_index = hash(key) % hashtable_size_ring(ring);
  nodeType client = smart_find_successor(node, client_index);

  return list_value_client(hashtable_get_client(key, node_hashtable(client)));
}