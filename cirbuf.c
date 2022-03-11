#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack {        
        	int cap,count,head,tail;
		int *data;
		
	};
struct stack s;
void enq(long x)
{	
	int i,k,j;
	int *help;
	if (s.count==s.cap)
	{ 
		if (s.tail >s.head || (s.head==s.tail && s.head==0))
		{	//printf("HI 1\n");
			help=(int*)malloc((s.cap+1)*sizeof(int));
			for(i=s.head;i<s.cap;++i)
			{
				help[i]=s.data[i];
			}
			free(s.data);
			s.data=(int*)malloc((2*s.cap+1)*sizeof(int));
			s.cap*=2;
			for(i=s.head;i<s.cap/2;++i)
			{
				s.data[i]=help[i];
				//printf("%d\n", s.data[i]);
			}
			s.tail=s.cap/2;
			free(help);
		}
		else
		{	
			//printf("HI 2\n");
			help=(int*)malloc((s.cap+1)*sizeof(int));
			for(i=0;i<s.tail;++i)
			{
				help[i]=s.data[i];
			}
			for(i=s.head;i<s.cap;++i)
			{
				help[i]=s.data[i];
			}
			free(s.data);
			s.data=(int*)malloc((2*s.cap+1)*sizeof(int));
			k=s.cap;
			s.cap*=2;
			for(i=0,j=0;i<s.tail;++i,++j)
			{
				s.data[i]=help[j];
			}
			for(i=s.cap-1-k+s.head+1,j=s.head;i<s.cap;++i,++j)
			{
				s.data[i]=help[j];
			}
			s.head=s.cap-1-k+s.head+1;
			free(help);
		}
	}
		
	s.data[s.tail]=x;
	++s.tail;
	if (s.tail==s.cap)
		s.tail=0;
	++s.count;
}
long deq()
{
	long x;
	x=s.data[s.head];
	++s.head;
	if(s.head ==s.cap)
		s.head=0;
	--s.count;
	return x;
}

int main()
{	
	
	int n,i,j;
	long r,d;
	scanf("%d\n", &n);
	s.data=(int*)malloc((4+1)*sizeof(int));
	s.cap=4;
	s.count=0;
	s.head=0;
	s.tail=0;
	char **str;
	str=(char**)malloc((n+1)*sizeof(char*));
	for(i=0;i<n;++i)
	{	
		str[i]=(char*)malloc(50*sizeof(char));
		gets(str[i]);
		d=1;
		r=0;
		if ((strcmp(str[i],"EMPTY"))==0)
		{
			if(s.count==0)
				printf("true\n");
			else
				printf("false\n");
		}
		else if (str[i][0]=='E')
		{
			for(j=strlen(str[i])-1;str[i][j]!= ' '; --j)
			{
				if (str[i][j]=='-')
					r=-r;
				else
				{r=r+1*d*(str[i][j]-48);
				d*=10;}
			}
			enq(r);
		}
		else if (strcmp(str[i],"DEQ")==0)
			printf("%ld\n", deq());
		free(str[i]);
	}
	free(s.data);
	free(str);
}
