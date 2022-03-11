#include <stdio.h>
#include <stdlib.h>

struct task {
    int low, high;
};

struct stack {
                int cap,top;
		struct task *data;

	};

struct stack s;
int *arr;

void push(int left, int right)
{
	s.data[s.top].low=left;
	s.data[s.top].high=right;
	++s.top;
}

struct task pop()

{
	--s.top;
	return s.data[s.top];
}

int compare(int i, int j)
{
      if (arr[i] > arr[j]) return 1;
      else if (arr[i] < arr[j]) return -1;
      else return 0;
}

void swap(int i, int j)
{
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
}

int partition(int low, int high)
{
	int i=low, j=low;
	while (j<high)
	{
		if(compare(j,high)<0)
		{
			swap(i,j);
			++i;
		}
		++j;
	}
	swap(i,high);
	return i;
}

int main()
{

	int n,i,j;
	struct task cur;
	scanf("%d\n", &n);
	s.data=(struct task*)malloc(n*sizeof(struct task));
	arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;++i)
		scanf("%d", &arr[i]);
	s.cap=n;
	s.top=1;
	s.data[0].low=0;
	s.data[0].high=n-1;
	do
	{
		cur=pop();
		do
		{
			i=partition(cur.low,cur.high);
			if (i<cur.high)
				push(i+1,cur.high);
			cur.high=i-1;
		}while(cur.low<cur.high);
	}while(s.top!=0);
	for(i=0;i<n;++i)
		printf("%d ", arr[i]);
	printf("\n");
	free(s.data);
}
