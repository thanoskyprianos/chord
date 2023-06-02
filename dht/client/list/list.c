#include <stdio.h> // delete later
#include <stdlib.h>

#include "list.h"

struct list_node_client_tag {
  keyType key;
  valueType value;
  list_node_client next; 
};

void list_free_client(list_node_client head) {
  while(head != NULL) {
    list_node_client current = head;
    head = head->next;
    free(current->key); free(current);
  }
}

list_node_client list_push_client(keyType key, valueType value, list_node_client head) {
  list_node_client node = list_find_client(key, head);
  if(node != NULL) { /* replace old value */
    node->value = value;
    return head;
  }

  list_node_client new = malloc(sizeof *new);
  
  string_copy(&new->key, key);
  new->value = value;
  new->next = head;

  return new;
}

list_node_client list_find_client(keyType key, list_node_client head) {
  while(head != NULL) {
    if(equal(head->key, key))
      return head;

    head = head->next;
  }

  return NULL;
}

keyType list_key_client(list_node_client node) { return node != NULL ? node->key : NULL; }
valueType list_value_client(list_node_client node) { return node != NULL ? node->value : -1; }
list_node_client list_next_client(list_node_client node) { return node != NULL ? node->next : NULL; }

// for debugging
void list_print_client(list_node_client head) { 
  while(head != NULL) {
    printf("(%s: %d)", head->key, head->value);
    head = head->next;

    if(head != NULL)
      printf(" -> ");
  }
}