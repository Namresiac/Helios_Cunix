#include<stdio.h>

char *strcpy(char *dest, const char *src)
{
  int i;
  i = 0;

  while(src[i])
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = src[i];
  return dest;
}

int main()
{
  printf("%s", *strcpy ("", "jeannot"));
  return 0;
}