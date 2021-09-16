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

void	*print(void *arg)
{
	t_philo *status = (t_philo *)arg;

	printf("idx :%d\n", status->idx);
	printf("forks : %p %p\n", status->l_fork, status->r_fork);
	printf("num : %d\n", status->info->num_to_philo);
	printf("die : %d\n", status->info->time_to_die);
	printf("eat : %d\n", status->info->time_to_eat);
	printf("sleep : %d\n", status->info->time_to_sleep);
	printf("count : %d\n", status->info->num_of_eat);
	printf("\n\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_philo	*philo;
	t_info	info;

	i = 0;
	philo = NULL;
	if (argc != 5 && argc != 6)
		error_print(1);
	init_info(argc, argv, &info);
	init_thread(info, philo);
	init_mutex(info, philo);

	//pthread_start();

	while (i < info.num_to_philo)
	{
		pthread_create(&(philo[i].thread), NULL, &print, &philo[i]);
		pthread_join(philo[i].thread, NULL);
		++i;
	}
	//free fork philo//
}
