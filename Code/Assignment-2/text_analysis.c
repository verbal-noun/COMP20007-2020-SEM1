/* * * * * * *
 * Text Analysis module for Assignment 2.
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

#include "text_analysis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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
void problem_2_a() {
  // Generate a blank trie 
  TrieNode *root = create_node();
  // Populate the Trie with words 
  int num = 0; 
  scanf("%d", &num);
  getchar();
  for(int i = 0; i < num; i++) {
    // Each each line
    char word[MAX_WORD];
    read_word(word);
    insert_word(root, word);
  }
  // Perform preorder traversal of the trie
  printf("^\n"); 
  for(int i = 0; i < MAX_SIZE; i++) {
    if(root->children[i]){
      preorder_traverse(root->children[i], i);
    }
    
  }
}

TrieNode *create_node() {
  TrieNode *new_node = NULL;
  new_node = (TrieNode*)malloc(sizeof(TrieNode));
  assert(new_node);
  
  if(new_node) {
    new_node->endWord = FALSE;

    for(int i = 0; i < MAX_SIZE; i++) {
      new_node->children[i] = NULL;
    }
  }

  return new_node;
}

void insert_word(TrieNode *root, char* word) {
  int level = 0, index = 0; 
  int length = strlen(word);

  TrieNode *curr = root;
  for(level = 0; level < length; level++) {
    index = word[level] - 'a';
    if(!curr->children[index]) {
      curr->children[index] = create_node();
      
    }
    curr = curr->children[index]; 
  }
  curr->endWord = TRUE;
}

void *read_word(char *str) {
  int size = 0;
  char c = EOF;
  // Input a single line 
  while((c = getchar()) != '\n' && c != EOF) {
    str[size++] = (char) c;
  }
  str[size] = '\0';

  return str;
}

void preorder_traverse(TrieNode *root, int index) {
  char ch = 'a' + index;
  printf("%c\n", ch);
  // The word contains an end word as well 
  if(root->endWord) {
    printf("$\n");
  }

  for(int i = 0; i < MAX_SIZE; i++) {
    if(root->children[i]) {
      preorder_traverse(root->children[i], i);
    }
  }
}
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
void problem_2_b() {
  // TODO: Implement Me!
}

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
void problem_2_c() {
  // TODO: Implement Me!
}
