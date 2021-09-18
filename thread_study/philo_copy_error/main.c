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
	printf("%p", status->info);
	
	printf("num : %d\n", status->info->num_to_philo);
	printf("die : %d\n", status->info->time_to_die);
	printf("eat : %d\n", status->info->time_to_eat);
	printf("sleep : %d\n", status->info->time_to_sleep);
	printf("count : %d\n", status->info->num_of_eat);
	printf("================");
	printf("\n\n");
	return (0);
}

// void print_f(t_philo *philo)
// {
// 	t_philo *status = philo;
// 	printf("================\n");
// 	printf("idx : %d\n", status->idx);
// 	printf("forks : %p %p\n", status->l_fork, status->r_fork);
// 	printf("num : %d\n", status->info->num_to_philo);
// 	printf("die : %d\n", status->info->time_to_die);
// 	printf("eat : %d\n", status->info->time_to_eat);
// 	printf("sleep : %d\n", status->info->time_to_sleep);
// 	printf("count : %d\n", status->info->num_of_eat);
// 	printf("================");
// 	printf("\n\n");
// }

void pthread_start(t_info info, t_philo *philo)
{
	int i;

	i = 0;
	while (i < info.num_to_philo)
	{
		
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

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_info	info;

	philo = NULL;
	if (argc != 5 && argc != 6)
		error_print(1);
 	init_info(argc, argv, &info);
	
	
// //	내가 이걸 고민하고 있는 이유 philo도 넘어 갔다가 오면 공간이 있어야 되니까 &philo이어야 되는데
// //philo =으로 받는 것은 왜 안되는 것이며

// //init_mutex는 주소를 넘겨오는데 philo로 만으로 충분한 것인가?

// 	//1)
	init_thread(&info, &philo);
// 	//2) 
// 	//philo = init_thread(*info);
// ////////////////
// 	//1)
	init_mutex(&info, philo);
// 	//2)
// 	//init_mutex(info, &philo);
// 	//여기 2번은 그래도 어느정도 납득이 됨


	pthread_start(info, philo);

	//free fork philo//
}

//내가 뇌절을 하고 있는건가

//구조체포인터 안의 주소에 주소를 넣으면 저장이 된다.
//그러면 init_thread의 1번은 되어야 되는게 아닌가
/*
void	init_mutex_data(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_of_philo)
	{
		philo[i].message = philo->message;
		philo[i].eating = philo->eating;
		philo[i].r_fork = &(philo->forks[i]);
		if (i != 0)
			philo[i].l_fork = &(philo->forks[i - 1]);
		i++;
	}
	philo[0].l_fork = &(philo->forks[i - 1]);
}
*/
