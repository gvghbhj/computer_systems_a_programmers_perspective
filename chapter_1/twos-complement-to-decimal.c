#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_BITS 64

int main(void)
{
  char num_bits[2]; // the data will be structured num_bits,binary so this stores the number of bits in the binary
  
  char c;
  int i = 0;
  
  while((c = getchar()) != EOF && i < 2 && c != ',')
  {
    num_bits[i] = c;
    i++;
  }

  if (atoi(num_bits) > MAX_NUM_BITS || atoi(num_bits) <= 0)
  {
    printf("EXCEEDS RANGE\n");
    exit(EXIT_FAILURE);
  }
  
  if (i == 2) 
  {
    c = getchar();
  }
    
  i = 0;
  char binary_buffer[atoi(num_bits) + 1];

  
  while((c = getchar()) != EOF && i < atoi(num_bits))
  {
    binary_buffer[i] = c;
    i++;
  }
  binary_buffer[i] = '\0';
  
  if (i != atoi(num_bits))
  {
    printf("NEED MORE INFO\n");
    exit(EXIT_FAILURE);
  }
  

  i = 0; // stored as big endian in this code

  long int number = 0;
  int binary_length = strlen(binary_buffer) - 1;
    
  if (binary_buffer[i] == '1')
  {
    number += (-1 * (1 << (binary_length - i))); // bit shift = multiplying by 2^i
  }
  else if (binary_buffer[i] != '0')
  {
    printf("NOT IN BINARY FORMAT");
    exit(EXIT_FAILURE);
  }
  
  i++;
  for (; i <= binary_length; i++)
  {
    if (binary_buffer[i] == '1')
    {
      number += (1 << (binary_length - i));
    }
    else if (binary_buffer[i] != '0')
    {
      printf("NOT IN BINARY FORMAT");
      exit(EXIT_FAILURE);
    }
  }

  printf("%ld\n", number);

  exit(EXIT_SUCCESS);
}
