/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rrotate.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:44:48 by jji               #+#    #+#             */
/*   Updated: 2021/05/27 15:44:50 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_RROTATE_H
# define CMD_RROTATE_H

# include "main.h"

void rrotate_a(t_link **stack_a);
void rrotate_b(t_link **stack_b);
void rrotate_ab(t_link **stack_a, t_link **stack_b);

#endif