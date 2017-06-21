#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char *word = (char *)malloc(sizeof(char) * 1000);
    scanf("%s", word);
    word[0] = toupper(word[0]);
    printf("%s", word);
    return 0;
}