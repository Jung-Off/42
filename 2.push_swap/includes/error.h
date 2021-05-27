/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:34:11 by jji               #+#    #+#             */
/*   Updated: 2021/05/25 15:37:05 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "main.h"

void    error_check(int argc, char **argv);
void    error_check2(void);
int     malloc_error(t_link **add);
void    duplicate_check(t_link *lst);
void    lst_free(t_link *lst);

#endif
