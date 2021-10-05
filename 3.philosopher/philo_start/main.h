/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:18:00 by jji               #+#    #+#             */
/*   Updated: 2021/09/09 18:57:56 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define OPTION_ON	1
#define OPTION_OFF	0

typedef int t_bool;

typedef struct	s_data
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_count;
}				t_data;

typedef struct 	s_status
{
	int					idx;
	pthread_t			philo;

	pthread_mutex_t		*forks_free;	
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	t_bool				option;
	t_data				*data;
}				t_status;

#endif
