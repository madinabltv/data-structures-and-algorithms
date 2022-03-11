#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M,N,t=0;
    int i,j;
	scanf("%d%d", &M, &N);
    int max[M],min[N];
	int a[M][N];
	int b[M],c[N];

	for(i=0;i<M;++i)
		for(j=0;j<N;++j)
			scanf("%d", &a[i][j]);

	for(i=0;i<M;++i)
	{
		max[i]=a[i][0];
		for(j=0;j<N;++j)
		{
			if(a[i][j] >= max[i])
			{
				max[i]=a[i][j];
				b[i]=j;
			}
		}
	}

    for(i=0;i<N;++i)
	{
		min[i]=a[0][i];
		for(j=0;j<M;++j)
		{
			if(a[j][i] <= min[i])
			{
				min[i]=a[j][i];
				c[i]=j;
			}
		}
	}

    /*for (int i = 0; i < M; i++) printf("%d ", max[i]);
    printf("\n");
    for (int i = 0; i < M; i++) printf("%d ", b[i]);
    printf("\n");
    for (int i = 0; i < N; i++) printf("%d ", c[i]);
    printf("\n");
    for (int i = 0; i < N; i++) printf("%d ", min[i]);
    printf("\n");*/


	for (i=0;i<M;++i)
		for (j=0;j<N;++j)
		    if (max[i] == min[j])
            {
                printf("%d %d\n", c[j], b[i]);
                return 0;
		    }
    printf("none\n");
    return 0;
}
