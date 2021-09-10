/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:17:58 by jji               #+#    #+#             */
/*   Updated: 2021/09/09 19:26:48 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void error_print(int err_num)
{
	if(err_num == 1)
		printf("error argc count\n");
	else if(err_num == 2)
		printf("error input char\n");
	else if(err_num == 3)
		printf("error input outofrange\n");
	exit(1);
}

int	philo_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		philo_isspace(char ch)
{
	if (ch == ' ')
		return (1);
	if (ch == '\f')
		return (1);
	if (ch == '\n')
		return (1);
	if (ch == '\r')
		return (1);
	if (ch == '\t')
		return (1);
	if (ch == '\v')
		return (1);
	return (0);
}

int philo_atoi(char *str)
{
	int			isnum;
	int			minus;
	long long	num;

	isnum = 0;
	minus = 1;
	num = 0;
	while (philo_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str)
	{
		if(!philo_isdigit(*str))
			error_print(2);
		num = num * 10 + (*(str++) - '0');
		isnum = 1;
	}
	num *= minus;
	if (isnum == 0)
		error_print(2);
	else if(num > 2147483637 || num < -2147483648)
		error_print(3);
	return (num);
}

t_data *data_init(int ac, char *av[])
{
	t_data *data;

	//숫자로 만 입력받기
	if(!(data = (t_data *)malloc(sizeof(t_data))))
		return (0);
	data->num_of_philo = philo_atoi(av[1]);
	data->time_to_die = philo_atoi(av[2]);
	data->time_to_eat = philo_atoi(av[3]);
	data->time_to_sleep = philo_atoi(av[4]);
	data->eat_count = philo_atoi(av[ac - 1]);
	return (data);
}
	
t_status *status_init(int ac, char *av[])
{
	t_data *data;
	pthread_mutex_t *forks;
	t_status *status;
	
	data = data_init(ac, av);
	if(!(status = (t_status *)malloc(sizeof(t_status) * data->num_of_philo)))
		return 0;
	if(!(forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_of_philo)))
		return 0;	

	if(ac == 5)
		status->option = OPTION_OFF;
	else
		status->option = OPTION_ON;

	status->forks_free = forks;
	int i = 0;
	while(i < data->num_of_philo)
	{
		status[i].idx = i + 1;
		status[i].data = data;
		pthread_mutex_init(&(forks[i]), NULL);
		++i;
	}
	i = 0;
	while(i < data->num_of_philo)
	{	
		if(i == 0)
		{
			status[i].l_fork = &(forks[data->num_of_philo - 1]);
			status[i].r_fork = &(forks[0]);
		}
		else
		{	
			status[i].l_fork = &(forks[i - 1]);
			status[i].r_fork = &(forks[i]);
		}
		i++;	
	}
	return (status);
}

void *print(void *arg)
{
	t_status *status = (t_status *)arg;

	printf("idx :%d\n", status->idx);
	printf("forks : %p %p\n", status->l_fork, status->r_fork);
	printf("option : %d\n", status->option);
	
	printf("num : %d\n", status->data->num_of_philo);
	printf("die : %d\n", status->data->time_to_die);
	printf("eat : %d\n", status->data->time_to_sleep);
	printf("sleep : %d\n", status->data->time_to_sleep);
	printf("count : %d\n", status->data->eat_count);

	printf("\n\n");
	return 0;
}
	
int main(int argc, char *argv[])
{
	t_status *status;

	if(argc != 5 && argc != 6)
		error_print(1);
	status = status_init(argc, argv);


	//포크
	int i = 0;
	while(i < status->data->num_of_philo)
	{
		pthread_create(&(status[i].philo), NULL, &print, &status[i]);
		pthread_join(status[i].philo, NULL);
		i++;
	}
}
