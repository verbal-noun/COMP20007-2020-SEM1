#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h";

void recurse(Node *node) {
  if(node->next == NULL) {
    node->prev = NULL;
  }

  recurse(node->next); 
  node->next->next = node; 
  node->prev = node->next; 
  node->next = NULL; 
}

void recursive_reverse(Deque *deque) {
  if(deque->size == 0 || deque->size == 1) {
    return; 
  }

  recurse(deque->top);
  Node *temp = deque->top;
  deque->top = deque->bottom;
  deque->bottom = temp; 

  free_node(temp);
}