#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <alloca.h>
#include <limits.h>

void heeapsort (void *pbase, size_t total_elems, size_t size, int (*compare)(const void *a, const void *b));

#define SWAP(a, b, size)                                                      \
  do                                                                              \
    {                                                                              \
      size_t __size = (size);                                                      \
      char *__a = (a), *__b = (b);                                              \
      do                                                                      \
        {                                                                      \
          char __tmp = *__a;                                                      \
          *__a++ = *__b;                                                      \
          *__b++ = __tmp;                                                      \
        } while (--__size > 0);                                                      \
    } while (0)

#define MAX_THRESH 4

typedef struct
  {
    char *lo;
    char *hi;
  } stack_node;

#define STACK_SIZE        (CHAR_BIT * sizeof (size_t))
#define PUSH(low, high)        ((void) ((top->lo = (low)), (top->hi = (high)), ++top))
#define        POP(low, high)        ((void) (--top, (low = top->lo), (high = top->hi)))
#define        STACK_NOT_EMPTY        (stack < top)

void heeapsort (void *pbase, size_t total_elems, size_t size, int (*compare)(const void *a, const void *b))
{
  char *base_ptr = (char *) pbase;
  const size_t max_thresh = MAX_THRESH * size;
  if (total_elems == 0)
    return;
  if (total_elems > MAX_THRESH)
    {
      char *lo = base_ptr;
      char *hi = &lo[size * (total_elems - 1)];
      stack_node stack[STACK_SIZE];
      stack_node *top = stack;
      PUSH (NULL, NULL);
      while (STACK_NOT_EMPTY)
        {
          char *left_ptr;
          char *right_ptr;
          char *mid = lo + size * ((hi - lo) / size >> 1);
          if ((*compare) ((void *) mid, (void *) lo) < 0)
            SWAP (mid, lo, size);
          if ((*compare) ((void *) hi, (void *) mid) < 0)
            SWAP (mid, hi, size);
          else
            goto jump_over;
          if ((*compare) ((void *) mid, (void *) lo) < 0)
            SWAP (mid, lo, size);
        jump_over:;
          left_ptr  = lo + size;
          right_ptr = hi - size;
          do
            {
              while ((*compare) ((void *) left_ptr, (void *) mid) < 0)
                left_ptr += size;
              while ((*compare) ((void *) mid, (void *) right_ptr) < 0)
                right_ptr -= size;
              if (left_ptr < right_ptr)
                {
                  SWAP (left_ptr, right_ptr, size);
                  if (mid == left_ptr)
                    mid = right_ptr;
                  else if (mid == right_ptr)
                    mid = left_ptr;
                  left_ptr += size;
                  right_ptr -= size;
                }
              else if (left_ptr == right_ptr)
                {
                  left_ptr += size;
                  right_ptr -= size;
                  break;
                }
            }
          while (left_ptr <= right_ptr);
          if ((size_t) (right_ptr - lo) <= max_thresh)
            {
              if ((size_t) (hi - left_ptr) <= max_thresh)
                POP (lo, hi);
              else
                lo = left_ptr;
            }
          else if ((size_t) (hi - left_ptr) <= max_thresh)
            hi = right_ptr;
          else if ((right_ptr - lo) > (hi - left_ptr))
            {
              PUSH (lo, right_ptr);
              lo = left_ptr;
            }
          else
            {
              PUSH (left_ptr, hi);
              hi = right_ptr;
            }
        }
    }

#define min(x, y) ((x) < (y) ? (x) : (y))
  {
    char *const end_ptr = &base_ptr[size * (total_elems - 1)];
    char *tmp_ptr = base_ptr;
    char *thresh = min(end_ptr, base_ptr + max_thresh);
    char *run_ptr;
    for (run_ptr = tmp_ptr + size; run_ptr <= thresh; run_ptr += size)
      if ((*compare) ((void *) run_ptr, (void *) tmp_ptr) < 0)
        tmp_ptr = run_ptr;
    if (tmp_ptr != base_ptr)
      SWAP (tmp_ptr, base_ptr, size);
    run_ptr = base_ptr + size;
    while ((run_ptr += size) <= end_ptr)
      {
        tmp_ptr = run_ptr - size;
        while ((*compare) ((void *) run_ptr, (void *) tmp_ptr) < 0)
          tmp_ptr -= size;
        tmp_ptr += size;
        if (tmp_ptr != run_ptr)
          {
            char *trav;
            trav = run_ptr + size;
            while (--trav >= run_ptr)
              {
                char c = *trav;
                char *hi, *lo;
                for (hi = lo = trav; (lo -= size) >= tmp_ptr; hi = lo)
                  *hi = *lo;
                *hi = c;
              }
          }
      }
  }
}

