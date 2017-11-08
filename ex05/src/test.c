
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "test.h"

int my_putc(char c)
{
  write(1, &c, 1);
    return 0;
}

int my_puts(const char *s)
{
  int i;
  i = 0;

  while(s[i] != '\0')
  {
    my_putc(s[i]);
    i++;
  }
}

int   test_all()
{
  my_puts("Nine people can't make a baby in a month.\n");
  my_puts("There are only two hard things in Computer Science: cache invalidation and naming things.");
  my_puts("");
  my_puts("Measuring programming progress by lines of code is like measuring aircraft building progress by weight.");
  my_puts("*********************************************************************************");
}

int           test_verif()
{
  puts("Nine people can't make a baby in a month.\n");
  puts("There are only two hard things in Computer Science: cache invalidation and naming things.");
  puts("");
  puts("Measuring programming progress by lines of code is like measuring aircraft building progress by weight.");
  puts("*********************************************************************************");
}

int   main(int argc, char *argv[])
{
  test_all();
  test_verif();
  return(0);
}
