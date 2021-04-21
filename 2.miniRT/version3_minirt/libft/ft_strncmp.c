/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:12:37 by jji               #+#    #+#             */
/*   Updated: 2020/12/24 21:31:56 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;
	size_t			i;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (u_s1[i] == u_s2[i] && u_s1[i] != '\0' &&
			u_s2[i] != '\0' && i < n - 1)
		i++;
	return (u_s1[i] - u_s2[i]);
}
