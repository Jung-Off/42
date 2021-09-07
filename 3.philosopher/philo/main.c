/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:58 by jji               #+#    #+#             */
/*   Updated: 2021/09/07 11:02:37 by jji              ###   ########.fr       */
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

	if(ac != 5 && ac != 6)
		error_print();
	philo = (t_philo *)malloc(sizeof(t_philo));
	
	if(ac == 5)
		philo->option = OPTION_OFF;
	else
	{	
		philo->option = OPTION_ON;
		printf("");
	}
	philo->number_of_philosophers = philo_atoi(av[1]);
	philo->time_to_die = philo_atoi(av[2]);
	philo->time_to_eat = philo_atoi(av[3]);
	philo->time_to_sleep = philo_atoi(av[4]);
	//여기서 문제가 av[5]라는 것이 인자가 4개일때는 없어서 5개일 때는 문제 없지만 4개일 때는 segfault가 난다
	//if 때문에 접근 자체를 못하는 상황이 아닌가? 그러면 이것을 어떻게 처리를 해주어야 하지요?!@
	philo->number_of_must_eat = philo_atoi(av[ac - 1]);
	
	/*if(OPTION_ON)
		philo->number_of_must_eat = philo_atoi(av[ac + 1]);
	else
		philo->number_of_must_eat = 0;
	*/

	return (philo);
}
	
int main(int argc, char *argv[])
{
	t_philo *philo;
	philo =	philo_init(argc, argv);

	printf("%d\n", philo->option);
	printf("%d\n%d\n%d\n%d\n%d ", philo->number_of_philosophers,
			philo->time_to_die, philo->time_to_eat, philo->time_to_sleep,
			philo->number_of_must_eat);

}
