/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:40:59 by jji               #+#    #+#             */
/*   Updated: 2021/09/16 14:41:00 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_the_fork(t_philo *philo, t_info *info, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < info->num_to_philo)
	{	
		philo[i].l_fork = &(forks[i]);
		philo[i].r_fork = &(forks[(i + 1) % info->num_to_philo]);
		++i;
	}
}

int init_mutex(t_info *info, t_philo *philo)
{
	int i;
	pthread_mutex_t *forks;
	
	i = 0;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->num_to_philo);
	if (forks == NULL)
	{
		error_print(4);
		free(info);
		free(philo);
		return (EX);
	}	
	while (i < info->num_to_philo)
	{
		pthread_mutex_init(&(forks[i]), NULL);
		++i;
	}
	info->fork = forks;
	pthread_mutex_init(&(philo->info->message), NULL);
//	pthread_mutex_init(philo->info->eating, NULL);
	put_the_fork(philo, info, forks);
	return (NEX);
}

int	init_thread(t_info *info, t_philo **philo)
{
	int				i;

	i = 0;
	*philo = (t_philo *)malloc(sizeof(t_philo) * info->num_to_philo);
	if (*philo == NULL)
	{
		free(info);
		error_print(4);
		return (EX);
	}
	while (i < info->num_to_philo)
	{
		(*philo)[i].idx = i + 1;
		(*philo)[i].info = info;
		(*philo)[i].num_of_eat = info->num_of_eat;
		(*philo)[i].done_eating = 0;
		++i;
	}
	return (NEX);
}

int		init_info(int ac, char *argv[], t_info **info)
{
	if (valid_input(argv))
	{
		error_print(2);
		return (EX);
	}
	*info = (t_info *)malloc(sizeof(t_info));
	if (*info == NULL)
	{
		error_print(4);
		return (EX);
	}
	(*info)->num_to_philo = philo_atoi(argv[1]);
	(*info)->time_to_die = philo_atoi(argv[2]);
	(*info)->time_to_eat = philo_atoi(argv[3]);
	(*info)->time_to_sleep = philo_atoi(argv[4]);
	if (ac == 6)
		(*info)->num_of_eat = philo_atoi(argv[ac - 1]);
	else
		(*info)->num_of_eat = -1;
	(*info)->death = LIVE;
	return (NEX);
}
