#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nel;
int *base;

int* initialize(const int nel)
{
	int* array = (int*)malloc(nel * sizeof(int));
	return array;
}

void show()
{
	for (int i = 0; i < nel; i++)
		printf("%d ", *(base + i));
}

void fill()
{
	for (int i = 0; i < nel; i++)
		scanf(" %d", base + i);
}

int comb()
{
	int m = 1 << nel;
	int count = 0;
	int sum;
	for (int j = 1; j < m; j++) {
		sum = 0;
		for (int i = 0; i < nel; i++)
			if (j & (1 << i))
				sum += *(base + i);
		if ((sum > 0) && ((sum & (sum - 1)) == 0))
			count++;
	}
	return count;
}

int main()
{
	scanf(" %d", &nel);
	base = initialize(nel);

	fill();
	//show();
	printf("%d", comb());
	free(base);

	return 0;
}
