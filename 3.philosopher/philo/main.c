#include "main.h"

void error_print(void)
{
	printf("error argc count\n");
}

void philo_init(int ac, char *av[])
{
	if(ac != 5 || ac != 6)
		error_print();
	
		

int main(int argc, char *argv[])
{
	t_philo philo;
	philo_init(argc, argv, philo);
}
