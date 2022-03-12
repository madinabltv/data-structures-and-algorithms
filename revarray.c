#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void revarray(void *base, unsigned long nel, unsigned long width);
int main(int argc, char **argv){
    return 0;
}

void revarray(void *base, unsigned long nel, unsigned long width) {
    for (unsigned long i = 0; i * 2 < nel; i++) {
        unsigned long j = nel - i - 1;
        void* a = malloc(width);
        memmove(a, ((char*)base + i * width), width);
        memmove(((char*)base + i * width), ((char*)base + j * width), width);
        memmove(((char*)base + j * width), a, width);
        free(a);
    }
}
