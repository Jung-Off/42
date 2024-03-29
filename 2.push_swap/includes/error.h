/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:34:11 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:26:32 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "main.h"

void	error_check(int argc);
void	error_check2(void);
int		malloc_error(t_link **add);
int		malloc_error2(int **tmp, int num);
void	lst_free(t_link *lst);

#endif
