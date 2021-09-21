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
# include <sys/time.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define LIVE 0
# define DEATH 1

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

typedef struct s_info
{
	int		num_to_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_eat;

	int		death;
	pthread_mutex_t	*fork;
}				t_info;

typedef struct s_philo
{
	int				idx;
	pthread_t		thread;
	pthread_t		monitor;
	pthread_mutex_t *fork;
	
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	//죽었다 라는 것 표시 할것
	unsigned long	start;

	t_info			*info;
}				t_philo;


int	philo_isdigit(int c);
int	philo_atoi(char *str);
int philo_strlen(char *str);

t_info *make_info(void);


void init_mutex(t_info info, t_philo *philo);


void init_thread(t_info *info, t_philo **philo);
void	init_info(int ac, char *argv[], t_info **info);

void valid_input(char *av[]);
t_philo	*make_philo(t_info info);
pthread_mutex_t	*make_forks(t_info info);

void	put_the_fork(t_philo *philo, t_info info, pthread_mutex_t *forks);


void	error_print(int err_num);
#endif
