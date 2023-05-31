#include <stdio.h>
#include <stdlib.h>

#include "node.h"

struct nodeType_tag {
  keyType id;
  hash_table_client ht;
  nodeType finger_table[IDLENGTH];
};

nodeType node_create(keyType id) {
  nodeType new = malloc(sizeof *new);

  string_copy(&(new->id), id);
  new->ht = hashtable_create_client(MAXKEYNUMBER / MAXNODENUMBER);

  return new;
}

void node_free(nodeType node) {
  hashtable_destroy_client(node->ht);
  free(node->id); free(node);
}

keyType node_id(nodeType node) { return node->id; }
hash_table_client node_hashtable(nodeType node) { return node->ht; }
nodeType node_finger_at(nodeType node, size_t i) { return node->finger_table[i]; }

void node_print(nodeType node) {
  printf("Node id: %s\n", node->id);
  printf("Node hashtable:\n");
  hashtable_print_client(node->ht);
}