#include <stdio.h>
#include <string.h>

int strdiff(char *a, char *b)
{
    char c1,c2;
    int i,j,w,k=-1;

    w=strlen(a);
    if (strlen(b) > strlen(a))
        w=strlen(b);
    for(i=0; i<w; ++i)
        for(j=0; j<8; ++j)
        {
            c1 = a[i]>>j;
            c2 = b[i]>>j;
            c1 &=0x01;
            c2 &=0x01;
            if (c1!=c2)
            {
                k=i*8+j;
                j=7;
                i=w-1;
            }

        }

    return k;
}
