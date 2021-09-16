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

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_info
{
	int		num_to_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_eat;
}				t_info;

typedef struct s_philo
{
	int				idx;
	pthread_t		thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	//죽었다 라는 것 표시 할것

	t_info			*info;
}				t_philo;


int	philo_isdigit(int c);
int	philo_atoi(char *str);
int philo_strlen(char *str);

void init_mutex(t_info info, t_philo *philo);
void init_thread(t_info info, t_philo *philo);
void	init_info(int ac, char *argv[], t_info *info);

void valid_input(char *av[]);
t_philo	*make_philo(t_info info);
pthread_mutex_t	*make_forks(t_info info);
void	put_the_fork(t_philo *philo, t_info info, pthread_mutex_t *forks);

void	error_print(int err_num);
#endif
