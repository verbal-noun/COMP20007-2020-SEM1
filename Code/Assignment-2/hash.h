/* * * * * * *
 * Hashing module for Assignment 2.
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

#ifndef HASH_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NULLCHAR " "
#define HASH_H
#define MAX_CHAR 257
#define ALPHABET_SIZE 26 
#define TWO_POWER_SIX 64
//-------------------------------------- 1a --------------------------------//
// Implements a solution to Problem 1 (a), which reads in from stdin:
//   N M
//   str_1
//   str_2
//   ...
//   str_N
// And outputs (to stdout) the hash values of the N strings 1 per line.
void problem_1_a();

/** A function to generate hash value for a give work 
 * 
 *  Parameter:
 *      str - The word whose hash value needs to be calculated 
 *      mod - the value of M used to calculate hash 
 * */     
int generate_hash(char str[], int mod);

/** A function to map value of a character according to given function
 * 
 * Parameter: 
 *  c - The character which needs to be converted 
 * */
int generate_value(char c);

/** Read words from the stdin 
 * 
 * Parameter:
 *      str - The string where value will be stored 
 * */ 
void read_word(char *str);
//-------------------------------------- 1b ------------------------------------//
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
void problem_1_b();
/** A function to insert a word into a given hashtable 
 * 
 * Parameter: 
 *      str - The string which would be hashed and placed into the table 
 *      hash_table - the hash table where the string will be placed 
 *      size - The size of the hashtable which also is the M value 
 *      step - The value of k    
 * */
int insert_hash(char str[], char **hash_table, int *size, int step);
/** A function to doubel the size of a given hashtable 
 * 
 * Parameter: 
 *      hash_table - The hashtable which has to be 
 *      table_size - The old able size and the value of M 
 *      step - The value of k used for rehashing 
 * */
char **resize_hash(char **hash_table, int *table_size, int step);

/** Iteratively free the memory associated with the hashtable
 * 
 * Parameter:
 *      table - The hashtable which will be freed 
 *      size - Size of the given hash table 
 * */
void free_table(char **table, int size);
#endif
