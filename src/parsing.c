#include "../include/philosophers.h"

int	init_ph(t_philo *ph, t_param *param)
{
	int	i;

	i = -1;
	param->str_ph = ph;
	param->fork = malloc(sizeof(pthread_mutex_t) * param->nb_p);
	if (!(param->fork))
		return (0);
	while (++i < param->nb_p)
	{
		ph[i].nb_eat = param->nb_eat;
		param->str_ph->l_eat = get_timestamp();
		pthread_mutex_init(&param->fork[i], NULL);
		ph[i].str_pa = param;
		ph[i].id = i + 1;
	}
	return (1);
}

void put_in_param(t_param *param, int i, char *str)
{
	int x;

	x = -1;
	while (str[++x])
		if (str[x] == '-')
			ft_exit(param, -3);
	if (i == 1)
		param->nb_p = ft_atoi(str);
	if (i == 2)
		param->t_die = ft_atoi(str);
	if (i == 3)
		param->t_eat = ft_atoi(str);
	if (i == 4)
		param->t_sleep = ft_atoi(str);
	if (i == 5)
		param->nb_eat = ft_atoi(str);
}

int ft_pars(int argc, char **argv, t_param *param)
{
	int i;
	int j;

	i = 1;
	param->nb_eat = -1;
	if (argc != 5 && argc != 6)
		return (-1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		put_in_param(param, i, argv[i]);
		i++;
	}
	return (1);
}