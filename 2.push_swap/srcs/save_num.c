/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:53:46 by jji               #+#    #+#             */
/*   Updated: 2021/05/25 15:53:47 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/save_num.h"

void link_number(int argc, char **argv, t_link **lst)
{
    t_link  *node;
    int     i;

    i = 2;
    node = (*lst);
    while(i < argc)
    {
        add_link(&node);
        //여기서 new_node라는 곳에 양쪽으로 어떻게 연결을 해줄까 라는 것!

        save_number(argv, lst);
        //index i , argv, lst 가져가야 할듯
        //여기서 숫자를 저장해주는 역할을 하는 함수
        //node = node->next;
        i++;
    }

    //from_first_to_last
    //여기에서 마지막 노드? 랑 처음 노드랑 연결
}	