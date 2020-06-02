#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

void change_value(int a );

int main(int argc, char const *argv[])
{
    /* code */
    char ch = 'a' + 3;
    printf("%c", ch);

}

void change_value(int a ){
    a++; 
}
