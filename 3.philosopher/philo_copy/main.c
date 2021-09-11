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
	
type *status_init(int ac, char *av[])
{
	if(ac == 5)
		option = OPTION_OFF;
	else
		option = OPTION_ON;

}

	
int main(int argc, char *argv[])
{

	if(argc != 5 && argc != 6)
		error_print(1);
}
