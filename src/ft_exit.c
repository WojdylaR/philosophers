#include "../include/philosophers.h"

void	ft_exit(t_param *param, int t)
{
	param->nb_eat++;
	if (t == -1)
	{
		printf("un philo est mort !\n");
	}
	exit(EXIT_SUCCESS);
}