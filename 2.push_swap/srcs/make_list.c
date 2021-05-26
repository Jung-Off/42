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

void make_node(t_link **lst)
{
    if (malloc_error(lst))
        return ;
    (*lst)->next = NULL;
    (*lst)->prev = NULL;
}

void add_node(t_link **lst, t_link *new_lst)
{
    t_link *move_lst;

    move_lst = *lst;
    if (*lst == NULL)
        *lst = new_lst;
    else
    {
        while (move_lst->next)
            move_lst = move_lst->next;
        move_lst->next = new_lst;
        new_lst->prev = move_lst; 
    }
}

void last_to_first(t_link **lst)
{
    t_link *last_node;

    last_node = *lst;
    while (last_node->next)
        last_node = last_node->next;
    last_node->next = *lst;
    (*lst)->prev = last_node;
}
