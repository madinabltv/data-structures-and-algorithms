#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
        int i,n,l,r,start;
	double maxsum,sum;
	scanf("%d", &n);
	double *a;
        a=(double*)malloc((n+1)*sizeof(double));
	double *b;
        b=(double*)malloc((n+1)*sizeof(double));
        double *c;
        c=(double*)malloc((n+1)*sizeof(double));
	for (i=0;i<n;++i)
	{
		scanf("%lf/%lf", &b[i], &c[i]);
		a[i]=log2(b[i]/c[i]);
		//printf("%lf ", a[i]);
	}
	l=0; r=0; maxsum=a[0]; start=0; sum=0; i=0;
	while(i<n)
	{
		sum+=a[i];
		if (sum>maxsum)
		{
			maxsum=sum;
			l=start;
			r=i;
		}
		++i;
		if(sum<0)
		{
			sum=0;
			start=i;
		}
	}
	printf("%d %d\n", l, r);
        free(a);
        free(b);
        free(c);
}
