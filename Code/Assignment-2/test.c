#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

void change_value(char *str);

int main(int argc, char const *argv[])
{
    /* code */
    char str[4]; 
    change_value(str);
    printf("%s", str);

}

void change_value(char *str ){
    str[0] = 'a';
    str[1] = 'b';
    str[2] = '\0';
    printf("%s\n", str); 
}
