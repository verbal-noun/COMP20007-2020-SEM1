#include <stdio.h> 

int main(int argc, char const *argv[])
{
    /* code */
    char str[256];
    int size = 0;
    int c = EOF;
    while((c = getchar()) != '\n' && c != EOF) {
        str[size++] = (char) c;
    }
    str[size] = '\0';

    printf("%s\n", str);
    
    return 0;
}

char *input_string() { 
    
}