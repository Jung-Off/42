/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:34:18 by jji               #+#    #+#             */
/*   Updated: 2021/05/27 15:34:18 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_ROTATE_H
# define CMD_ROTATE_H

# include "main.h"

void rotate_a(t_link **stack_a);
void rotate_b(t_link **stack_b);
void rotate_ab(t_link **stack_a, t_link **stack_b);

#endif