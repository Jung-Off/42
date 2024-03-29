/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 20:36:39 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:25:51 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "main.h"

void	same_check(int save, t_link *lst);
void	duplicate_check(t_link *lst);
int		ascending_check(t_link *lst);
int		decending_check(t_link *lst, int num);
int		ascending_check_len(t_link *lst, int len);

#endif
