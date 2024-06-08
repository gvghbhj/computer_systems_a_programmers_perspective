#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len);

int main(void)
{
  char *x = "hey how are you";

  show_bytes((byte_pointer) &x, strlen(x) * sizeof(char));
}

void show_bytes(byte_pointer start, int len)
{
  for (int i = 0; i < len; i++)
  {
    printf("%.2x\n", *(start + i));
  }
}

