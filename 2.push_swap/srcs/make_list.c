/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:07:09 by jji               #+#    #+#             */
/*   Updated: 2021/05/25 16:07:11 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/make_list.h"

void    init_list(t_link **lst)
{
	(*lst)->next = NULL;
	(*lst)->prev = NULL;
}

void    add_link(t_link **lst)
{

    t_link *add;

    if(malloc_error(&add))
        return ;

    if (lst == NULL)
    {
        *lst = add;
    }
    else
    {
        while((*lst)->next == NULL)
            (*lst) = (*lst) ->next;
        *lst = add;
    }
    
}