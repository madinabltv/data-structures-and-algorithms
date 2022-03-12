#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pword(const char *sub, const char *str) {
	int i = 0;
	int j = 0;
	int tmpj;
	int subLen = strlen(sub);
	//int strLen = strlen(str);

	while (str[j]) {
		if (i == subLen)
			i = 0;
		//printf("1 i = %d j = %d\n", i, j);

		if (sub[i] == str[j]) {
			i++;
			j++;
		//printf("2 i = %d j = %d\n", i, j);

		} else if (sub[0] == str[j]) {
			i = 1;
			j++;
		//printf("3 i = %d j = %d\n", i, j);

		} else {
			int k;
			for (k = 0; k < subLen; k++) {
				i = 0;
				tmpj = j - (1 + k);
				//printf("tmp = %d\n", tmpj);

				while (sub[i] == str[tmpj] && tmpj < j + 1) {
					i++;
					tmpj++;
				}
				//printf("tmp = %d i = %d\n", tmpj, i);

				if ((tmpj - 1) == j) {
					i = 0;
					j -= (1 + k);
					//printf(" tmp = j = %d\n", tmpj);
					break;
				}
			}
			if (k == subLen){
				return 0;
				//printf("k = subLen = %d\n", k);
			}
		}
	}
	return 1;
}

int main(int argc, char **argv) {

	const char *sub = argv[1];
	const char *str = argv[2];

	(pword(sub, str)) ? printf("yes") : printf("no");

	printf("\n");
	return 0;
}
