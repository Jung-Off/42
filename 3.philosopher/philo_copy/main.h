/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:18:00 by jji               #+#    #+#             */
/*   Updated: 2021/09/29 17:25:16 by jji              ###   ########.fr       */
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

# define LEFT 1
# define RIGHT 2
# define EAT 3
# define SLEEP 4
# define THINK 5

# define EX 1
# define NEX 0

# define FIN 0

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

typedef struct s_info
{
	int				num_to_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eat;
	int				death;
	pthread_mutex_t	message;
	pthread_mutex_t	*fork;
}				t_info;

typedef struct s_philo
{
	int				idx;	
	pthread_t		thread;
	pthread_t		monitor;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	eating;
	unsigned long	time_to_0;
	unsigned long	last_meal;
	int				num_of_eat;
	int				done_eating;
	t_info			*info;
}				t_philo;

void			error_print(int err_num);
int				philo_isdigit(int c);
int				philo_atoi(char *str);
int				philo_strlen(char *str);
int				valid_input(char *av[]);

void			put_the_fork(t_philo *philo, t_info *info,
					pthread_mutex_t *forks);
int				init_mutex(t_info *info, t_philo *philo);
int				init_thread(t_info *info, t_philo **philo);
int				init_info(int ac, char *argv[], t_info **info);

void			ft_stop(unsigned long time_to_usleep);
unsigned long	get_time_stamp(t_philo *philo);
unsigned long	get_time(void);

void			error_print(int err_num);
void			print_die_message(t_philo *philo);
void			print_fin_message(t_philo *philo);
int				print_action_message(t_philo *philo, int act);

int				check_argc(int ac);
void			check_except(t_philo *philo);
int				check_fin(t_philo *philo);
int				check_death(t_philo *philo);

void			philo_update(t_philo *philo);
int				philo_eat(t_philo *philo);
int				philo_think(t_philo *philo);
int				philo_sleep(t_philo *philo);

#endif
