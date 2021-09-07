/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:18:00 by jji               #+#    #+#             */
/*   Updated: 2021/09/07 10:05:40 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#define OPTION_ON	1
#define OPTION_OFF	0

typedef int t_bool;

typedef struct	s_philo
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	t_bool	option;
	int		number_of_must_eat;
}				t_philo;

#endif
