/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:58 by jji               #+#    #+#             */
/*   Updated: 2021/09/11 19:25:36 by jji              ###   ########.fr       */
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
	//여기 부분 수정
	//exit 쓰면 안댐
	exit(1);
}

// void	*start(void *arg)
// {
// 	t_philo *status = (t_philo *)arg;
// 	printf("================\n");
// 	printf("idx : %d\n", status->idx);
// 	printf("forks : %p %p\n", status->l_fork, status->r_fork);
// 	printf("%p", status->info);
	
// 	printf("num : %d\n", status->info->num_to_philo);
// 	printf("die : %d\n", status->info->time_to_die);
// 	printf("eat : %d\n", status->info->time_to_eat);
// 	printf("sleep : %d\n", status->info->time_to_sleep);
// 	printf("count : %d\n", status->info->num_of_eat);
// 	printf("================");
// 	printf("\n\n");
// 	return (0);
// }

unsigned long	get_time(void)
{
	struct timeval	time;
	unsigned long	now;

	gettimeofday(&time, NULL);
	now = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (now);
}

unsigned long	get_time_stamp(t_philo *philo)
{
	unsigned long	now;

	now = get_time();
	//printf("get : %lu \n",now);
	return (now - philo->start_behave);
}

//함수명 고려해볼것
void	ft_usleep(unsigned long time_to_usleep)
{
	unsigned long	start;

	start = get_time();
	while (get_time() < start + time_to_usleep)
		usleep(100);
}

int print_action_message(t_philo *philo, int act)
{
	if (philo->info->death == DEATH)
		return (TRUE);
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

	return (FALSE);
}

int	ft_sleep(t_philo *philo)
{
	if (print_action_message(philo, 4))
		return (DEATH);
	ft_usleep(philo->info->time_to_sleep);
	return (LIVE);
}

int	ft_think(t_philo *philo)
{
	if (print_action_message(philo, 5))
		return (DEATH);
	return (LIVE);
}

void check_except(t_philo *philo)
{
	printf(GREEN"[%lums] philo [%d] has taken a fork in right hand\n"GREEN, get_time_stamp(philo), philo->idx);
	ft_usleep(philo->info->time_to_die);
	philo->info->death = 1;
	printf(RED"[%lums] philo [%d] died\n"RED, get_time_stamp(philo), philo->idx);
}



int philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (philo->info->death)
	{
		pthread_mutex_unlock(philo->l_fork);
		return (DEATH);
	}
	if (print_action_message(philo, LEFT))
		return (DEATH);
	pthread_mutex_lock(philo->r_fork);
	if (philo->info->death)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (DEATH);
	}
	if (print_action_message(philo, RIGHT))
		return (DEATH);
	//
	philo->last_meal = get_time_stamp(philo);
	philo->info->num_of_eat--;
	//
	if(print_action_message(philo, EAT))
		return (!FALSE);
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	
	return (!TRUE);
}



void *start (void *input_philo)
{
	t_philo *philo;

	philo = input_philo;
	if (philo->info->num_to_philo == 1)
		check_except(philo);
	if (philo->idx % 2 == 1)
		ft_usleep(philo->info->time_to_eat);
	while(philo->info->death == LIVE)
	{
		if (philo_eat(philo))
			return (NULL);
		if (ft_sleep(philo))
			return (NULL);
		if (ft_think(philo))
			return (NULL);
	}
	return (NULL);
}


void pthread_start(t_info info, t_philo *philo)
{
	int i;

	i = 0;
	while (i < info.num_to_philo)
	{
		philo[i].start_behave = get_time();
		pthread_create(&(philo[i].thread), NULL, &start, &philo[i]);
		//pthread_create(&(philo[i].monitor), NULL, &check, &philo[i]);
		++i;
		usleep(100);
	}
	i = 0;
	while (i < info.num_to_philo)
	{
		pthread_join(philo[i].thread, NULL);
		//pthread_join(philo[i].monitor, NULL);
		++i;
	}
}

int check_argc(int ac)
{
	if(ac != 5 && ac != 6)
	{
		error_print(1);
		return (EX);
	}
	return (NEX);
}

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_info	*info;

	if (check_argc(argc))
		return (0);
 	if (init_info(argc, argv, &info) || init_thread(info, &philo))
		return (0);
	if (init_mutex(info, philo))
		return (0);
	pthread_start(*info, philo);

	//free fork philo//
}
