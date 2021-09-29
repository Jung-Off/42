/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:53:50 by jji               #+#    #+#             */
/*   Updated: 2021/09/28 16:53:51 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_stop(unsigned long time_to_usleep)
{
	unsigned long	start;

	start = get_time();
	while (get_time() < start + time_to_usleep);
		//usleep(100); //이것의 차이는 어떻게 될까
}

unsigned long	get_time(void)
{
	struct timeval	time;
	unsigned long	now;

	gettimeofday(&time, NULL);
	now = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (now);
}

unsigned long	get_time_stamp(t_philo *philo)
{
	unsigned long	now;

	now = get_time();
	return (now - philo->time_to_0);
}
