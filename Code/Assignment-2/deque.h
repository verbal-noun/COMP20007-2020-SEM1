/* * * * * * *
 * Deque module (i.e., double ended queue) for Assignment 1
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

// You must not change any of the code already provided in this file, such as
// type definitions, constants or functions.
//
// You may, however, add additional functions and/or types which you may need
// while implementing your algorithms and data structures.

#ifndef DEQUE_H
#define DEQUE_H

// DO NOT CHANGE THESE TYPE DEFINITIONS

// The data type that our Deque will contain
typedef int Data;
typedef char * String;

// Our Deque is implemented using a doubly-linked list
typedef struct deque Deque;

// The Nodes which make up the doubly-linked list
typedef struct node Node;

struct deque {
  Node *top;
  Node *bottom;
  int size;
};

struct node {
  Node *next;
  Node *prev;
  char word[100];
  Data frequency;
};

// Create a new empty Deque and return a pointer to it
Deque *new_deque();

// Free the memory associated with a Deque
void free_deque(Deque *deque);

// Create a new Node with a given piece of data
Node *new_node(String text, Data count);

// Free the memory associated with a Node
void free_node(Node *node);

// Add an element to the top of a Deque
void deque_push(Deque *deque, String word, Data data);

// Add an element to the bottom of a Deque
void deque_insert(Deque *deque, String word, Data data);

// Remove and return the top element from a Deque
Data deque_pop(Deque *deque);

// Remove and return the bottom element from a Deque
void deque_remove(Deque *deque);

// Return the number of elements in a Deque
int deque_size(Deque *deque);

// Print the Deque on its own line with the following format:
//   [x_1, x_2, ..., x_n]
//     ^              ^
//    top           bottom
void print_deque(Deque *deque);

// Adds new word into the list according to the its frequency 
void add_word(Deque *deque, String word, Data data);
#endif
