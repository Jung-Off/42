/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:54:42 by jji               #+#    #+#             */
/*   Updated: 2021/09/28 16:54:43 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error_print(int err_num)
{
	if (err_num == 1)
		printf("error argc count\n");
	else if (err_num == 2)
		printf("error you input char\n");
	else if (err_num == 3)
		printf("error input out of range\n");
	else if (err_num == 4)
		printf("error malloc assignment\n");
}

int print_action_message(t_philo *philo, int act)
{
	if (philo->info->death == DEATH)
		return (EX);
	pthread_mutex_lock(&(philo->info->message));
	if (act == LEFT)
		printf(CYAN"[%lums] philo[%d] has taken a fork in left hand\n"RESET,
			get_time_stamp(philo), philo->idx);
	else if (act == RIGHT)
		printf(CYAN"[%lums] philo[%d] has taken a fork in right hand\n"RESET,
			get_time_stamp(philo), philo->idx);
	else if (act == EAT)
		printf(GREEN"[%lums] philo[%d] is eating\n"RESET,
			get_time_stamp(philo), philo->idx);
	else if (act == SLEEP)
		printf(MAGENTA"[%lums] philo[%d] is sleeping\n"RESET,
			get_time_stamp(philo), philo->idx);
	else if (act == THINK)
		printf(YELLOW"[%lums] philo[%d] thinks\n"RESET,
			get_time_stamp(philo), philo->idx);
	pthread_mutex_unlock(&(philo->info->message));

	return (NEX);
}