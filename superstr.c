#include <stdio.h>
#include <stdlib.h>
#define size 1024

char** base;

int length(int i)
{
	int length = 0;
	while (*(*(base + i) + length) != 0)
		length++;
	return length;
}

int wordcmp(const char *Aword, const char *Bword){
	while (*Aword && *Bword && *Aword == *Bword){
		Aword++;
		Bword++;
	}
	return *Aword - *Bword;
}

char* subword(int word, int left, int right)
{
	char* subword = (char*)malloc(size * sizeof(char));
	int i = 0;
	int j = left;
	while (j < right + 1) {
		*(subword + i) = *(*(base + word) + j);
		i++;
		j++;
	}
	*(subword + i) = 0;
	return subword;
}

int overlap(int a, int b)
{
	int Aword = length(a) - 1;
	int Bword = length(b) - 1;
	int overlap = 0;
	int i = Aword;
	int j = 0;
	char* suff,* preff;

	while ((i > 0) && (j < Bword + 1)) {
		suff = subword(a, i, Aword);
		preff = subword(b, 0, j);
		//printf("%s %s\n", suff, preff);
		if (wordcmp(suff, preff) == 0)
			overlap = j + 1;
		free(suff);
		free(preff);
		i--;
		j++;
	}
	return overlap;
}

void merge(int a, int b, int j) {
	int i = 0;
	while(*(*(base + a) + i) != 0)
		i++;
	while(*(*(base + b) + j) != 0){
		*(*(base + a) + i) = *(*(base + b) + j);
		i++;
		j++;
	}
	*(*(base + a) + i) = 0;
	**(base + b) = 0;
}

void superstr(int nel)
{
	int half = 0;
	while (half < (nel - 1)) {
		int a = 0, b = 0;
		int maxlap = -1;
		for (int i = 0; i < nel; i++) {
			for (int j = 0; j < nel; j++) {
				if ((i != j) && (**(base + i) != 0) && (**(base + j) != 0)) {
					int h = overlap(i, j);
					if (h > maxlap) {
						maxlap = h;
						a = i;
						b = j;
						}
				}
			}
		}
		merge(a, b, maxlap);
		half++;
	}
}

int main()
{
	int nel;
	scanf("%d ", &nel);
	base = (char**)malloc(nel * sizeof(char*));

	for (int i = 0; i < nel; i++){
		*(base + i) = (char*)malloc(size * sizeof(char));
		scanf("%s\n", *(base + i));
	}

	superstr(nel);

	for (int i = 0; i < nel; i++) {
		if (**(base + i) != 0)
			printf("%d\n", length(i));
		free(*(base + i));
	}

	free(base);
	return 0;
}
