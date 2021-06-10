/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:33:16 by jji               #+#    #+#             */
/*   Updated: 2021/05/25 15:52:40 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error.h"

void error_check(int argc, char **argv)
{
	if (argc == 1)
		exit(1);
}

void  error_check2(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	malloc_error(t_link **add)
{
	*add = malloc(sizeof(t_link));

	if (*add == NULL)
		return (1);
	else
		return (0);
}

int	malloc_error2(int **tmp, int num)
{
	*tmp = malloc(sizeof(int) * num);

	if (*tmp == NULL)
		return (1);
	else
		return (0);
}

void lst_free(t_link *lst)
{
	t_link *temp;

	while (lst)
	{
		temp = (lst)->next;
		free(lst);
		lst = temp;
	}
	return ;
}
