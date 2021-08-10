#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

typedef struct s_philo
{
	int				id;
	pthread_t		id_th;
	pthread_mutex_t	*fork;
	t_param			str_pa;
	int				la_di;
	int				nb_eat;
}				t_philo;

typedef struct	s_param
{
	int	philo_nb;
	int	nb_p;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nb_eat;
	int	*fork;
}				t_param;	

void			init_ph(t_philo *ph, t_param *param);
long long int	ft_atoi(const char *str);
int				ft_parc(int argc, char **argv, t_param *lst);
int				ft_isdigit(int c);
void			ft_init_thread(t_param *lst);
void			ft_eat(t_philo *ph);
void			ft_sleep(t_philo *ph);
void			ft_think(t_philo *ph);
void			ft_putstr_philo(char *str, int t, int p);
int				get_timestamp(void);

#endif