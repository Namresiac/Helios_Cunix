

int my_putc(char c)
{
  write(1, &c,1);
    return 0;
}

int my_puts(const char *s)
{
  while(*s)
  {
    my_putc(*s);
    s++;
  }
}
