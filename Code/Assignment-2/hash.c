/* * * * * * *
 * Hashing module for Assignment 2.
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by Kaif Ahsan
 */

#include "hash.h"
#include <stdio.h>
#include <math.h>

// Implements a solution to Problem 1 (a), which reads in from stdin:
//   N M
//   str_1
//   str_2
//   ...
//   str_N
// And outputs (to stdout) the hash values of the N strings 1 per line.
void problem_1_a() {
  // Input number of strings and mod value 
  int num = 0, mod = 0;
  scanf("%d %d", &num, &mod);
  getchar();

  int i = 0;
  for(i = 0; i < num; i++) {
    // Input string 
    char str[256];
    int size = 0;
    int c = EOF;
    int hash = 0; 

    while((c = getchar()) != '\n' && c != EOF) {
      str[size++] = (char) c;
    }
    str[size] = '\0';
    
    // Generate hash of given string 
    hash = generate_hash(str, size, mod);
    // output hash to the stdout 
    printf("%d\n", hash);
  }
}

// A function to generate hash for a given string 
int generate_hash(char str[], int size, int mod) {
  int result = generate_value(str[0]);
  int chr = 0;
  for(int i = 1; i < size; i++) {
    // generate character value
    chr = generate_value(str[i]);
    // Add character value into result 
    result = (result * 64 + chr) % mod;
  }

  // return hash value of string
  return result % mod;
}

int generate_value(char c) {
  int offset = 26; 
  int value = 0;

  if ('a' <= c && c <= 'z') {
    value = c - 'a';
  } 
  else if ('A' <= c && c <= 'Z'){
    value = c - 'A' + offset;
  }
  else {
    value = c - '0' + ( 2 * offset);
  }
  return value;
  
}
// Implements a solution to Problem 1 (b), which reads in from stdin:
//   N M K
//   str_1
//   str_2
//   ...
//   str_N
// Each string is inputed (in the given order) into a hash table with size
// M. The collision resolution strategy must be linear probing with step
// size K. If an element cannot be inserted then the table size should be
// doubled and all elements should be re-hashed (in index order) before
// the element is re-inserted.
//
// This function must output the state of the hash table after all insertions
// are performed, in the following format
//   0: str_k
//   1:
//   2: str_l
//   3: str_p
//   4:
//   ...
//   (M-2): str_q
//   (M-1):
void problem_1_b() {
  // TODO: Implement Me!
}
