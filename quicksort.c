#include <stdio.h>
#include <stdlib.h>

long* base;
int m, nel;

void fill(const int nel)
{
	for (int i = 0; i < nel; i++)
		scanf(" %ld", base + i);
}

void show(const int nel)
{
	for (int i = nel - 1; i > -1; i--)
		printf("%ld ", *(base + i));
	printf("\n");
}

long* initialize(const int nel)
{
	long* array = (long*)malloc(nel * sizeof(long));
	return array;
}

int pickelement(const int minval, const int maxval)
{
	int random = (rand() % (maxval - minval)) + minval;
	return random;
}

int compare(const int a, const int b)
{
	int i = (*(base + a) - *(base + b) > 0) ? 1 : 0;
	return i;
}

void swap(const int a, const int b)
{
	int c = *(base + a);
	*(base + a) = *(base + b);
	*(base + b) = c;
}

void selectsort(int left, int right)
{
	for (int j = right; j > left; j--) {
		int k = j;
		for (int i = j - 1; i > left - 1; i--)
			if (compare(i, k) == 0)
				k = i;
		swap(j, k);
	}
}

int partition(int left, int right)
{
	int p = pickelement(left, right); 
	swap(p, right);
	int border = left; 
	//printf("left %d random %d right %d\n", left, p, right);

	for (int i = left; i < right; i++){
		if (compare(i, right) > 0) {
			swap(i, border);
			border++;
		}
	}
	swap(right, border);
	return border;
}

void quicksort(int left, int right)
{
	int tree_el = ((right - left) < m) ? 1 : 0;

	if (left < right){
		if (tree_el)
			selectsort(left, right);
		else {
			int border = partition(left, right);
			quicksort(left, border - 1);
			quicksort(border + 1, right);
		}
	}
}

int main()
{
	scanf(" %d %d", &nel, &m);

	base = initialize(nel);
	fill(nel);

	quicksort(0, nel - 1);
	//selectsort(0, nel - 1);
	show(nel);

	free(base);
	return 0;
}
