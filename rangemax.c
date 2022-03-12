#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct task {
	char operation[3];
	int x;
	int y;
};

int *tree;
int *base;

int findMAX(const int x, const int y) {
	return (base[x] >= base[y]) ? x : y;
}

void build(const int left_gap, const int right_gap, int index) {
	if (left_gap == right_gap)
		tree[index] = left_gap;
	else {
		int middle =(left_gap + right_gap) / 2;
		build(left_gap, middle, (2 * index + 1));
		build(middle + 1, right_gap, (2 * index + 2));
		tree[index] = findMAX(tree[2 * index + 1], tree[2 * index + 2]);
	}
}

void segment_tree_build(const int nel) {
	build(0, nel - 1, ( - (1 / 2)));
}

int query(const int left_gap, const int right_gap, const int left, const int right, int index) {
	if ((left_gap == left) && (right_gap == right))
		return tree[index];
	else {
		int middle = (left + right) / 2;
		if (right_gap <= middle)
			return query(left_gap, right_gap, left, middle, (2 * index + 1));
		else if (left_gap > middle)
			return query(left_gap, right_gap, middle + 1, right, (2 * index + 2));
		else
			return findMAX(query(left_gap, middle, left, middle, (2 * index + 1)),
			query(middle + 1, right_gap, middle + 1, right, (2 * index + 2)));
	}
}

int segment_tree_query(const int nel, const int left_gap, const int right_gap) {
	int value = query(left_gap, right_gap, 0, nel - 1, 0);
	return value;
}

void update(const int i, const int v, const int left, const int right, int index) {
	if (left == right)
		base[tree[index]] = v;
	else {
		int middle = (left + right) / 2;
		if (i <= middle)
			update(i, v, left, middle, (2 * index + 1));
		else
			update(i, v, middle + 1, right, (2 * index + 2));
		tree[index] = findMAX(tree[2 * index + 1], tree[2 * index + 2]);
	}

}

void segment_tree_update(const int nel, const int i, const int v) {
	update(i, v, 0, nel - 1, 0);
}

void execute(struct task *procedure, const int procedureCount, const int nel) {

	for (int i = 0; i < procedureCount; i++) {

		if (procedure[i].operation[1] == 'M') {
			int value = segment_tree_query(nel, procedure[i].x, procedure[i].y);
			printf("%d\n", base[value]);

		} else if (procedure[i].operation[1] == 'U')
			segment_tree_update(nel, procedure[i].x, procedure[i].y);
	}
}

int main() {

	int nel;
	scanf (" %d\n", &nel);

	int k = 1;
	while (nel > pow(2, k))
		k++;

	int j;
	base = (int*)malloc(pow(2, k) * sizeof(int));
	for (j = 0; j < nel; j++)
		scanf(" %d", &base[j]);
	int inf = ( - pow(10, 9) - 1);
	for (; j < pow(2, k); j++)
		base[j] = inf;

	tree = (int*)malloc(pow(2, k + 1) * sizeof(int));
	for (int i = 0; i < pow(2, k + 1); i++)
		tree[i] = 0;

	int procedureCount;
	scanf("\n %d\n", &procedureCount);

	struct task *procedure = (struct task*)malloc(procedureCount * sizeof(struct task));
	for (int i = 0; i < procedureCount; i++)
		scanf( "%c%c%c %d %d\n", &procedure[i].operation[1],
		&procedure[i].operation[2],
		&procedure[i].operation[3],
		&procedure[i].x, &procedure[i].y);

	segment_tree_build(nel);
	execute(procedure, procedureCount, nel);

	free(base);
	free(procedure);
	free(tree);
	return 0;
}
