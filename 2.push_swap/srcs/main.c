/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:22:53 by jji               #+#    #+#             */
/*   Updated: 2021/05/25 15:53:02 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int main(int argc, char **argv)
{
	t_link *lst;

	lst = 0;
	
	error_check(argc, argv);
	link_number(argc, argv, &lst);

///>>>>>>>>>>/////
	while(argc--)
	{
		printf("%d\n", lst->num);
		lst = lst->next;
	}
//<<<<<<<<<<<///
	// while(argc--)
	// {
	// 	printf("%d\n", lst->num);
	// 	lst = lst->prev;
	// }
	//linke_number 애서 저장한 lst를 이용할 예정
}
