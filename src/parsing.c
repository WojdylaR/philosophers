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
		ph[i].nb_eat = 0;
		pthread_mutex_init(&param->fork[i], NULL);
		ph[i].str_pa = param;
		ph[i].id = i + 1;
	}
	return (1);
}

void ft_error(t_param *lst, int i)
{
	if (i == -1)
	{
		free(lst);
		printf("Bad arg ! Should be : number of philo, time to die, time to ");
		printf("eat, time to sleep, \"number of times philosopher must eat\"");
	}
}

void put_in_lst(t_param *lst, int i, char *str)
{
	if (i == 1)
		lst->nb_p = ft_atoi(str);
	if (i == 2)
		lst->t_die = ft_atoi(str);
	if (i == 3)
		lst->t_eat = ft_atoi(str);
	if (i == 4)
		lst->t_sleep = ft_atoi(str);
	if (i == 5)
		lst->nb_eat = ft_atoi(str);
}

int ft_pars(int argc, char **argv, t_param *lst)
{
	int i;
	int j;

	i = 1;
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
		put_in_lst(lst, i, argv[i]);
		i++;
	}
	lst->fork = malloc(sizeof(int) * lst->nb_p + 1);
	if (!(lst->fork))
		return (-1);
	return (1);
}