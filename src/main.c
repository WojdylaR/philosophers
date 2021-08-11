#include "../include/philosophers.h"

int main(int argc, char **argv)
{
	t_param *lst;

	lst = malloc(sizeof(t_param));
	if (!(lst))
		return (0);
	if (ft_pars(argc, argv, lst) == -1)
	{
		printf("Bad arg ! Should be : number of philo, time to die, time to ");
		printf("eat, time to sleep, \"number of times philosopher must eat\"");
		return (0);
	}
	ft_init_thread(lst);
	return (0);
}