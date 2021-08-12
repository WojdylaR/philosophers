#include "../include/philosophers.h"

void    end_simu(t_param *param)
{
    int j;

    j = 0;
    param->t_die = -1;
    while (j < param->nb_p)
    {
        pthread_detach(param->str_ph[j].id_th);
        j++;
    }
    return ;
}

void    *thread_philo(void *temp)
{
	t_philo	*ph;

	ph = temp;
    while (ph->str_pa->t_die > 0 && ph->nb_eat != 0)
    {
        ft_eat(ph);
		ph->nb_eat++;
        ft_sleep(ph);
        ft_think(ph);
    }
    return (0);
}

void    check_death(t_param *param)
{
    int i;
    int c;
    int delta;

    c = 0;
    while (1)
    {
        i = -1;
        while (++i < param->nb_p)
        {
            pthread_mutex_lock(&param->str_ph->eat);
            delta = get_timestamp() - param->str_ph[i].l_eat;
            pthread_mutex_unlock(&param->str_ph->eat);
            if (delta > param->t_die)
            {
                printf("%d %d died\n", get_timestamp(), param->str_ph[i].id);
                return (end_simu(param));
            }
            if (param->str_ph[i].nb_eat == 0)
                c++;
        }
        if (c == param->nb_p)
            return (end_simu(param));
        ft_usleep(1);
    }
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
        pthread_create(&ph->id_th, NULL, &thread_philo, &ph[i]);
    check_death(param);
	return (1);
}