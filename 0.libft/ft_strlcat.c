/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:09:34 by jji               #+#    #+#             */
/*   Updated: 2021/01/05 20:28:20 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, char *src ,size_t dstsize)
{
	size_t i;
	size_t dst_len;
	size_t src_len;

	i = 0;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if(dstsize < 1)
		return (src_len);
	if(dstsize < dst_len)
		return (src_len + dstsize);

	while(src[i] &&  i + dst_len < dstsize - 1)
	{
		dst[i + dst_len] = src[i];
		++i;
	}
	dst[i + dst_len] = '\0';

	return (dst_len + src_len);		
}
