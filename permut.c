#include <stdio.h>

int main()
{ 
        int a[8];
	int b[8];
 	int c[8];
	int i=0;
	int j=0;
	int boolean=0;
 	int check=1;
 	int k=0;
	int l=0;

	for (i=0;i<8;++i)
		scanf("%d", &a[i]);
	for (i=0; i<8; ++i)
		scanf("%d", &b[i]);
	for (i=0; i<8; ++i)
		c[i] = -1;

	for (i=0; i<8;++i)
		for (j=0; j<8;++j)
		{ 
			for (k=0; k<i;++k)
				if (j == c[k])
				{
					check =0;
					k=i;
				}      
			if (check ==1)
				if (a[i] == b[j])
				{ 
					++boolean;
					c[l++] = j; 
					j=7;
				} 
			check=1;
		}

	if (boolean == 8) 
		printf("yes \n");
	else 
		printf("no \n");

	return 0;
}
