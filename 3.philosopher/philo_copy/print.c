/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:54:42 by jji               #+#    #+#             */
/*   Updated: 2021/09/29 17:28:27 by jji              ###   ########.fr       */
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

void	print_die_message(t_philo *philo)
{
	if (philo->info->death == DEATH)
		return ;
	philo->info->death = DEATH;
	//usleep(100);
	printf(RED"[%lums] philo[%d] died"RESET,
		get_time_stamp(philo), philo->idx);
}

void	print_fin_message(t_philo *philo)
{
	if (philo->info->death == DEATH)
		return ;
	philo->done_eating = 1;
	//usleep(100);
	printf(GREEN"[%lums] philo[%d] is done eating!\n\033[0m"RESET,
		get_time_stamp(philo), philo->idx);
}

int	print_action_message(t_philo *philo, int act)
{
	if (philo->info->death == DEATH)
		return (EX);
	pthread_mutex_lock(&(philo->info->message));
	if (act == LEFT)
		printf("[%lums] philo[%d] has taken a fork in left hand\n",
			get_time_stamp(philo), philo->idx);
	else if (act == RIGHT)
		printf("[%lums] philo[%d] has taken a fork in right hand\n",
			get_time_stamp(philo), philo->idx);
	else if (act == EAT)
		printf(CYAN"[%lums] philo[%d] is eating\n"RESET,
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
