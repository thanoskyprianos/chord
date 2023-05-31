#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "../../node/node.h"

struct list_node_ring_tag {
  nodeType node;
  list_node_ring next; 
};

void list_free_ring(list_node_ring head) {
  while(head != NULL) {
    list_node_ring current = head;
    head = head->next;
    node_free(current->node); free(current);
  }
}

list_node_ring list_push_ring(nodeType node, list_node_ring head) {
  nodeType search = list_find_ring(node_id(node), head);
  if(search != NULL) {
    printf("Node with id %s already exists\n", node_id(node));
    return head; // already exists, do nothing
  }

  list_node_ring new = malloc(sizeof *new);
  new->node = node;
  new->next = head;

  return new;
}

nodeType list_find_ring(keyType key, list_node_ring head) {
  while(head != NULL) {
    if(equal(node_id(head->node), key))
      return head->node;

    head = head->next;
  }

  return NULL;
}

nodeType list_data_ring(list_node_ring node) { return node->node; }

list_node_ring list_next_ring(list_node_ring node) { return node->next; }

void list_print_ring(list_node_ring head) {
  while(head != NULL) {
    node_print(head->node);
    head = head->next;

    if(head != NULL)
      printf(" -> ");
  }
}