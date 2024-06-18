#include <stdio.h>
#include <stdlib.h>

int uadd_ok(unsigned x, unsigned y);

int main(int argc, char **argv)
{
  if (argc != 3)
    return 1;

  printf("%d\n", uadd_ok(atoi(argv[1]), atoi(argv[2])));

  return 0;
}

int uadd_ok(unsigned x, unsigned y)
{
  unsigned result;
  result = x + y;

  if (result < x)
  {
    return 0;
  }
  else 
  {
    return 1;
  }
}
