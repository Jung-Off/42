/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:53:46 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:46:51 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/save_num.h"

int	null_guard(t_link *new_lst)
{
	if (!new_lst)
		return (1);
	else
		return (0);
}

int	link_number(int argc, char **argv, t_link **lst)
{
	int		i;
	t_link	*new_lst;

	i = 1;
	while (i < argc)
	{
		make_node(&new_lst);
		if (null_guard(new_lst))
			return (1);
		new_lst->num = push_atoi(argv[i]);
		add_node(lst, new_lst);
		i++;
	}
	duplicate_check(*lst);
	if (ascending_check(*lst))
	{
		lst_free(*lst);
		exit(0);
	}
	last_to_first(lst);
	return (0);
}
