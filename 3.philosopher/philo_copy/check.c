/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:56:36 by jji               #+#    #+#             */
/*   Updated: 2021/09/28 16:56:37 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int check_argc(int ac)
{
	if (ac != 5 && ac != 6)
	{
		error_print(1);
		return (EX);
	}
	return (NEX);
}

void check_except(t_philo *philo)
{
	printf(GREEN"[%lums] philo [%d] has taken a fork in right hand\n"GREEN, get_time_stamp(philo), philo->idx);
	ft_stop(philo->info->time_to_die);
	philo->info->death = DEATH;
	printf(RED"[%lums] philo [%d] died\n"RED, get_time_stamp(philo), philo->idx);
}

int check_death(t_philo *philo)
{
	if (get_time_stamp(philo) >= philo->last_meal + philo->info->time_to_die)
		return (EX);
	return (NEX);	
}

int check_fin(t_philo *philo)
{
	if (philo->num_of_eat == FIN)
		return (EX);
	return (NEX);
}