#include "../include/philosophers.h"

void    ft_eat(t_philo *ph)
{
    if (!(ph->id % 2))
    {
        pthread_mutex_lock(&ph->str_pa->fork[ph->id - 1]);
        printf("%d %d has taken a fork\n", get_timestamp(), ph->id);
        pthread_mutex_lock(&ph->str_pa->fork[ph->id % ph->str_pa->nb_p]);
        printf("%d %d has taken a fork\n", get_timestamp(), ph->id);
    }
    else
    {
        pthread_mutex_lock(&ph->str_pa->fork[ph->id % ph->str_pa->nb_p]);
        printf("%d %d has taken a fork\n", get_timestamp(), ph->id);
        pthread_mutex_lock(&ph->str_pa->fork[ph->id - 1]);
        printf("%d %d has taken a fork\n", get_timestamp(), ph->id);
    }
    printf("%d %d is eating\n", get_timestamp(), ph->id);
    usleep(1000 * ph->str_pa->t_eat);
    ph->l_eat = get_timestamp(); 
    pthread_mutex_unlock(&ph->str_pa->fork[ph->id - 1]);
    pthread_mutex_unlock(&ph->str_pa->fork[ph->id % ph->str_pa->nb_p]);
}

void    ft_sleep(t_philo *ph)
{
    printf("%d %d is sleeping\n", get_timestamp(), ph->id);
    usleep(1000 * ph->str_pa->t_sleep);
}

void    ft_think(t_philo *ph)
{
    printf("%d %d is thinking\n", get_timestamp(), ph->id);
}