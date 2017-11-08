
int		ft_atoi(const char *nptr)
{
	int	i;
	int neg;
	int	var;

	i = 0;
	neg = 0;
	var = 0;

	while (((nptr[i] >= 8) && (nptr[i] <= 13)) || (nptr[i] == ' '))
		i++;

	if (nptr[i] == '-')
		neg = -1;

	if ((nptr[i] == '-') || (nptr[i] == '+'))
		i++;

	while (((nptr[i] >= '0') && (nptr[i] <= '9')))
	{
		var = var * 10 + (nptr[i] - '0');
		i++;
	}
	if (neg == -1)
		return (-var);
	else
		return (var);
}