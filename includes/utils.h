/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:30:14 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 10:50:18 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//	@func
/*
** < opers.c > */

t_res		oper(t_engine *engine, t_flag from, t_inst inst);
/*
** < opers_util.c > */

t_deque		*get_deque(t_engine *engine, t_flag from);
void		set_deques_from_to(t_engine *e, t_deque *deqs[2], t_flag from);
const char	*get_op_name(t_op op);
t_res		opers(t_engine *engine, t_flag from, int size, t_inst insts[]);
/*
** < visualize.c > */

void		engine_showcase_oper(t_engine *engine);
void		engine_visualize(t_engine *engine);
#endif