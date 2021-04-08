/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:08:52 by jji               #+#    #+#             */
/*   Updated: 2021/02/16 19:37:49 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include "./libft/libft.h"

typedef struct	s_flag
{
	int			minus;
	int			zero;
	int			wid;
	int			dot;
	int			pre;
	int			usepre;
}				t_flag;

void			init_flag(t_flag *t);
void			ft_parse(char **p, t_flag *t, va_list ap);
int				ft_printf(char *p, ...);
void			ft_flag_lineup_zero(char **p, t_flag *t);
void			ft_flag_wp(char **p, t_flag *t, va_list ap);
int				ft_atoi_moveaddress(char **str);
int				ft_format(char *p, t_flag *t, va_list ap);
int				ft_max(int i, int j);
int				ft_putzero(t_flag *t, char *str_d);
int				ft_putblank(t_flag *t, char *str_d);
int				ft_putnum(t_flag *t, char *str_d);
int				ft_allblank(t_flag *t);
int				format_d(t_flag *t, int d);
int				ft_compare(int n, t_flag *t);
char			*ft_itoa_fix(int n, t_flag *t);
int				format_u(t_flag *t, char *base_char, unsigned int u);
char			*ft_uitoa_fix(unsigned int ui, t_flag *t, char *base);
char			*ft_ultoa_fix(unsigned long ul, t_flag *t, char *base);
int				format_p(t_flag *t, char *base_char, unsigned long ul);
int				format_c(t_flag *t, int c);
int				format_s(t_flag *t, char *str);
#endif
