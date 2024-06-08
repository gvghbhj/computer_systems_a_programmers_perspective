#include <stdio.h>

int main(void)
{
  int x = 0x0000000087654321;

  printf("%x\n", (~x) ^ 0xff);
  printf("%x\n", x ^ (~0xff));

  return 0;
}
