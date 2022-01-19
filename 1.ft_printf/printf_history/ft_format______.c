/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:52:14 by jji               #+#    #+#             */
/*   Updated: 2021/02/10 20:47:07 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_format(char *p, t_flag *t, va_list ap)
{
	if ((*p == 'd' || *p == 'i'))
		return (format_d(t, va_arg(ap, int)));
	//else if... c, s, p, x, X, u, %
	
	return (0);
}

int		format_d(t_flag *t, int d)
{

	char *str_d;

	int cnt;
	
	cnt = 0;
	if (t->dot && !t->pre && !d)
	{
		if (t->wid)
			cnt += t->wid;
		while (t->wid--)
			write(1, " ", 1);
		return (cnt);
	}
	//study..
	str_d = ft_itoa_fix(d, t);
	//free//
	int i;

	i = 0;
	cnt = 0;
	//pre...?
	int gap = t->wid - (int)ft_strlen(str_d);
	//int gap2 =t->wid - t->pre;
	if (gap >= 0)
		cnt += gap;
int	gap2 = gap;
	
	if (t->minus == 0) //우측정렬
	{
/*	
		if (t->zero == 0 && !(t->pre))
		{
			while(gap-- > 0)
				write(1, " ", 1);
			write(1, str_d, (int)ft_strlen(str_d));
		}
		
		if (t->zero == 1 && (t->wid >= t-> pre))
		{
			if(str_d[0] == '-')
			{
				write(1, "-", 1);
				++i;
			}
			while(gap-- > 0)
				write(1, "0", 1);
			write(1, str_d + i, (int)ft_strlen(str_d + i));
		}
		*/	
		if(t->zero == 1)
		{
			if(str_d[0] == '-')
			{
				write(1, "-", 1);
				++i;
			}
			if (gap > 0)
				while (gap--)
				{
					write(1, " ", 1);
					if(
			//	while(gap2-- > 0)
			//		write(1, "0", 1);
			while(gap-- > 0)
				write(1, "0", 1);
			write(1, str_d + i, (int)ft_strlen(str_d + i));
		}

		else
		{	
			if (t->wid > (int)ft_strlen(str_d))
				while((gap-- > 0))
					write(1, " ", 1);
			write(1, str_d, (int)ft_strlen(str_d));
		}
	}
	else
	{	
		write(1, str_d, (int)ft_strlen(str_d));
		if (t->wid > (int)ft_strlen(str_d))
			while((gap-- > 0))
				write(1, " ", 1);	
	}
	//printf("%s", str_d);
	return (cnt + (int)ft_strlen(str_d));
}
