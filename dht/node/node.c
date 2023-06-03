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

nodeType find_successor(nodeType node, size_t id) {
  if(id > hash(node->id) && id <= hash(node->finger_table[0]->id))
    return node->finger_table[0];

  return find_successor(node->finger_table[0], id);
}

nodeType closest_preceding_node(nodeType node, size_t id) {
  for(int i = IDLENGTH - 1; i >= 0; i--) {
    size_t finger_id = hash(node->finger_table[i]->id);

    if(finger_id > hash(node->id) && finger_id < id)
      return node->finger_table[i];
  }

  return node->finger_table[0]; // range skipped, start from next node
}

nodeType smart_find_successor(nodeType node, size_t id) {
  if(id > hash(node->id) && id <= hash(node->finger_table[0]->id))
    return node->finger_table[0];

  nodeType next = closest_preceding_node(node, id);
  return smart_find_successor(next, id);
}


keyType node_id(nodeType node) { return node->id; }
hash_table_client node_hashtable(nodeType node) { return node->ht; }
nodeType node_finger_at(nodeType node, size_t i) { return node->finger_table[i]; }
void node_set_finger_at(nodeType node, size_t i, nodeType finger) { node->finger_table[i] = finger; }

void node_print(nodeType node) {
  printf("Node id: %s\n", node->id);
  printf("Node hashtable:\n");
  hashtable_print_client(node->ht);
}