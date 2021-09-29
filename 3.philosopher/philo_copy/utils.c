/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:38:27 by jji               #+#    #+#             */
/*   Updated: 2021/09/29 17:28:02 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	philo_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (NEX);
	else
		return (EX);
}

int	philo_atoi(char *str)
{
	int			isnum;
	int			minus;
	long long	num;

	isnum = 0;
	minus = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			error_print(3);
		str++;
	}
	while (*str)
		num = num * 10 + (*(str++) - '0');
	if (num > MAX_INT || num < MIN_INT)
		error_print(3);
	return (num);
}

int	philo_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

int	valid_input(char *av[])
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		len = philo_strlen(av[i]);
		while (j < len)
		{
			if (len != 1)
			{	
				if ((j == 0) && (av[i][j] == '-' || av[i][j] == '+'))
					j++;
			}
			if (philo_isdigit(av[i][j]))
				return (EX);
			++j;
		}
		++i;
	}
	return (NEX);
}
