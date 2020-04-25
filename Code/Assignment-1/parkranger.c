/* * * * * * *
 * Park Ranger module for Assignment 1
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "deque.h"
#include "parkranger.h"
#include "util.h"

/*
* This function must read in a ski slope map and determine whether or not
* it is possible for the park ranger to trim all of the trees on the ski slope
* in a single run starting from the top of the mountain.
*
* The ski slope map is provided via stdin in the following format:
*
*   n m
*   from to
*   from to
*   ...
*   from to
*
* Here n denotes the number of trees that need trimming, which are labelled
* {1, ..., n}. The integer m denotes the number "reachable pairs" of trees.
* There are exactly m lines which follow, each containing a (from, to) pair
* which indicates that tree `to` is directly reachable from tree `from`.
* `from` and `to` are integers in the range {0, ..., n}, where {1, ..., n}
* denote the trees and 0 denotes the top of the mountain.
*
* For example the following input represents a ski slope with 3 trees and
* 4 reachable pairs of trees.
*
* input:            map:          0
*   3 4                          / \
*   0 1                         /  2
*   0 2                        / /
*   2 1                        1
*   1 3                          \
*                                 3
*
* In this example your program should return `true` as there is a way to trim
* all trees in a single run. This run is (0, 2, 1, 3).
*
*/
bool is_single_run_possible() {
  // You should remove this line and replace it with your own code:
  int tree_num = 0; 
  int paths = 0; 
  int i = 0;
  // Scan the number of trees and reachable pairs 
  scanf("%d %d", &tree_num, &paths); 

  // If the reachable pairs is smaller than number of trees, return false 
  if(paths < tree_num) {
    return false;
  }  
   
  // Creating an adjency matrix and initialising it to false
  Deque* adj_list[tree_num+1];
  for(i = 0; i < tree_num + 1; i++){
    adj_list[i] = new_deque();
  }

  int start = -1, end = -1;
  for(i = 0; i < paths; i++) {
    scanf("%d %d", &start, &end);
    deque_insert(adj_list[start], end);
  }
  
  int max_total_path = 0;
  // Find the longest path possible from the peak
  max_total_path = dfs_explore(0, adj_list) - 1;
  for(i = 0; i < tree_num + 1; i++){
    free_deque(adj_list[i]);
  }

  if(max_total_path == tree_num) {
    return true; 
  } else {
    return false;
  }
  
}

// TODO: Add any additional functions or types required to solve this problem.

int dfs_explore(int node, Deque *adj_list[]) {  
  // A variable to measure the max length of the child path   
  int max_path = 0; 
  Node *temp;
  // If the node does not have an outgoing edge return 1 for its height 
  // This is also the base case of our recursive function 
  if(adj_list[node]->size == 0) {
    return 1;
  }

  // For each traversable reachable path of the node call dfs_explore
  temp = adj_list[node]->top;
  while(temp != NULL) {
    // Select the maximum from all the child paths 
    max_path = max(dfs_explore(temp->data, adj_list), max_path);
    temp = temp->next;
  }
  
  free_node(temp);
  // Return the summation current node and maximum child path 
  return max_path + 1;
  
}


int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}