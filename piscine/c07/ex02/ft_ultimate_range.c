/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 02:32:34 by jji               #+#    #+#             */
/*   Updated: 2020/12/07 13:59:29 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int bound;
	int index;
	int *buffer;

	if (min >= max)
		return (0);
	bound = max - min - 1;
	if ((*range = (int *)malloc(bound * sizeof(int))) == NULL)
		return (-1);
	buffer = *range;
	index = 0;
	while (index <= bound)
	{
		buffer[index] = min + index;
		index++;
	}
	return (bound + 1);
}
