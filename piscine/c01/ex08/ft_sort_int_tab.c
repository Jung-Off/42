/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 23:23:42 by jji               #+#    #+#             */
/*   Updated: 2020/11/25 16:51:21 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int num_r;
	int num;
	int temp;

	num_r = 0;
	while (num_r < size - 1)
	{
		num = 0;
		while (num < (size - 1) - num_r)
		{
			if (tab[num] > tab[num + 1])
			{
				temp = tab[num];
				tab[num] = tab[num + 1];
				tab[num + 1] = temp;
			}
			++num;
		}
		++num_r;
	}
}
