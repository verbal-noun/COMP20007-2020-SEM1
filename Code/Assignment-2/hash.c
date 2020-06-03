/* * * * * * *
 * Hashing module for Assignment 2.
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards" "unimelb.edu.au>
 * implementation by Kaif Ahsan
 */

#include "hash.h"

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
  scanf("%d %d\n", &num, &mod);

  int i = 0;
  for(i = 0; i < num; i++) {
    // Input words from stdin 
    char str[MAX_CHAR];
    int hash = 0; 
    read_word(str);
    
    // Generate hash of given string 
    hash = generate_hash(str, mod);
    // output hash to the stdout 
    printf("%d\n", hash);
  }
}

// A function to generate hash for a given string 
int generate_hash(char str[], int mod) {
  int result = generate_value(str[0]);
  int chr = 0;
  for(int i = 1; i < strlen(str); i++) {
    // generate character value
    chr = generate_value(str[i]);
    // Add character value into result 
    result = (result * TWO_POWER_SIX + chr) % mod;
  }

  // return hash value of string
  return result % mod;
}

int generate_value(char c) {
  int value = 0;

  if ('a' <= c && c <= 'z') {
    value = c - 'a';
  } 
  else if ('A' <= c && c <= 'Z'){
    value = c - 'A' + ALPHABET_SIZE;
  }
  else {
    value = c - '0' + ( 2 * ALPHABET_SIZE);
  }
  return value;
  
}

void read_word(char *str) {
  int size = 0;
  char c = EOF;
  // Input a single line 
  while((c = getchar()) != '\n' && c != EOF) {
    str[size++] = (char) c;
  }
  str[size] = '\0';

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
  // Take initial input 
  int num = 0, mod = 0, k = 0, i = 0;
  // Pointer to the table size   
  int *table_size = &mod; 
  // Take input initial values 
  scanf("%d %d %d\n", &num, &mod, &k);

  // Create empty hash table 
  char **hash_table = malloc(mod * sizeof(char*)); 
  for(i = 0; i < mod; i++) {
    hash_table[i] = malloc(MAX_CHAR * sizeof(char));
  }
  for(i = 0; i < mod; i++) {
    strcpy(hash_table[i], NULLCHAR);
  }

  // Read strings 
  for(i = 0; i < num; i ++){
    char str[MAX_CHAR];
    read_word(str);
    // Insert strings into the hash table

    int hash_placed = 0;
    while(!hash_placed) {
      // Attempt to insert hash into table 
      hash_placed = insert_hash(str, hash_table, table_size, k);
      // If unsuccessful resize hashtable
      if(!hash_placed) {
        // Resize hashtable
        hash_table = resize_hash(hash_table, table_size, k);
      } 
    }
  }

  // Print values stored in the hash table 
  for(i = 0; i < mod; i++) {
    printf("%d: %s\n", i, hash_table[i]);
  }
  
  // Free hashtable 
  free_table(hash_table, *table_size);
  
}

int insert_hash(char str[], char **hash_table, int *size, int step) {
    // Generate hash value 
    int hash = generate_hash(str, *size);
    // Attempt to insert hash into hash table or recursive increase size
    int ind = (hash + step) % *size ; 
    if(!strcmp(hash_table[hash], NULLCHAR)) {
      strcpy(hash_table[hash], str);
      return true;
    }
    // Item already in place, try to put it in K steps
    while(ind != hash) {
      if(!strcmp(hash_table[ind], NULLCHAR)) {
        strcpy(hash_table[ind], str);
        return true;
      }
      // Otherwise increase by K 
      ind = (ind + step) % (*size);
    }
  // String could not be placed in the table 
  return false;
}

char **resize_hash(char **hash_table, int *table_size, int step) {
  // Create a reference to the old table 
  char **old_table = hash_table;
  int old_size = *table_size;
  *table_size = *table_size * 2;

  // Create new hashtable 
  char **new_table = malloc(2 * old_size * sizeof(char*)); 
  for(int i = 0; i < 2 * old_size; i++) {
    new_table[i] = malloc(MAX_CHAR * sizeof(char));
  }
  for(int i = 0; i < 2 * old_size; i++) {
    strcpy(new_table[i], NULLCHAR);
  }

  // Recalculate hash into new table 
  for(int i = 0; i < old_size; i++) {
    // insert old string into the new hash table 
    int hash_placed = 0;
    while(!hash_placed) {
      // Attempt to insert hash into table 
      hash_placed = insert_hash(old_table[i], new_table, table_size, step);
      // If unsuccessful resize hashtable
      if(!hash_placed) {
        // Resize hashtable
        hash_table = resize_hash(new_table, table_size, step);
      } 
    }

  }

  // Free old table 
  free_table(old_table, old_size);
  // Return new hashtable 
  return new_table;
}

void free_table(char **table, int size) {
  // Free individual item
  for(int i = 0; i < size; i++) {
    free(table[i]);
  }
  // Free hashtable 
  free(table);
}