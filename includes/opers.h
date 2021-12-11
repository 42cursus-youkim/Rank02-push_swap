/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:30:14 by youkim            #+#    #+#             */
/*   Updated: 2021/12/11 18:21:34 by youkim           ###   ########.fr       */
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

typedef void(*t_oper_f)(t_engine *, t_flag which);

//	@func
/*
** < manager.c > */

t_deque	*get_deque(t_engine *engine, t_flag which);
t_deque	*get_deque_reversed(t_engine *engine, t_flag which);
void	oper(t_engine *engine, t_op op);
char	*get_op_name(t_op op);
/*
** < opers.c > */

void	oper_swap(t_engine *engine, t_flag which);
void	oper_push(t_engine *engine, t_flag which);
#endif