// A simple program that takes an array of signed decimal and converts it to an unsigned decimal, for a known number of bits and vice versa


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MIN_ARGS 4
#define ANSI_ESCAPE_CODE_BLUE "\033[34;1m"
#define ANSI_ESCAPE_CODE_RESET "\033[0m"

unsigned int convert_signed(int number, unsigned int bytes);
int convert_unsigned(unsigned int number, unsigned int bytes);

int main(int argc, char *argv[])
{
  unsigned int num_bytes;
  num_bytes = (unsigned int) atoi(argv[2]);

  if (argc < MIN_ARGS)
  {
    exit(EXIT_FAILURE);
  }
  
  if (toupper(argv[1][0]) == 'U')
  {
    for (int i = 3; i < argc; i++)
    {
      printf("converted number: ");
      printf(ANSI_ESCAPE_CODE_BLUE "%d\n" ANSI_ESCAPE_CODE_RESET, convert_signed(atoi(argv[i]), num_bytes));
    }
  }
  else if (toupper(argv[1][0]) == 'S')
  {
    for (int i = 3; i < argc; i++)
    {
      printf("converted number: ");
      printf(ANSI_ESCAPE_CODE_BLUE "%d\n" ANSI_ESCAPE_CODE_RESET, convert_unsigned((unsigned int) atoi(argv[i]), num_bytes));
    }
  }
  else 
  {
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}

unsigned int convert_signed(int number, unsigned int bytes)
{
  int max = pow(2, bytes);
  
  if (number > max - 1 || number < (-1 * max))
  {
    printf("incorretct formatting, this number is not representable with the number of bytes specified");
    exit(EXIT_FAILURE);
  }

  if (number >= 0)
  {
    return (unsigned int) number;
  }
  else
  {
    return (unsigned int) (number + max);
  }
}

int convert_unsigned(unsigned int number, unsigned int bytes)
{
  unsigned int max = pow(2, bytes);
  unsigned int tmax = pow(2, bytes - 1);

  if (number > max)
  {
    printf("incorretct formatting, this number is not representable with the number of bytes specified");
    exit(EXIT_FAILURE);
  }

  if (number < tmax)
  {
    return (int) number;
  }
  else 
  {
   return (int) (number - max);
  }
}
