#include<string.h>
#include<stdio.h>

unsigned int my_strlen(char *str)
{
  int i;
  i = 0;

  while(*str)
      {
      str++;
      i++;
      }
  return i;
}

int main()
{
  printf("%d", strlen("jijijijijijdjdjdjdjdjdjjdjddjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj"));
  return 0;
}