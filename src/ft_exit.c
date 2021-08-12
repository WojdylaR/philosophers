#include "../include/philosophers.h"

void	ft_free(t_param *param)
{
	if (param)
	{
		if (param->str_ph)
			free(param->str_ph);
		if (param->fork)
			free(param->fork);
		free(param);
	}
}

void	ft_exit(t_param *param, int t)
{
	param->nb_eat++;
	if (t == -1)
		printf("un philo est mort !\n");
	if (t == -3)
		printf("Valeur inferieur a 0 ou superieur a INT_MAX");
	if (t == -2)
	{
		printf("Bad arg ! Should be : number of philo, time to die, time to ");
		printf("eat, time to sleep, \"number of times philosopher must eat\"");
	}
	ft_free(param);
	exit(EXIT_SUCCESS);
}