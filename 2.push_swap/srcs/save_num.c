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

int null_guard(t_link *new_lst)
{
    if(!new_lst)
        return (1);
    else
        return (0);
}

int link_number(int argc, char **argv, t_link **lst)
{
    int     i;
    t_link *new_lst;

    i = 1;
    while(i < argc)
    {
        make_node(&new_lst);                //노드 생성
        if (null_guard(new_lst))
            return (1);
        new_lst->num = push_atoi(argv[i]);  //여기에서 숫자를 저장하는 함수
        add_node(lst, new_lst);             //붙이는 함수
        i++;
    }
    duplicate_check(*lst); //중복확인
    if(ascending_check(*lst)) //오름차순 확인
    {
        lst_free(*lst);
        exit (0);
    }
    last_to_first(lst);
    return (0);
}