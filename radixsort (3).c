#include <stdio.h>
#include <string.h>
#include <stdlib.h>



union Int32 { 
    int x; 
    unsigned char bytes[4]; 
}; 


unsigned char key(unsigned char ss, int q)
{        
        return  ss;
}
unsigned char keys(union Int32 s, int q)
{
	if (q==4  && (s.bytes[3]>>7 & 0x01 ==0))
		return s.bytes[3];
	else if (q==4 )
		return (s.bytes[3]-128);
	else if(q==3) return s.bytes[2];
	else if(q==2) return s.bytes[1];
	else if(q==1) return s.bytes[0];
}
union Int32 *distribution( int q, unsigned char (*key)(unsigned char ss, int q), int m, union Int32 *s, int n)
{	
	int count[m];
	int i;
	unsigned char k;
	int j=0;
	for(i=0; i<=m;++i)
		count[i]=0;
	while (j<n)
	{	
		
		k=key(keys(s[j],q), q);
		++count[k];
		++j;
	}
	i=1;
	while (i<m)
	{
		count[i] += count[i-1];
		++i;
	}
	union Int32 *d = (union Int32*) malloc((n+1)*sizeof(union Int32));
	j=n-1;
	

	while(j>=0 )
	{	
		k=key(keys(s[j],q), q);
		i=count[k]-1;
		count[k]=i;
		if(i<n && i>=0 )
		{
			
			d[i]=s[j];
		}
		--j;
	}
    
	return d;
}

void radixsort( unsigned char (*key)(unsigned char i, int q), int q, union Int32 *a, int n)
{
	union Int32 b[n];
	union Int32 *f;
	int i,m;
	for (i=0;i<n;++i)
	{
		b[i]=a[i];
	}
	while (q<=4)
	{	
		
		
		m=256;
			f= distribution(q,key,m,b,n);
			for (i=0;i<n;++i)
			{
				b[i]=f[i];
			}

		free(f);
		++q;
	}
	for(i=0;i<n;++i)
	{
		printf("%d\n", b[i].x);
	}
}
	

int main()
{
	
	
	int n,i;
	scanf("%d", &n);
	union Int32 a[n];
	for (i = 0; i < n; ++i)
		scanf("%d", &a[i].x);
	
	radixsort(key, 1,a,n);
}

