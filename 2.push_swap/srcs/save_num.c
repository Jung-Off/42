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


// void make_number(char *str, t_link **new)
// {
//     (*new)->num = push_atoi(str);
// }

void link_number(int argc, char **argv, t_link **lst)
{
    int     i;
    t_link *new_lst;

    i = 1;
    while(i < argc)
    {
        make_node(&new_lst);                //노드 생성
        new_lst->num = push_atoi(argv[i]);  //여기에서 숫자를 저장하는 함수
        add_node(lst, new_lst);             //붙이는 함수
        i++;
    }

                //중복확인

    last_to_first(lst);
}