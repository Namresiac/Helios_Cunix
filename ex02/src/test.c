
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "test.h"

int	my_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);

    i++;
	}
	return (0);
}

int   test_small()
{
  assert(my_strcmp("", "") == 0);
  assert(my_strcmp("A", "A") == 0);
  assert(my_strcmp("AB", "AB") == 0);
  assert(my_strcmp("AB", "AC") == -1);
  assert(my_strcmp("AB", "AA") == 1);
  assert(my_strcmp("AB", "AD") == -1);
}

int   test_long()
{
  assert(my_strcmp("HELLO WORLD", "HELLA WORLD") > 0);
  assert(my_strcmp("HELLO WORLD", "HELL WORLD") == 1);
}

int   main(int argc, char *argv[])
{
  test_small();
  test_long();
  return(0);
}
