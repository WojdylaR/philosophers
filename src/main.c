#include "../include/philosophers.h"

int main(int argc, char **argv)
{
	t_param *param;

	param = malloc(sizeof(t_param));
	if (!(param))
		return (0);
	if (ft_pars(argc, argv, param) == -1)
		ft_exit(param, -2);
	ft_init_thread(param);
	return (0);
}