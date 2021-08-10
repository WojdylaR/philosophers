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

void    *thread_philo(t_philo *ph)
{
    while (1)
    {
        ft_eat(ph);
        ft_sleep(ph);
        ft_think(lst);
    }
    return (0);
}

void    ft_init_thread(t_param *param)
{
    int i;
    t_philo *ph;

    ph = malloc(sizeof(t_philo) * param->nb_p);
    if (!(ph))
        return (0);
    init_ph(ph, param);
    i = -1;
    while (++i <= param->nb_p)
    {
        pthread_create(ph, NULL, thread_philo, &ph[i]);
    }
    while (1)
    {
        
    }
}