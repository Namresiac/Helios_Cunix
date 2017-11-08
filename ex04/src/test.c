
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "test.h"

int   my_atoi(const char *nptr)
 {
   int i;
   int n;
   int v;
 
   i = 0;
   n = 0;
   v = 0;
   while (((nptr[i] >= 8) && (nptr[i] <= 13)) || (nptr[i] == ' '))
   {
     i++;
   }
   if (nptr[i] == '-')
     n = -1;
   if ((nptr[i] == '-') || (nptr[i] == '+'))
     i++;
   while (((nptr[i] >= '0') && (nptr[i] <= '9')))
   {
     v = v * 10 + (nptr[i] - '0');
     i++;
   }
   if (n == -1)
     return (-v);
   else
     return (v);
 }


char* my_itoa( int nmb)
{
    int copy = nmb;
    int count = 0;
    int i;
    char *res;

    while ( copy > 0 )
    {
        count++;
        copy /= 10;
    }

    res = (char*) malloc ((count + 1) * sizeof(char));

    for (i = count - 1; i >= 0; i--)
    {
        *(res + i) = nmb%10 + '0';
        nmb /= 10;
    }
      return (res);
}


int   test_small()
{
  assert(my_atoi("0") == 0);
  assert(my_atoi("-0") == 0);
  assert(my_atoi("-1") == -1);
  assert(my_atoi("42") == 42);
  assert(my_atoi("-42") == -42);
  assert(my_atoi("1k") == 1);
}

int           test_long()
{
  assert(my_atoi("123456789") == 123456789);
  assert(my_atoi("2147483647") == 2147483647);
  assert(my_atoi("-2147483648") == -2147483648);
  assert(my_atoi("4294967296") == 0);
  assert(my_atoi("4294967298") == 2);
  assert(my_atoi("ABC") == 0);
  assert(my_atoi("0") == atoi("0"));
}

int           test_verif()
{
  assert(atoi("0") == 0);
  assert(atoi("-0") == 0);
  assert(atoi("-1") == -1);
  assert(atoi("42") == 42);
  assert(atoi("-42") == -42);
  assert(atoi("1k") == 1);
  assert(atoi("123456789") == 123456789);
  assert(atoi("2147483647") == 2147483647);
  assert(atoi("-2147483648") == -2147483648);
  assert(atoi("4294967296") == 0);
  assert(atoi("4294967298") == 2);
  assert(atoi("ABC") == 0);
  assert(atoi("1234QWERTY1234") == 1234);
}

int     test_itoa()
{

/*  assert(strcmp(my_itoa(0), "0") == 0);*/
  assert(strcmp(my_itoa(1), "1") == 0);
  assert(strcmp(my_itoa(32), "32") == 0);
  assert(strcmp(my_itoa(12345678), "12345678") == 0);
  assert(strcmp(my_itoa(-34), "-34") == 0);
  assert(strcmp(my_itoa(-12345678), "-12345678") == 0);
  assert(strcmp(my_itoa(-1234567890), "-1234567890") == 0);
}

int   main(int argc, char *argv[])
{
  test_small();
  test_long();
  test_verif();
  test_itoa();
  return(0);
}
