#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"
#include "../hashtable/hashtable.h"

void string_copy(char **dest, char *src) {
  int len = strlen(src);
  (*dest) = malloc((len + 1) * sizeof(char));
  memcpy((*dest), src, len + 1);
}

struct list_node_tag {
  keyType key;
  valueType value;
  list_node next; 
};

void list_free(list_node head) {
  while(head != NULL) {
    list_node current = head;
    head = head->next;
    free(current->key); free(current);
  }
}

list_node list_push(keyType key, valueType value, list_node head) {
  list_node node = list_find(key, head);
  if(node != NULL) { /* replace old value */
    node->value = value;
    return head;
  }

  list_node new = malloc(sizeof *new);
  
  string_copy(&new->key, key);
  new->value = value;
  new->next = head;

  return new;
}

list_node list_find(keyType key, list_node head) {
  while(head != NULL) {
    if(equal(head->key, key))
      return head;

    head = head->next;
  }

  return NULL;
}

keyType list_key(list_node node) { return node->key; }
valueType list_value(list_node node) { return node->value; }
list_node list_next(list_node node) { return node->next; }