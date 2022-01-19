/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:41:05 by jji               #+#    #+#             */
/*   Updated: 2021/09/16 14:41:06 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void valid_input(char *av[])
{
	int i;
	int j;
	int len;

	i = 1;
	while(av[i] != NULL)
	{
		j = 0;
		len = philo_strlen(av[i]);
		while(j < len)
		{
			if(len != 1)
			{	
				if ((j == 0) && (av[i][j] == '-' || av[i][j] == '+'))
					j++;
			}
			if (philo_isdigit(av[i][j]))
				error_print(2);
			++j;
		}
		++i;
	}
}

t_info *make_info()
{
	t_info *info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
		error_print(4);
	return (info);
}

t_philo	*make_philo(t_info info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * info.num_to_philo);
	if (philo == NULL)
		error_print(4);
	return (philo);
}

pthread_mutex_t	*make_forks(t_info info)
{
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info.num_to_philo);
	if (forks == NULL)
		error_print(4);
	return (forks);
}

//1)
void	put_the_fork(t_philo *philo, t_info info, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < info.num_to_philo)
	{	
		philo[i].l_fork = &(forks[i]);
		philo[i].r_fork = &(forks[(i + 1) % info.num_to_philo]);
		++i;
	}
}
//2)
/*
void	put_the_fork(t_philo **philo, t_info info, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < info.num_to_philo)
	{	
		(*philo[i]).l_fork = &(forks[i]);
		(*philo[i]).r_fork = &(forks[(i + 1) % info.num_to_philo]);
		++i;
	}
}
*/