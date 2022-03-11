#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int gcd(int a, int b)
{
        return abs(b ? gcd(b, a % b) : a);
}
void logar (int m, int *lg)
{
        int i=1, j=0;
	while (i<=m)
	{
		while (j<(1<<i))
		{
			lg[j]=i-1;
			++j;
		}
		++i;
	}
}
void build(int *a, int *lg, int *ST[], int n, int m)
{
	int i=0,j=1;
	while (i<n)
	{
		ST[i][0]=a[i];
		++i;
	}
	while (j<m)
	{
		i=0;
		while (i<=n-(1<<j))
		{
			ST[i][j]=gcd(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
			++i;
		}
		++j;
	}
}
int query(int *ST[], int l , int r, int *lg)
{
	int j;
	j=lg[r-l+1];
	return gcd(ST[l][j],ST[r-(1<<j)+1][j]);
}

int main()
{
	int i,n,m,l,d,r,k,j;
	scanf("%d", &n);
	int a[n];
	for (i=0; i<n;++i)
		scanf("%d", &a[i]);
	int *lg;
	lg=(int*)malloc((1<<((int)log2(n)+2))*sizeof(int));
	logar(log2(n)+1,lg);
	int **ST;
	ST=(int**)malloc((i+1)*sizeof(int*));
	for(i=0;i<n;++i)
		ST[i]=(int*)malloc((log2(n)+2)*sizeof(int));
	build(a,lg,ST,n,log2(n)+1);
	scanf("%d ", &m);
	char **s;
	s=(char**)malloc((m+1)*sizeof(char*));
	for (i=0;i<m;++i)
	{
		s[i]=(char*)malloc(50*sizeof(char));
		gets(s[i]);
		l=0;
		r=0;
		d=1;
		for(j=strlen(s[i])-1;s[i][j]!= ' '; --j)
		{

			r=r+1*d*(s[i][j]-48);
			d*=10;
		}
		d=1;
		for(k=j-1;k>=0; --k)
		{

			l=l+1*d*(s[i][k]-48);
			d*=10;
		}
		printf("%d\n", query(ST,l,r,lg));
		free(s[i]);

	}
	for(i=0;i<n;++i)
		free(ST[i]);
	free(lg);
	free(s);
        free(ST);
}
