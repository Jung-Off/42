/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:58 by jji               #+#    #+#             */
/*   Updated: 2021/09/09 19:26:48 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void error_print(void)
{
	printf("error argc count\n");
	exit(1);
}

int	philo_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		philo_isspace(char ch)
{
	if (ch == ' ')
		return (1);
	if (ch == '\f')
		return (1);
	if (ch == '\n')
		return (1);
	if (ch == '\r')
		return (1);
	if (ch == '\t')
		return (1);
	if (ch == '\v')
		return (1);
	return (0);
}

int philo_atoi(char *str)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while (philo_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (philo_isdigit(*str))
	{
		num *= 10;
		num += (*(str++) - '0');
	}
	return (num * sign);
}


t_philo *philo_init(int ac, char *av[])
{
	t_philo *philo;
	t_status status[philo_atoi(av[1])];

	philo = (t_philo *)malloc(sizeof(t_philo));
	
	if(ac == 5)
		philo->option = OPTION_OFF;
	else
		philo->option = OPTION_ON;
	
	philo->number_of_philosophers = philo_atoi(av[1]);
	philo->time_to_die = philo_atoi(av[2]);
	philo->time_to_eat = philo_atoi(av[3]);
	philo->time_to_sleep = philo_atoi(av[4]);

	philo->eat_count = philo_atoi(av[ac - 1]);
	
	/*if(philo->option)
		philo->eat_count = philo_atoi(av[5]);
	else
		philo->eat_count = 0;
	*/
		int i = 0;

	philo->status = status;

	while(i < philo->number_of_philosophers)
	{
		philo->status[i].die = 0;
		philo->status[i].hungry = 0;
		++i;
	}
	return (philo);
}
	
int main(int argc, char *argv[])
{
	t_philo *philo;

	if(argc != 5 && argc != 6)
		error_print();
	
	philo =	philo_init(argc, argv);


	printf("%d\n", philo->option);
	printf("philo numbers :%d\n die time : %d\n eat time : %d\n sleep time : %d\n eat count : %d\n", 
			philo->number_of_philosophers, philo->time_to_die, 
			philo->time_to_eat, philo->time_to_sleep, philo->eat_count);
	
	int i = 0;	
	while(i < philo->number_of_philosophers)
	{
		printf(" %d : die : %d  hungry : %d\n", i, philo->status[i].die ,philo->status[i].hungry); 
		++i;
	}
}
