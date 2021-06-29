#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_param
{
	int	nb_p;
	int	t_die;
	int	t_eat;
	int	t_phi;
	int	nb_eat;
}				t_param;	

#endif