/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:27:17 by jji               #+#    #+#             */
/*   Updated: 2021/05/18 12:37:35 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	comma(char **str)
{
	while (ft_isspace(**str))
		*str += 1;
	if (**str != ',')
		error_check(4, "p3");
	(*str)++;
}

int		ft_isspace(char ch)
{
	if (ch == ' ')
		return (1);
	if (ch == '\f')
		return (1);
	if (ch == '\n')
		return (1);
	if (ch == '\r')
		return (1);
	if (ch == '\t')
		return (1);
	if (ch == '\v')
		return (1);
	return (0);
}
