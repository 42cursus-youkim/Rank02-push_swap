/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:28 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 20:59:58 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "libft.h"

//	@func
/*
** < func_engine.c > */

bool	is_deque_sorted(t_engine *engine);
t_res	engine_solve(t_engine *engine);
t_res	inst(t_engine *engine, t_flag what, t_inst inst);
/*
** < init_engine.c > */

void	init_engine(t_engine *engine, int size, int *nums);
void	del_engine(t_engine *engine);
/*
** < qsort.c > */

void	partition(t_engine *e, t_flag what, int size);
/*
** < show_engine.c > */

void	engine_showcase_oper(t_engine *engine);
void	engine_visualize(t_engine *engine);
#endif