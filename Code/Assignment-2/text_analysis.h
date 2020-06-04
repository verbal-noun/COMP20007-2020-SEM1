/* * * * * * *
 * Text Analysis module for Assignment 2.
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

#ifndef TEXT_ANALYSIS_H
#include "deque.h"
#include "util.h"
#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TEXT_ANALYSIS_H
#define MAX_SIZE 26
#define TRUE 1
#define FALSE 0 
#define MAX_WORD 100
#define NULLBYTE '\0'
#define MAX_FREQ 5
// Build a character level trie for a given set of words.
//
// The input to your program is an integer N followed by N lines containing
// words of length < 100 characters, containing only lowercase letters.
//
// Your program should built a character level trie where each node indicates
// a single character. Branches should be ordered in alphabetic order.
//
// Your program must output the pre-order traversal of the characters in
// the trie, on a single line.
typedef struct node_t TrieNode; 

struct node_t {
    TrieNode *children[MAX_SIZE];
    int freq;
    int is_word; 

};  

// ------------------------------- 2a ---------------------------------// 
void problem_2_a();
/** Function to create an empty trie */
TrieNode *create_node();
/** Function to insert word in the trie 
 * 
 * Paramerter: 
 *      root - The root node of the trie 
 *      word - The word to be inserted in the trie 
*/
void insert_word(TrieNode *root, char* word);
/** Read words from stdin input 
 * 
 * Parameters: 
 *      str - String where characters will be stored 
 * */ 
// void read_word(char *str); 

/** Performs preorder traversal of a trie 
 * 
 * Parameters:
 *      root - The node which would be traversed
 *      index - Determines the child alphabet 
 * */
void preorder_traverse(TrieNode *root, int index);
/** Performs postorder traversal to free a trie */ 
void free_trie(TrieNode *root);



// ---------------------------------- 2b ------------------------------// 
// Using the trie constructed in Part (a) this program should output all
// prefixes of length K, in alphabetic order along with their frequencies
// with their frequencies. The input will be:
//   n k
//   str_0
//   ...
//   str_(n-1)
// The output format should be as follows:
//   an 3
//   az 1
//   ba 12
//   ...
//   ye 1
void problem_2_b();
/** A function to recursively search all prefixes of a given length 
 * 
 * Parameters:
 *      node - Current node of the trie to be evaluated 
 *      level - Current depth/level of the trie 
 *      index - Helps determine the character of the alphabet 
 *      size - target prefix size 
 *      prefix - An array to hold the string built recursively 
 **/
void recursive_search(TrieNode *node, int level, int index, int size, char prefix[]);


//------------------------------------- 2c ----------------------------------------// 
// Again using the trie data structure you implemented for Part (a) you will
// provide a list (up to 5) of the most probable word completions for a given
// word stub.
//
// For example if the word stub is "al" your program may output:
//   0.50 algorithm
//   0.25 algebra
//   0.13 alright
//   0.06 albert
//   0.03 albania
//
// The probabilities should be formatted to exactly 2 decimal places and
// should be computed according to the following formula, for a word W with the
// prefix S:
//   Pr(word = W | stub = S) = Freq(word = W) / Freq(stub = S)
//
// The input to your program will be the following:
//   n
//   stub
//   str_0
//   ...
//   str_(n-1)
// That is, there are n + 1 strings in total, with the first being the word
// stub.
//
// If there are two strings with the same probability ties should be broken
// alphabetically (with "a" coming before "aa").
void problem_2_c();
/** Function to print the probability of upto 5 most likely word given a stub
 * 
 * Parameters: 
 *      root - The trie which will be searched 
 *      word - the word stub which will be used 
 **/
void get_freq(TrieNode *root, char word[MAX_WORD]);
/** A function to recursively search word containing a particular prefix and puts 
 * into a deque 
 * 
 * Parameters: 
 *      node - Node which will be searched
 *      text - The string build so far recursively 
 *      list - the deque where matching words will be put 
 * */
void search_word(TrieNode *node, char text[MAX_WORD], Deque *list);

/** Function to check whether a node has any children 
 * 
 * Parameters: 
 *  node - The node to be inspected 
 * */
int has_children(TrieNode *node);

#endif
