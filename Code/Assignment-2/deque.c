/* * * * * * *
 * Deque module (i.e., double ended queue) from Assignment 1
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by Kaif Ahsan
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deque.h"
#include "util.h"

// Create a new empty Deque and return a pointer to it
Deque *new_deque()
{
  Deque *deque = malloc(sizeof(*deque));
  assert(deque);

  deque->top = NULL;
  deque->bottom = NULL;
  deque->size = 0;

  return deque;
}

// Free the memory associated with a Deque
void free_deque(Deque *deque)
{
  // Remove (and thus free) all of the nodes in the Deque.
  while (deque->size > 0)
  {
    deque_remove(deque);
  }

  // Free the deque struct itself
  free(deque);
}

// Create a new Node with a given piece of data
Node *new_node(String new_word, Data count)
{
  Node *node = malloc(sizeof(*node));
  assert(node);

  node->next = NULL;
  node->prev = NULL;
  strcpy(node->word, new_word);
  node->frequency = count;

  return node;
}

// Free the memory associated with a Node
void free_node(Node *node)
{
  free(node);
}

// Add new word into the frequency list 
void add_word(Deque *deque, String word, Data data) {
  
  Node *current = deque->top;
  // If existing deque is empty 
  if(deque->size == 0) {
    deque_push(deque, word, data);
  }
  // if new node is greater the existing highest value 
  else if(data > deque->top->frequency) {
    // push data at the top of the deque
    deque_push(deque, word, data);
  }
  // If new data is lower the current lowest value 
  else if(data <= deque->bottom->frequency && deque->size < 5) {
    deque_insert(deque, word, data);
  }
  else {
    Node *new = new_node(word, data);
    while(current->next != NULL && 
    current->next->frequency >= data) {
      if(current->next->frequency == data && 
      !strcmp(word, current->next->word)) {
        break;
      }
      current = current->next;
    }
    
    /*Make the appropriate links */
    new->next = current->next; 
    // if the new node is not inserted 
    // at the end of the list 
    if (current->next != NULL){ 
      new->next->prev = new; 
    }
    else{
      deque->bottom = new;
    }
    current->next = new; 
    new->prev = current;
  }
}

// Add an element to the top of a Deque
void deque_push(Deque *deque, String word, Data data)
{
  Node *new = new_node(word, data);

  if (deque->size > 0)
  {
    new->next = deque->top;
    deque->top->prev = new;
  }
  else
  {
    // If the Deque was initially empty then new is both the top and bottom
    deque->bottom = new;
  }

  deque->top = new;
  deque->size++;
}

// Add an element to the bottom of a Deque
void deque_insert(Deque *deque, String word, Data data)
{
  Node *new = new_node(word, data);

  if (deque->size > 0)
  {
    new->prev = deque->bottom;
    deque->bottom->next = new;
  }
  else
  {
    // If the Deque was initially empty then new is both the top and bottom
    deque->top = new;
  }

  deque->bottom = new;
  deque->size++;
}

// Remove and return the bottom element from a Deque
void deque_remove(Deque *deque)
{
  if (deque->size == 0)
  {
    exit_with_error("can't remove from empty Deque");
  }

  Node *old_bottom = deque->bottom;

  if (deque->size == 1)
  {
    deque->top = NULL;
    deque->bottom = NULL;
  }
  else
  {
    deque->bottom = old_bottom->prev;
    deque->bottom->next = NULL;
  }

  deque->size--;

  free(old_bottom);
}

// Return the number of elements in a Deque
int deque_size(Deque *deque)
{
  return deque->size;
}

// Print the Deque on its own line with the following format:
//   [x_1, x_2, ..., x_n]
//     ^              ^
//    top           bottom
void print_deque(Deque *deque)
{
  Node *current = deque->top;
  int i = 0;

  printf("[");

  while (current)
  {

    printf("%s %d", current->word, current->frequency);
    // Print a comma unless we just printed the final element
    if (i < deque->size - 1)
    {
      printf(", ");
    }
    current = current->next;
    i++;
  }

  printf("]\n");
}

