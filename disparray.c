#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elem {
    struct elem *next;
    int v,k;
};
int q;
struct elem *init(struct elem *t)
{
        t=NULL;
	return t;
}
struct elem *listsearch(struct elem *t, int k)
{
	struct elem *x=t;
	while(x!=NULL && x->k!=k)
		x=x->next;
	return x;
}
int h(int i)
{
	return i%q;
}
int lookup(struct elem **t, int k)
{
	struct elem *p=listsearch(t[h(k)],k);
	if (p==NULL) return 0;
	return p->v;
}
struct elem *insertbeforehead(struct elem *t, int k, int v)
{
	struct elem *y=(struct elem*)malloc(1*sizeof(struct elem));
	y->k=k,y->v=v;
	y->next=t;
	t=y;
	return t;
}
void deleteafter(struct elem *x)
{
	struct elem *y=x->next;
	x->next=y->next;
	y->next=NULL;
	free(y);
}
struct elem *deletehead(struct elem *t)
{
	struct elem *y=t;
	t=y->next;
	y->next=NULL;
	free(y);
	return t;
}
struct elem *searchanddelete(struct elem *t, int k)
{
	struct elem *y=NULL, *x=t;
	while(x!=NULL)
	{
		if(x->k==k)
		{
			if(y==NULL)
				t=deletehead(t);
			else
				deleteafter(y);
			break;
		}
		y=x;
		x=x->next;
	}
	return t;
}
struct elem *delete(struct elem **t, int k)
{
	return searchanddelete(t[h(k)],k);
}
struct elem *insert(struct elem **t, int k, int v)
{
	int i=h(k);
	return insertbeforehead(t[i],k,v);
}
struct elem *reassign(struct elem **t, int k, int v)
{
	struct elem *p=listsearch(t[h(k)],k);
	if(p==NULL && v!=0) t[h(k)]=insert(t,k,v);
	else if(p!=NULL && v==0) t[h(k)]=delete(t,k);
	else if (p!=NULL) p->v=v;
	return t[h(k)];
}
int main()
{
	int n,m,i,j,k,v;
	char com[10];
	scanf("%d %d", &n,&m);
	q=m;
	struct elem **t=(struct elem**)malloc((m+1)*sizeof(struct elem*));
	for(i=0;i<m;++i)
		t[i]=init(t[i]);
	for(i=0;i<n;++i)
	{
		scanf("%s %d", com, &k);
		if(strcmp(com,"AT")==0)
			printf("%d\n", lookup(t,k));
		else
		{
			scanf("%d", &v);
			t[h(k)]=reassign(t,k,v);
		}
	}
	for(i=0;i<m;++i)
	{
		struct elem *x,*h;
		x=t[i];
		j=0;
		while(x!=NULL)
		{
			h=x;
			x=x->next;
			free(h);
			++j;
		}
	}
	free(t);
}

