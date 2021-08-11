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

void    *thread_philo(void *temp)
{
	t_philo	*ph;

	ph = temp;
    while (1)
    {
        ft_eat(ph);
		ph->nb_eat++;
        ft_sleep(ph);
        ft_think(ph);
    }
    return (0);
}

int	check_death(t_param *param, int i)
{
	while (i < param->nb_p)
	{
		if (get_timestamp() - param->str_ph->l_eat > param->t_die)
			ft_exit(param, -1);
		usleep(10000);
	}
	return (1);
}

int	ft_init_thread(t_param *param)
{
    int i;
    t_philo *ph;

    ph = malloc(sizeof(t_philo) * param->nb_p);
    if (!(ph))
        return (0);
    init_ph(ph, param);
    i = -1;
    while (++i < param->nb_p)
    {
        pthread_create(&ph->id_th, NULL, &thread_philo, &ph[i]);
		usleep(1000);
	}
	while (1)
	{
		i = 0;
		check_death(param, i);
	}
	return (1);
}