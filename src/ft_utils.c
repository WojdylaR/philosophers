#include "../include/philosophers.h"

void	ft_putchar_fd(char c, int i)
{
	write(i, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 10 && n >= 0)
		ft_putchar_fd(n + 48, fd);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * (-1), fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	ft_putstr_philo(char *str, int t, int p)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	ft_putnbr_fd(p, 1);
	write(1, " ms ", 6);
	ft_putnbr_fd(t, 1);
	write(1, str, x);
}

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long int	ft_atoi(const char *str)
{
	int				i;
	long long int	nbr;
	int				negative;

	nbr = 0;
	negative = 1;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v')
		|| (str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	return (nbr * negative);
}