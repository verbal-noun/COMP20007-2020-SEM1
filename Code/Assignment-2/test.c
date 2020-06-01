#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

void change_value(int a );

int main(int argc, char const *argv[])
{
    /* code */
    int num = 0, mod = 0, k = 0; 
    scanf("%d %d %d", &num, &mod, &k);
    int *size = &mod; 
    *size = *size + 1;
    printf("%d\n", mod);
    printf("%d\n", *size);
    
//   // Create empty hash table 
//     char **hash_table = malloc(mod * sizeof(char*)); 
//     for(int i = 0; i < mod; i++) {
//         hash_table[i] = malloc(257 * sizeof(char));
//     }

//     for(int i = 0; i < mod; i++) {
//         strcpy(hash_table[i], "@");
//     }

//     for(int i = 0; i < mod; i++) {
//         printf("%s\n", hash_table[i]);
//     }
}

void change_value(int a ){
    a++; 
}
