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

void init_mutex(t_info info, t_philo *philo)
{
	int i;
	pthread_mutex_t *forks;
	
	i = 0;
	forks = make_forks(info);
	while (i < info.num_to_philo)
	{
		pthread_mutex_init(&(forks[i]), NULL);
		++i;
	}
	philo->fork = forks;

	put_the_fork(philo, info, forks);
}

//1)
void	init_thread(t_info *info, t_philo **philo)
{
	int				i;

	i = 0;
	*philo = make_philo(*info);
	while (i < info->num_to_philo)
	{
		(*philo)[i].idx = i + 1;
		(*philo)[i].info = info;
		++i;
	}
}

void	init_info(int ac, char *argv[], t_info **info)
{
	valid_input(argv);
	*info = make_info();
	(*info)->num_to_philo = philo_atoi(argv[1]);
	(*info)->time_to_die = philo_atoi(argv[2]);
	(*info)->time_to_eat = philo_atoi(argv[3]);
	(*info)->time_to_sleep = philo_atoi(argv[4]);
	if (ac == 6)
		(*info)->num_of_eat = philo_atoi(argv[ac - 1]);
	else
		(*info)->num_of_eat = 0;
	(*info)->death = LIVE;
}
