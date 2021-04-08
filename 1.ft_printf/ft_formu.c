/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:05:21 by jji               #+#    #+#             */
/*   Updated: 2021/02/16 17:05:30 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	u_len(long long un, int base)
{
	int count;

	count = 0;
	if (un == 0)
		return (1);
	while (un > 0)
	{
		un /= base;
		count++;
	}
	return (count);
}

char		*ft_uitoa_fix(unsigned int ui, t_flag *t, char *base)
{
	long long	llui;
	char		*tmp;
	int			len;
	int			base_l;

	llui = ui;
	base_l = (int)ft_strlen(base);
	len = u_len(llui, base_l);
	len = ((len > t->pre) ? len : t->pre);
	if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (llui == 0)
		tmp[0] = '0';
	tmp[len--] = '\0';
	while (len >= 0)
	{
		tmp[len] = base[llui % base_l];
		llui /= base_l;
		len--;
	}
	return (tmp);
}

int			format_u(t_flag *t, char *base_char, unsigned int ui)
{
	char	*str_ui;
	int		i;

	if (t->dot == 1 && t->pre == 0 && ui == 0)
		return (ft_allblank(t));
	str_ui = ft_uitoa_fix(ui, t, base_char);
	i = (t->minus == 1 ? ft_putnum(t, str_ui) : ft_putblank(t, str_ui));
	i += (t->minus == 0 ? ft_putnum(t, str_ui) : ft_putblank(t, str_ui));
	free(str_ui);
	return (i);
}

char		*ft_ultoa_fix(unsigned long ul, t_flag *t, char *base)
{
	char	*tmp;
	int		len;
	int		base_l;

	base_l = (int)ft_strlen(base);
	len = u_len(ul, base_l);
	len = ((len > t->pre) ? len : t->pre);
	if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (ul == 0)
		tmp[0] = '0';
	tmp[len--] = '\0';
	while (len >= 0)
	{
		tmp[len] = base[ul % base_l];
		ul /= base_l;
		len--;
	}
	return (tmp);
}

int			format_p(t_flag *t, char *base_char, unsigned long ul)
{
	char	*str_ul;
	char	*str_re;
	int		i;

	str_ul = 0;
	if (t->dot == 1 && t->pre == 0 && ul == 0)
		str_ul = ft_strdup("");
	else
		str_ul = ft_ultoa_fix(ul, t, base_char);
	str_re = ft_strjoin("0x", str_ul);
	free(str_ul);
	i = (t->minus == 1 ? ft_putnum(t, str_re) : ft_putblank(t, str_re));
	i += (t->minus == 0 ? ft_putnum(t, str_re) : ft_putblank(t, str_re));
	free(str_re);
	return (i);
}
