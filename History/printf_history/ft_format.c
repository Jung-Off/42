/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:52:14 by jji               #+#    #+#             */
/*   Updated: 2021/02/10 16:12:50 by jji              ###   ########.fr       */
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

int		ft_mallocsize(t_flag *t, char *d)
{
	int re_i;
	
	t->str_len = ft_strlen(d);
	re_i = t->wid >= t->pre ? t->wid : t->pre;
	re_i = t->str_len >= re_i ? t->str_len : re_i;
	return (re_i);
}

void	malloc_init(char **print_d, int size, t_flag *t)
{
	if (t->zero == 1)
		ft_memset(*print_d, '0', size);
	else
		ft_memset(*print_d, ' ', size);
}

void ft_numlen(char *copy_d, t_flag *t)
{	
	int i;

	i = 0;
	while(ft_isdigit(copy_d[i]) || copy_d[i] == '-')
		++i;
	t->str_tunninglen = i;
}

char	*malloc_put(char **print_d, char *str_d, t_flag *t)
{
	char *copy_d;
	int i;
	int pre_copy;

	copy_d = ft_strdup(*print_d);
	i = 0;
	if(*str_d == '-' && str_d++)
	{
		copy_d[i++] = '-';
		t->str_len--;
	}
	if((pre_copy = (t->pre - t->str_len)) > 0)
		while (pre_copy > 0)
		{
			copy_d[i++] = '0';
			pre_copy--;
		}
	ft_strlcpy(copy_d + i, str_d, t->str_len + 1);	
	ft_numlen(copy_d, t);
	return (copy_d);
}

void ft_leftright(char **print_d, char *dup, t_flag *t)
{
	int d;

	if (t->minus != 1) 
	{
		//d = (t->wid > t->pre ? t->wid : t->pre);
		// d = (t->wid > t->str_tunninglen ? t->wid : t->pre);
		d = t->wid - t->str_tunninglen;
		if (d > 0)
		{
			ft_memcpy((*print_d + d), dup, t->str_tunninglen);
		}
		else
			ft_memcpy((*print_d), dup, ft_strlen(dup));
	}
	else
		ft_memcpy((*print_d), dup, ft_strlen(dup));	
}

int		format_d(t_flag *t, int d)
{
	char	*print_d;
	char	*str_d;
	int		malloc_size;
	char	*dup;

	if (t->dot && t->pre == 0 && d == 0)
		return (0);
	str_d = ft_itoa(d);
	malloc_size = ft_mallocsize(t, str_d);
	if (!(print_d = (char*)malloc(sizeof(char) * (malloc_size + 1))))
		return (0);
	print_d[malloc_size] = '\0';	
	malloc_init(&print_d, malloc_size, t);
	dup = malloc_put(&print_d, str_d, t);
	ft_leftright(&print_d, dup, t);	
	write(1, print_d, malloc_size);

	return (malloc_size);
}
