#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
    if (argc != 3) return 1;
    unsigned s_length = strlen(argv[1]);
    unsigned t_length = strlen(argv[2]);
    unsigned *p = calloc(s_length + t_length + 1, sizeof(unsigned));
    if (p == NULL) return 2;
    char *tmp_ptr = calloc(s_length + t_length + 2, sizeof(char));
    if (tmp_ptr == NULL)
    {
        free(p);
        return 2;
    }
    strcpy(tmp_ptr, argv[1]);
    argv[1] = tmp_ptr;
    argv[1][s_length] = (char)31;
    strcat(argv[1], argv[2]);
    unsigned k = 0;
    for (unsigned i = 1; i != s_length + t_length + 1; ++i)
    {
        while (k > 0 && argv[1][i] != argv[1][k])
        {
            k = p[k-1];
        }
        if (argv[1][i] == argv[1][k])
        {
            ++k;
        }
        p[i] = k;
        if (p[i] == s_length)
        {
            printf("%u ", i - 2 * s_length);
        }
    }
    free(p);
    free(tmp_ptr);
}
