#include <stdio.h>
#include <string.h>

#define STRING_SIZE 1000

char s[STRING_SIZE];

int wcount(char *s)
{

    int word = 0;
    int counter = 1;
    int counter2 = 0;
    if (s[0] == '\0') return 0;

    if (s[0] != ' ')
        word++;
    while(s[counter] != '\0')
    {
        if((s[counter] != ' ') && (s[counter2] == ' ') && (s[counter] != '\n'))
            word++;

        counter++;
        counter2++;
    }
    return word;
}

int main()
{
    gets(s);
    printf("%d", wcount(s));
}
