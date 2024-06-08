#include <stdio.h>
#include <stdlib.h>

void inplace_swap(int *x, int *y);

int main(int argc, char *argv[])
{
  int int_argv[argc - 1];

  for (int i = 1; i < argc; i++)
  {
    int_argv[i - 1] = atoi(argv[i]);
  }

  int first, last;
  for (first = 0, last = argc - 2; first < last; first++, last--)
  {

    printf("Initially: first/%d, last/%d\n", int_argv[first], int_argv[last]);
    inplace_swap(&(int_argv[first]), &(int_argv[last]));

    printf("after: first/%d, last/%d\n\n", int_argv[first], int_argv[last]);
  }
  
  for (int i = 0; i < argc - 1; i++)
  {
    printf("%d", int_argv[i]);
  }

  printf("\n");

  return 0;
}

void inplace_swap(int *x, int *y)
{
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}
