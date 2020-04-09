#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linkedList.h"

typedef struct node node_t;
typedef struct {
    /* data */
    int val;

} data_t;

struct node{
    /* data */
    data_t data;
    node_t *next;
};

typedef struct {
    node_t *head;
    node_t *foot;
} list_t;

// Function to create an empty list 
list_t *make_empty_list(void) {
    list_t *list;
    list = (list_t*)malloc(sizeof(*list));
    assert(list != NULL);
    list->head = list->foot = NULL;
    return list;
}

int is_list_empty(list_t *list) {
    assert(list != NULL);
    return list->head == NULL;
}

// Function to free memory of a linked list 
void free_list(list_t *list) {
    node_t *prev, *curr;
    assert(list != NULL);
    curr = list->head;
    while (curr) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    free(list);
}

list_t *insert_at_head(list_t *list, data_t value) {
    node_t *new; 
    new = (node_t*)malloc(sizeof(node_t));
    assert(list != NULL && new!=NULL);
    new->data = value;
    new->next = list->head;
    list->head = new;
    if(list->foot == NULL) {
        list->foot = new;
    }
    return list;
}

list_t *insert_at_foot(list_t *list, data_t value) {
    node_t *new;
    new = (node_t*)malloc(sizeof(node_t));
    assert(list!=NULL && new!=NULL);
    new->data = value;
    if (list->foot == NULL) {
        list->head = list->foot = NULL;
    } else {
        list->foot->next = NULL; 
        list->foot = new; 
    }
    return list;
}

void count_nodes(list_t *list) {
    node_t *temp;
    int count = 0; 
    temp = list->head; 
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", count);
}