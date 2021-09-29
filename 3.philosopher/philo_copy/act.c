/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:57:36 by jji               #+#    #+#             */
/*   Updated: 2021/09/28 16:57:43 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void philo_update (t_philo *philo)
{
    pthread_mutex_lock(&(philo->eating));
    philo->last_meal = get_time_stamp(philo);
    philo->num_of_eat--;
    //printf("\n\n\nminus=====%d=====\n\n\n", philo->num_of_eat);
    pthread_mutex_unlock(&(philo->eating));
}

int philo_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    if (philo->info->death)
    {
        pthread_mutex_unlock(philo->l_fork);
        return (EX);
    }
    if (print_action_message(philo, LEFT))
        return (EX);
    pthread_mutex_lock(philo->r_fork);
    if (philo->info->death)
    {
        pthread_mutex_unlock(philo->l_fork);
        pthread_mutex_unlock(philo->r_fork);
        return (EX);
    }
    if (print_action_message(philo, RIGHT))
        return (EX);
    philo_update(philo);

//printf("\n\n\neat=====%d====eat\n\n\n", philo->num_of_eat);

    if (print_action_message(philo, EAT))
        return (EX);
    ft_stop(philo->info->time_to_eat);
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
    //usleep(100);
    return (NEX);
}

int	philo_think(t_philo *philo)
{
	if (print_action_message(philo, 5))
		return (EX);
	return (NEX);
}

int	philo_sleep(t_philo *philo)
{
	if (print_action_message(philo, 4))
		return (EX);
	ft_stop(philo->info->time_to_sleep);
	return (NEX);
}