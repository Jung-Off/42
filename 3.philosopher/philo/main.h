#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>

typedef struct s_philo
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_must_eat;
}		t_philo;

#endif
