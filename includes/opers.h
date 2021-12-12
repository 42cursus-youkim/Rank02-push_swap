/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:30:14 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 14:21:23 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERS_H
# define OPERS_H
typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	NOP = -1,
}	t_op;

typedef enum e_flag
{
	STACK_A = 0,
	STACK_B = 1,
	STACK_BOTH = 2,
	STACK_FROM = 0,
	STACK_TO = 1,
}	t_flag;

typedef t_status	(*t_oper_f)(t_engine *engine, t_flag which);

//	@func
/*
** < manager.c > */

t_status	oper(t_engine *engine, t_op op);
/*
** < manager_utils.c > */

t_deque		*get_deque(t_engine *engine, t_flag which);
t_deque		*get_deque_reversed(t_engine *engine, t_flag which);
const char	*get_op_name(t_op op);
/*
** < opers.c > */

t_status	oper_swap(t_engine *engine, t_flag which);
t_status	oper_push(t_engine *engine, t_flag which);
t_status	oper_rotate(t_engine *engine, t_flag which);
t_status	oper_rev_rotate(t_engine *engine, t_flag which);
#endif