/* * * * * * *
 * Text Analysis module for Assignment 2.
 *
 * created for COMP20007 Design of Algorithms 2020
 * template by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 * implementation by <Insert Name Here>
 */

#include "text_analysis.h"

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
  // Input number of words  
  scanf("%d\n", &num);
  // Read words from stdin and insert into trie 
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
  
  // Recursively free memory allocated for trie 
  free_trie(root);
}

TrieNode *create_node() {
  // Allocate memory for a new node 
  TrieNode *new_node = NULL;
  new_node = (TrieNode*)malloc(sizeof(TrieNode));
  assert(new_node);
  // Initialise node with NULL
  if(new_node) {
    new_node->is_word = FALSE;

    for(int i = 0; i < MAX_SIZE; i++) {
      new_node->children[i] = NULL;
    }
  }

  return new_node;
}

// Function to insert word into the trie 
void insert_word(TrieNode *root, char* word) {
  int level = 0, index = 0; 
  int length = strlen(word);

  TrieNode *curr = root;
  for(level = 0; level < length; level++) {
    index = word[level] - 'a';
    // If character doesn't exist in trie level 
    if(!curr->children[index]) {
      curr->children[index] = create_node();
      curr->children[index]->freq = 1; 
    }
    // Increase frequency of the character 
    else{
      curr->children[index]->freq++;
    }
    // Move into next level 
    curr = curr->children[index]; 
  }
  // Mark the end of a word 
  curr->is_word++;
}

void preorder_traverse(TrieNode *root, int index) {
  char ch = 'a' + index;
  printf("%c\n", ch);
  // The word contains an end word as well 
  if(root->is_word != 0) {
    printf("$\n");
  }

  for(int i = 0; i < MAX_SIZE; i++) {
    if(root->children[i]) {
      preorder_traverse(root->children[i], i);
    }
  }
}

void free_trie(TrieNode *root) {
  for(int i = 0; i < MAX_SIZE; i++) {
    if(root->children[i]) {
      free_trie(root->children[i]);
    }
  }

  free(root);
}

//----------------------------------------- 2b ------------------------------//
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
  // Take input of n & k 
  int num = 0, k = 0; 
  scanf("%d %d\n", &num, &k);

  // Initiate an empty trie 
  TrieNode *root = create_node();
  // Read word from stdin and insert into trie 
  for(int i = 0; i < num; i++) {
    // Each each line
    char word[MAX_WORD];
    read_word(word);
    insert_word(root, word);
  }
  
  // Recursively look for prefix with fixed size of k 
  char prefix[k+1];
  // -1 is passed as index has root level has no words 
  recursive_search(root, -1, 0, k, prefix);

  // Free memory allocated for trie 
  free_trie(root);
}

// Function to recursive search for prefixes with a fixed length 
void recursive_search(TrieNode *node, int level, int index, int size, char prefix[]) {
  // Base case 
  if(level + 1 == size) {
    char ch = 'a' + index;
    prefix[level] = ch;
    prefix[level+1] = '\0'; 
    printf("%s %d\n", prefix, node->freq);
    return; 
  }
  // Normal case
  else {
    for(int i = 0; i < MAX_SIZE; i++) {
      if(node->children[i]) {
        char ch = 'a' + i;
        prefix[level+1] = ch; 
        recursive_search(node->children[i], level+1, i, size, prefix);
      }
      
    }
  }
  
}

//------------------------------------- 2c ---------------------------------------//
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
  // Take number of strings and word stub 
  int num = 0; 
  char stub[MAX_WORD]; 
  scanf("%d\n", &num);
  read_word(stub);

  // Build the trie from the input words 
  TrieNode *root = create_node();
  for(int i = 0; i < num; i++) {
    char word[MAX_WORD];
    read_word(word);
    insert_word(root, word);
  }

  
  // Find the matching words with highest frequency 
  get_freq(root, stub);

  // free memory used for trie 
  free_trie(root);
}


// Function to get the frequency linked list for words 
void get_freq(TrieNode *root, char word[MAX_WORD]) {
  // Move to the end of word stub
  TrieNode *temp = root;   
  for(int i = 0; i < strlen(word); i++) {
    int index = word[i] - 'a';
    if(temp->children[index]) {
      temp = temp->children[index];
    // No word of given stub exits   
    } else {
      return;
    }
    
  }
 
  // Populate all the words into a deque which contains the stub 
  // Deque functionalityimplemented on top of Assignment-1 provided files  
  Deque *word_list = new_deque();
  char copy[MAX_WORD];
  strcpy(copy, word);
  search_word(temp, copy, word_list);

  // Print the word probability 
  // Calculate frequency of word stub 
  double stub_freq = temp->freq;
  Node *current = word_list->top;
  double word_freq = 0;
  if(word_list->size > 0) {
    int i = 0;
    // Loop through the frequency list to calculate and print data
    while (current)
    {
      word_freq = current->frequency; 
      printf("%.2f %s\n", word_freq / stub_freq, current->word);
      current = current->next;
      i++;
      // Bounds to print only top 5 items 
      if(i == MAX_FREQ) break;
    }
  }

  // Free memory used for the deque 
  free_deque(word_list);
  
}


// Function to search words containing a given stub and add it to a linked list 
void search_word(TrieNode *node, char text[MAX_WORD], Deque *list) {
  // Base case - word has been found  
  if(node->is_word || !has_children(node)) {
    // Add word into the frequency list 
    add_word(list, text, node->is_word);
  }
  // Normal case 
  for(int i = 0; i < MAX_SIZE; i++) {
    if(node->children[i]) {
      // Get the length of current str 
      int prev_len = strlen(text);
      // Add new character into the string and pass it to the next recursive func
      char ch = 'a' + i; 
      strcat(text, &ch);
      text[prev_len+1] = NULLBYTE; 
      search_word(node->children[i], text, list);
      // reverse the change after recursive call 
      text[prev_len] = NULLBYTE;

    }
  }
}


// Function to check if a node has children 
int has_children(TrieNode *node) {
  for(int i = 0; i < MAX_SIZE; i++) {
    // The node has a child 
    if(node->children[i]) {
      return TRUE;
    }
  }

  return FALSE;
}