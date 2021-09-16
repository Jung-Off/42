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
	exit(1);
}

void	*start(void *arg)
{
	t_philo *status = (t_philo *)arg;
	printf("================\n");
	printf("idx : %d\n", status->idx);
	printf("forks : %p %p\n", status->l_fork, status->r_fork);
	printf("num : %d\n", status->info->num_to_philo);
	printf("die : %d\n", status->info->time_to_die);
	printf("eat : %d\n", status->info->time_to_eat);
	printf("sleep : %d\n", status->info->time_to_sleep);
	printf("count : %d\n", status->info->num_of_eat);
	printf("================");
	printf("\n\n");
	return (0);
}


void pthread_start(t_info info, t_philo *philo)
{
	int i;

	i = 0;
	while (i < info.num_to_philo)
	{
		pthread_create(&(philo[i].thread), NULL, &start, &philo[i]);
		//pthread_create(&(philo[i].monitor), NULL, &check, &philo[i]);
		++i;
		usleep(10);
	}
	i = 0;
	while (i < info.num_to_philo)
	{
		pthread_join(philo[i].thread, NULL);
		//pthread_join(philo[i].monitor, NULL);
		++i;
	}
}

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_info	info;

	philo = NULL;
	if (argc != 5 && argc != 6)
		error_print(1);
	init_info(argc, argv, &info);
	//여기서부터 다시시작
	philo = init_thread(info);
	init_mutex(info, philo);

	pthread_start(info, philo);

	//free fork philo//
}
