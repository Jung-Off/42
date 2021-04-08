/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:43:10 by jji               #+#    #+#             */
/*   Updated: 2020/12/29 20:40:30 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*p;
	t_list	*head;

	head = 0;
	while (lst)
	{
		if (!(p = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, p);
		lst = lst->next;
	}
	return (head);
}
