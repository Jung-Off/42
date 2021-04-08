/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:53:06 by jji               #+#    #+#             */
/*   Updated: 2020/11/30 21:00:59 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int state;
	int len;

	state = 0;
	len = -1;
	while (*(str + (++len)))
	{
		if (*(str + len) >= '0' && *(str + len) <= '9')
			state = 1;
		else if (*(str + len) >= 'a' && *(str + len) <= 'z')
		{
			if (state == 0)
				(*(str + len) += 'A' - 'a') && (state = 1);
		}
		else if (*(str + len) >= 'A' && *(str + len) <= 'Z')
		{
			if (state == 1)
				*(str + len) += 'a' - 'A';
			else
				state = 1;
		}
		else
			state = 0;
	}
	return (str);
}
