/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:45:08 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:47:26 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	lst_len(t_link *stack_a)
{
	t_link	*temp;
	int		len;

	len = 1;
	temp = stack_a->next;
	while (temp != stack_a)
	{
		temp = temp->next;
		++len;
	}
	return (len);
}

int	ft_isnum(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

int	push_atoi(char *str)
{
	long long	sum;
	int			minus;

	sum = 0;
	minus = 1;
	if (*str == '-' && str++)
		minus = -1;
	while (*str)
	{
		if (!ft_isnum(*str))
			error_check2();
		sum = sum * 10 + (*(str++) - '0');
	}
	sum *= minus;
	if (sum > 2147483647 || sum < -2147483648)
		error_check2();
	return (sum);
}
