/*
    * Header file for the linked list module   
*/

// Include guard, which ensures these typedesf and 
// prototypes aren't added multiple times 
#ifndef LINKEDLIST_H
#define LINKEDLIST_H 

typedef struct node node_t;
typedef struct data_t;
typedef struct list_t;

// Function to create an empty list 
list_t *make_empty_list(void);
// Function to check if list is empty
int is_list_empty(list_t *list);
// Function to free memory of a linked list 
void free_list(list_t *list);
// Insert item at the top of the list 
list_t *insert_at_head(list_t *list, data_t value);
// Insert item at the bottom of the list  
list_t *insert_at_foot(list_t *list, data_t value);
// Count the number of nodes
void count_nodes(list_t *list);

#endif LINKEDLIST_H