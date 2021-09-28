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

void *start (void *input_philo)
{
	t_philo *philo;

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

void pthread_start(t_info info, t_philo *philo)
{
	int i;

	i = 0;
	while (i < info.num_to_philo)
	{
		philo[i].time_to_0 = get_time();
		philo[i].last_meal = philo[i].time_to_0;
		pthread_create(&(philo[i].thread), NULL, &start, &philo[i]);
		//pthread_create(&(philo[i].monitor), NULL, &check, &philo[i]);
		++i;
		usleep(100);// 이것의 차이 2
	}
	i = 0;
	while (i < info.num_to_philo)
	{
		pthread_join(philo[i].thread, NULL);
		//pthread_join(philo[i].monitor, NULL);
		++i;
	}
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
	pthread_start(*info, philo);

	//free fork philo//
}


//중간에 오류가 났을때
//뮤텍스 destroy, malloc free

//마지막에
//뮤텍스 destroy, malloc free