#include "../include/philosophers.h"

int    get_timestamp(void)
{
    struct timeval    curr_time;
    static int        timebase = 0;

    if (timebase == 0)
    {
        gettimeofday(&curr_time, NULL);
        timebase = curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000;
    }
    gettimeofday(&curr_time, NULL);
    return (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000 - timebase);
}

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '-')
		return (1);
	return (0);
}

void	ft_usleep(int time_in_ms)
{
	int	start_time;

	start_time = get_timestamp();
	while ((get_timestamp() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
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