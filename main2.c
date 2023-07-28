#include <stdio.h>
#include <string.h>
#include "main.h"

int main()
{
    char input[] = "Hello, World! This is a test.";
    char delim[] = " ,!.";
    char *token;

    printf("Input string: %s\n", input);
    printf("Delimiter: \"%s\"\n", delim);

    token = _strtok(input, delim);

    while (token != NULL)
    {
        printf("Token: \"%s\"\n", token);
        token = _strtok(NULL, delim);
    }

    return 0;
}

