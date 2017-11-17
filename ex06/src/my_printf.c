void	ft_putchar(char c)
{
  write(1, &c, 1);
}

void	my_printf(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}



















