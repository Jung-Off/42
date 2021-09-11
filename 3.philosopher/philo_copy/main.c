/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:58 by jji               #+#    #+#             */
/*   Updated: 2021/09/11 19:25:36 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void error_print(int err_num)
{
	if(err_num == 1)
		printf("error argc count\n");
	else if(err_num == 2)
		printf("error you input char\n");
	else if(err_num == 3)
		printf("error input out of range\n");
	else if(err_num == 4)
		printf("error malloc assignment\n");
	exit(1);
}

int	philo_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	philo_isspace(char ch)
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
	int			isnum;
	int			minus;
	long long	num;

	isnum = 0;
	minus = 1;
	num = 0;
	while (philo_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str)
	{
		if(!philo_isdigit(*str))
			error_print(2);
		num = num * 10 + (*(str++) - '0');
		isnum = 1;
	}
	num *= minus;
	if (isnum == 0)
		error_print(2);
	else if (num > 2147483637 || num < -2147483648)
		error_print(3);
	return (num);
}
	
int make_philo(t_philo **philo, t_info info)
{
	*philo = (t_philo *)malloc(sizeof(t_philo) * info.num_to_philo);
	if (*philo == NULL)
		return (1);
	else
		return (0);
}

int make_forks(pthread_mutex_t **forks, t_info info)
{
	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info.num_to_philo);
	if (*forks == NULL)
		return (1);
	else
		return (0);
}

void put_the_fork(t_philo **philo, t_info info, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < info.num_to_philo)
	{	
		if (i == 0)
		{
			(*philo)[i].l_fork = &(forks[info.num_to_philo - 1]);
			(*philo)[i].r_fork = &(forks[0]);
		}
		else
		{
			(*philo)[i].l_fork = &(forks[i - 1]);
			(*philo)[i].r_fork = &(forks[i]);
		}
		++i;
	}
}

void init_thread(t_philo **philo, t_info info)
{
	int i;
	pthread_mutex_t *forks;

	i = 0;
	if (make_philo(philo, info))
		return (error_print(4));
	if (make_forks(&forks, info))
		return (error_print(4));
	while (i < info.num_to_philo)
	{
		(*philo)[i].idx = i + 1;
		pthread_mutex_init(&(forks[i]), NULL);
		(*philo)[i].info = &info;
		++i;
	}
	(*philo)->fork = forks;
	put_the_fork(philo, info, forks);
}

void init_info(int ac, char *argv[], t_info *info)
{
	if(ac == 5)
		info->option = OPTION_OFF;
	else
		info->option = OPTION_ON;
	info->num_to_philo = philo_atoi(argv[1]);
	info->time_to_die = philo_atoi(argv[2]);
	info->time_to_eat = philo_atoi(argv[3]);
	info->time_to_sleep = philo_atoi(argv[4]);
	info->num_of_eat = philo_atoi(argv[ac - 1]);
}

void *print(void *arg)
{
	t_philo *status = (t_philo *)arg;

	printf("idx :%d\n", status->idx);
	printf("forks : %p %p\n", status->l_fork, status->r_fork);
	//printf("option : %d\n", status->info->option);

	printf("num : %d\n", status->info->num_to_philo);
	printf("die : %d\n", status->info->time_to_die);
	printf("eat : %d\n", status->info->time_to_eat);
	printf("sleep : %d\n", status->info->time_to_sleep);
	printf("count : %d\n", status->info->num_of_eat);

	printf("\n\n");
	return 0;
}

int main(int argc, char *argv[])
{
	t_philo *philo;
	t_info	info;
	int i;

	if(argc != 5 && argc != 6)
		error_print(1);
	init_info(argc, argv, &info);
	
	init_thread(&philo, info);
	
	i = 0;
	while(i < info.num_to_philo)
	{
		pthread_create(&(philo[i].thread), NULL, &print, &philo[i]);
		pthread_join(philo[i].thread, NULL);
		++i;
	}

	//start(philo);

}
