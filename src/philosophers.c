#include "../include/philosophers.h"

int main(int argc, char **argv)
{
	if (ft_parc(argc, argv) == -1)
	{
		printf("Wrong arg ! Should be : number of philo, time to die, time to 
			eat, time to sleep, \"number of times philosopher must eat\"");
		return (0);
	}
}