struct Point3D {
	double x, y, z;
};

struct token {
  int size;
  char string[1024];
};

int compare(const void *a, const void *b){
    if (a == b) return 0;
    return a < b ? -1 : 1;
}

void hsortheap(struct token *base, int root, int bottom,
               int (*compare)(const void *a, const void *b)) {
  int maxChild;
  int done = 0;
  while ((root * 2 <= bottom) && (!done)) {
    if (root * 2 == bottom)
      maxChild = root * 2;
    else if (base[root * 2].size > base[root * 2 + 1].size)
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    void *argument1;
    void *argument2;
    if (base[root].size < base[maxChild].size) {
      int temp = base[root].size;
      base[root].size = base[maxChild].size;
      base[maxChild].size = temp;
      char tempstr[1024];
      strcpy(tempstr, base[root].string);
      strcpy(base[root].string, base[maxChild].string);
      strcpy(base[maxChild].string, tempstr);
      root = maxChild;
    } else
      done = 1;
  }
}

void heapsort(void *base, size_t nel, size_t width,
           int (*compare)(const void *a, const void *b)) {
             
  struct token *ptrbase;
  ptrbase = (struct token *)base;
  for (int i = (nel / 2); i >= 0; i--) hsortheap(ptrbase, i, nel - 1, compare);
  for (int i = nel - 1; i >= 1; i--) {
    int temp = ptrbase[0].size;
    ptrbase[0].size = ptrbase[i].size;
    ptrbase[i].size = temp;
    char tempstr[1024];
    strcpy(tempstr, ptrbase[0].string);
    strcpy(ptrbase[0].string, ptrbase[i].string);
    strcpy(ptrbase[i].string, tempstr);
    hsortheap(ptrbase, 0, i - 1, compare);
  }
}

void siftDown(int *base, int root, int bottom)
{
  int maxChild;
  int done = 0;
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom)
      maxChild = root * 2;
    else if (base[root * 2] > base[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    if (base[root] < base[maxChild]) 
    {
      int temp = base[root];
      base[root] = base[maxChild];
      base[maxChild] = temp;
      root = maxChild;
    }
    else
      done = 1;
  }
}

void swap(int *a, int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void hsort(void *base, size_t nel, size_t width,
           int (*compare)(const void *a, const void *b)) 
{
  if (width == sizeof(struct Point3D)) {
    heeapsort(base, nel, width, compare);
  } else if (width == sizeof(char)) {
    heeapsort(base, nel, width, compare);
  } else {
  int temp;
  for (int i = (nel / 2); i >= 0; i--)
    siftDown(base, i, nel - 1);
  for (int i = nel - 1; i >= 1; i--)
  {
    swap(base, 0, i);
    siftDown(base, 0, i - 1);
  }
  }
}

int main() {

  int n = 0;
  char buffer[1024];

  scanf("%d", &n);

  struct token *array = (struct token *)malloc(n * sizeof(struct token));

  for (int i = 0; i < n; i++) {

    scanf("%s", array[i].string);

    array[i].size = 0;

    for (int j = 0; j < strlen(array[i].string); j++) {

      if (array[i].string[j] == 'a') {
        array[i].size++;
      }

    }
  }

  heapsort(array, n, sizeof(array), compare);
  for (int i = 0; i < n; i++) {
    printf("%s\n", array[i].string);
  }
  free(array);
  return 0;
}
