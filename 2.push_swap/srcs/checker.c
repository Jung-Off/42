/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 20:36:20 by jji               #+#    #+#             */
/*   Updated: 2021/05/26 20:36:22 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void same_check(int save, t_link *lst)
{
	while(lst->next)
	{
		lst = lst->next;
		if(save == lst->num)
			error_check2();
	}
}

void duplicate_check(t_link *lst)
{
	int save;

	while(lst->next)
	{
		save = lst->num;
		same_check(save, lst);
		lst = lst->next;
	}
}