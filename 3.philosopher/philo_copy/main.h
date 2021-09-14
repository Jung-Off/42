/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:18:00 by jji               #+#    #+#             */
/*   Updated: 2021/09/11 17:15:07 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define OPTION_ON	1
# define OPTION_OFF	0

typedef int	t_bool;

typedef struct s_info
{
	int		num_to_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	t_bool	option;
	int		num_of_eat;
}				t_info;

typedef struct s_philo
{
	int				idx;
	pthread_t		thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

	t_info			*info;
}				t_philo;

#endif
