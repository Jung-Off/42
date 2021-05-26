/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_num.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:54:42 by jji               #+#    #+#             */
/*   Updated: 2021/05/25 15:54:44 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_NUM_H
# define SAVE_NUM_H

#include "main.h"

// void make_number(char *str, t_link **new);
int null_guard(t_link *new_lst);
int link_number(int argc, char **argv, t_link **lst);


#endif