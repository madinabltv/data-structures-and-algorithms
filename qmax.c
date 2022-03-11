#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int max;
  int data;
  struct node* next;
};

void push(struct node** top, int data);
int pop(struct node** top);

struct queue {
  struct node* stack1;
  struct node* stack2;
};

struct queue* initQueue() {
  struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
  queue->stack1 = NULL;
  queue->stack2 = NULL;
  return queue;
}

void enqueue(struct queue* q, int x) { push(&q->stack1, x); }

void dequeue(struct queue* q) {
  int x;
  if (q->stack1 == NULL && q->stack2 == NULL) {
    printf("Очередь пуста\n");
    return;
  }
  if (q->stack2 == NULL) {
    while (q->stack1 != NULL) {
      x = pop(&q->stack1);
      push(&q->stack2, x);
    }
  }
  x = pop(&q->stack2);
  printf("%d\n", x);
}

void queueEmpty(struct queue* q) {
  if (q->stack1 == NULL && q->stack2 == NULL) {
    printf("true\n");
    return;
  } else {
    printf("false\n");
    return;
  }
}

void maximum(struct queue* q) {
  if (q->stack1 == NULL && q->stack2 == NULL) {
    printf("Очередь пуста\n");
    return;
  }
  if (q->stack1 == NULL) {
    printf("%d\n", q->stack2->max);
  } else if (q->stack2 == NULL) {
    printf("%d\n", q->stack1->max);
  } else {
    if (q->stack1->max > q->stack2->max) {
      printf("%d\n", q->stack1->max);
    } else {
      printf("%d\n", q->stack2->max);
    }
  }
}

void push(struct node** top, int data) {
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  if (newnode == NULL) {
    printf("Stack overflow \n");
  }
  if ((*top) == NULL) {
    newnode->max = data;
  } else {
    if ((*top)->max < data && (*top) != NULL) {
      newnode->max = data;
    } else {
      newnode->max = (*top)->max;
    }
  }
  newnode->data = data;
  newnode->next = (*top);
  (*top) = newnode;
}

int pop(struct node** top) {
  int buff;
  struct node* t;
  if (*top == NULL) {
    printf("Stack underflow \n");
  } else {
    t = *top;
    buff = t->data;
    *top = t->next;
    free(t);
    return buff;
  }
}

void queuefree(struct queue* q) {
  while (q->stack1 != NULL) {
    pop(&q->stack1);
  }
  while (q->stack2 != NULL) {
    pop(&q->stack2);
  }
}

int main() {
  int a, n;
  char str[10];
  struct queue* q = initQueue();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    if (strstr(str, "ENQ")) {
      scanf("%d", &a);
      enqueue(q, a);
    } else if (strstr(str, "DEQ")) {
      dequeue(q);
    } else if (strstr(str, "MAX")) {
      maximum(q);
    } else if (strstr(str, "EMPTY")) {
      queueEmpty(q);
    } else {
      printf("Ошибка\n");
    }
  }
  queuefree(q);
  free(q);
  return 0;
}
