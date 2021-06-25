/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:11:25 by jji               #+#    #+#             */
/*   Updated: 2020/12/27 16:59:52 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *p;

	p = *lst;
	if (lst)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			while (p->next)
				p = p->next;
			p->next = new;
		}
	}
}
