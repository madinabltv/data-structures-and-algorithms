#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    char string[1000010];
    int mas[26] = {[0 ... 25] = 0};
    int n, i, j;

    fgets(string, sizeof(string), stdin);
    n = strlen(string);

    for (i=0; i<n-1; i++)
        mas[string[i]-97]++;

    for (i = 0; i< 26; i++)
    {
     for (j = 0; j< mas[i];j++)
        printf("%c", 97+i);
    }
        return 0;
}
