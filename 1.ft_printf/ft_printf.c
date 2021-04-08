/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:57:56 by jji               #+#    #+#             */
/*   Updated: 2021/02/16 19:41:32 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag(t_flag *t)
{
	t->minus = 0;
	t->zero = 0;
	t->wid = 0;
	t->dot = 0;
	t->pre = 0;
}

void	ft_parse(char **p, t_flag *t, va_list ap)
{
	ft_flag_lineup_zero(p, t);
	if (ft_isdigit(**p) || **p == '*')
		ft_flag_wp(p, t, ap);
	if (**p == '.' && (*p)++)
	{
		t->dot = 1;
		ft_flag_wp(p, t, ap);
	}
}

int		ft_format(char *p, t_flag *t, va_list ap)
{
	if (*p == 'd' || *p == 'i')
		return (format_d(t, va_arg(ap, int)));
	else if (*p == 'u')
		return (format_u(t, "0123456789", va_arg(ap, unsigned int)));
	else if (*p == 'x')
		return (format_u(t, "0123456789abcdef", va_arg(ap, unsigned int)));
	else if (*p == 'X')
		return (format_u(t, "0123456789ABCDEF", va_arg(ap, unsigned int)));
	else if (*p == 'p')
		return (format_p(t, "0123456789abcdef", va_arg(ap, unsigned long)));
	else if (*p == 's')
		return (format_s(t, va_arg(ap, char*)));
	else if (*p == 'c')
		return (format_c(t, (char)va_arg(ap, int)));
	else if (*p == '%')
		return (format_c(t, '%'));
	return (0);
}

int		ft_printf(char *p, ...)
{
	va_list	ap;
	int		re_i;
	t_flag	t;

	re_i = 0;
	init_flag(&t);
	va_start(ap, p);
	while (*p)
	{
		if (*p != '%')
		{
			write(1, p++, 1);
			re_i++;
			continue ;
		}
		p++;
		ft_parse(&p, &t, ap);
		re_i += ft_format(p++, &t, ap);
		init_flag(&t);
	}
	va_end(ap);
	return (re_i);
}
