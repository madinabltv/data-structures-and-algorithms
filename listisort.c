#include <stdio.h>
#include <stdlib.h>

struct elem { 
    struct elem *prev, *next; 
    int v; 
};

void Insert(struct elem *x, struct elem *y)
{
        struct elem *z;
	z=x->next;
	x->next=y;
	y->prev=x;
	y->next=z;
	z->prev=y;
}
void InsertHead(struct elem *list, struct elem *y)
{
	y->next=list->next;
	list->next->prev=y;
	y->prev=list;
	list->next=y;
}
struct elem *delete(struct elem *x)
{
	struct elem *y,*z;
	y=x->prev;
	z=x->next;
	y->next=z;
	z->prev=y;
	x->prev=NULL;
	x->next=NULL;
	free(x);
	return z;
}

struct elem *search(struct elem *list, struct elem *y)
{	
	struct elem *x;
	x=list->next;
	while(x->next!=list && x->next!=y && (x->next->v < y->v))
		x=x->next;
	if ((x->next==y || x==list->next) && (x->v > y->v)) return list;
	else  return x;
}

void InsertSort(struct elem *list)
{
	struct elem *x;
	x=list->next->next;
	while(x!=list)
	{	
		struct elem *y=(struct elem*)malloc(1*sizeof(struct elem));
		y->v = x->v;
			Insert(search(list,x),y); 
		struct elem *h=delete(x);
		x=h;
		
	}	
}
	
int main()
{
	int n,i;
	scanf("%d", &n);
	struct elem *l;
	struct elem *list=(struct elem*)malloc(1*sizeof(struct elem));
	list->prev=list;
	list->next=list;
	l=list;
	for(i=0;i<n;++i)
	{
		struct elem *x=(struct elem*)malloc(1*sizeof(struct elem));
		scanf("%d", &x->v);
		x->prev=l;
		x->next=l->next;
		l->next=x;
		if (i==0) list->next=x;
		if (i==n-1) {x->next=list;
				list->prev=x;}
		l=x;
	}
	InsertSort(list);
	struct elem *x;
	x=list->next;
	i=0;
	while(x!=list)
	{	
		printf("%d ", x->v);
		if (i>0) free(x->prev);
		x=x->next;
		++i;
	}
	free(list->prev);
	free(list);
	printf("\n");
}
