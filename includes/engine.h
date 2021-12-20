/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:28 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 11:01:12 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "libft.h"

//	@func
/*
** < checks.c > */

void		check_duplicate(const int argc, const char *argv[]);
t_deque		*get_input(const int argc, const char *argv[]);
bool		is_sorted(t_engine *engine);
/*
** < engine.c > */

void		init_engine(t_engine *engine, t_deque *input);
void		del_engine(t_engine *engine);
void		engine_print_opers(t_engine *engine);
const char	*get_op_name(t_op op);
/*
** < push_swap.c > */

void		solve(t_engine *engine);
#endif