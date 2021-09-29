/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:58 by jji               #+#    #+#             */
/*   Updated: 2021/09/29 17:19:48 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*start(void *input_philo)
{
	t_philo	*philo;

	philo = input_philo;
	if (philo->info->num_to_philo == 1)
		check_except(philo);
	if (philo->idx % 2 == 1)
		ft_stop(philo->info->time_to_eat);
	while (philo->info->death == LIVE)
	{
		if (philo_eat(philo))
			return (NULL);
		if (philo->info->death || philo->done_eating)
			return (NULL);
		if (philo_sleep(philo))
			return (NULL);
		if (philo->info->death || philo->done_eating)
			return (NULL);
		if (philo_think(philo))
			return (NULL);
	}
	return (NULL);
}

void	*check(void *input_philo)
{
	t_philo	*philo;

	philo = input_philo;
	while (philo->info->death == LIVE)
	{
		pthread_mutex_lock(&philo->eating);
		if (check_death(philo))
		{
			print_die_message(philo);
			pthread_mutex_unlock(&philo->eating);
			return (NULL);
		}
		if (check_fin(philo))
		{
			print_fin_message(philo);
			pthread_mutex_unlock(&philo->eating);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->eating);
		usleep(100);
	}
	return (NULL);
}

void	pthread_start(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num_to_philo)
	{
		pthread_create(&(philo[i].thread), NULL, &start, &philo[i]);
		pthread_create(&(philo[i].monitor), NULL, &check, &philo[i]);
		++i;
	}
	i = 0;
	while (i < info->num_to_philo)
	{
		pthread_join(philo[i].thread, NULL);
		pthread_join(philo[i].monitor, NULL);
		++i;
	}
}

void pthread_end(t_info *info, t_philo *philo)
{
	int i;

	i = 0;
	pthread_mutex_destroy(&(info->message));
	while (i < info->num_to_philo)
	{
		pthread_mutex_destroy(&(philo[i].eating));
		pthread_mutex_destroy(&(info->fork[i]));
		philo[i].info = NULL;
		++i;
	}
	free(info->fork);
	free(info);
	free(philo);
}

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_info	*info;

	if (check_argc(argc))
		return (0);
	if (init_info(argc, argv, &info) || init_thread(info, &philo))
		return (0);
	if (init_mutex(info, philo))
		return (0);
	pthread_start(info, philo);
	pthread_end(info, philo);
}
