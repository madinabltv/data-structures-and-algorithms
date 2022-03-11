#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack {
        	int cap,top;
		int *data;

	};
struct stack s;
void push(long x)
{
	s.data[s.top]=x;
	++s.top;
}
long pop()
{
	--s.top;
	return s.data[s.top];
}
long max(long a , long b)
{
	if (a>=b) return a;
	else return b;
}
long min(long a, long b)
{
	if (a<=b) return a;
	else return b;
}
int main()
{

	int n,i,j;
	long r,d,dup,sw1,sw2;
	scanf("%d\n", &n);
	s.data=(int*)malloc((n+1)*sizeof(int));
	s.cap=n;
	s.top=0;
	char **str;
	str=(char**)malloc((n+1)*sizeof(char*));
	for(i=0;i<n;++i)
	{
		str[i]=(char*)malloc(50*sizeof(char));
		gets(str[i]);
		d=1;
		r=0;
		if (str[i][0]=='C')
		{
			for(j=strlen(str[i])-1;str[i][j]!= ' '; --j)
			{
				if (str[i][j]=='-')
				r=-r;
				else
				{r=r+1*d*(str[i][j]-48);
				d*=10;}
			}
			push(r);
		}
		else if (strcmp(str[i],"ADD")==0)
			push(pop()+pop());
		else if (strcmp(str[i],"SUB")==0)
			push(pop()-pop());
		else if (strcmp(str[i],"MUL")==0)
			push(pop()*pop());
		else if (strcmp(str[i],"DIV")==0)
			push(pop()/pop());
		else if (strcmp(str[i],"MAX") ==0)
			push(max(pop(),pop()));
		else if(strcmp(str[i],"MIN")==0)
			push(min(pop(),pop()));
		else if(strcmp(str[i],"NEG")==0)
			push(-1*pop());
		else if(strcmp(str[i],"DUP")==0)
		{
			dup=pop();
			push(dup);
			push(dup);
		}
		else if(strcmp(str[i],"SWAP")==0)
		{
			sw1=pop();
			sw2=pop();
			push(sw1);
			push(sw2);
		}

		free(str[i]);
	}
	free(str);
	printf("%ld\n", pop());
        free(s.data);
}
