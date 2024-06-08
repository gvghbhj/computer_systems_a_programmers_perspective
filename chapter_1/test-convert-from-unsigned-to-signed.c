#include <stdio.h>
#include <limits.h>

int main(void)
{
  struct numbers 
  {
    int x;
    unsigned int ux;
  };

  struct numbers nums[4];

  nums[0].x = 10;
  nums[0].ux = (unsigned int) nums[0].x;

  nums[1].x = -10;
  nums[1].ux = (unsigned int) nums[1].x;

  nums[2].x = INT_MAX;
  nums[2].ux = (unsigned int) nums[2].x;

  nums[3].x = INT_MIN;
  nums[3].ux = (unsigned int) nums[3].x;

  for (int i = 0; i < 4; i++)
  {
    printf("Int: %d, and usigned int: %d\n", nums[i].x, nums[i].ux);
  }

  return 0;
}
