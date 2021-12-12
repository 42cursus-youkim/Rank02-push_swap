/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:30:14 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 20:59:58 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERS_H
# define OPERS_H

//	@func
/*
** < handler.c > */

t_res		oper(t_engine *engine, t_op op);
/*
** < handler_utils.c > */

t_deque		*get_deque(t_engine *engine, t_flag what);
void		set_deques_from_to(t_engine *engine, t_deque *deqs[2],
				t_flag from);
const char	*get_op_name(t_op op);
/*
** < operations.c > */

t_res		oper_swap(t_engine *engine, t_flag what);
t_res		oper_push(t_engine *engine, t_flag to);
t_res		oper_rotate(t_engine *engine, t_flag what);
t_res		oper_rev_rotate(t_engine *engine, t_flag what);
#endif