/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:03:37 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 20:56:55 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

//	instructions you'll print out
typedef enum e_op
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR = 10,
	NOP = -1,
}	t_op;

//	deque-agnostic instructions
typedef enum e_inst
{
	SWAP = 0,
	ROT,
	RROT,
	PUSH,
}	t_inst;

//	stack you are referring to
typedef enum e_flag
{
	STK_A = 0,
	STK_B = 1,
	STK_BOTH = 2,
	STK_FROM = 0,
	STK_TO = 1,
}	t_flag;

//	one for a, one for b, one for history
typedef struct s_engine
{
	t_deque	*a;
	t_deque	*b;
	t_deque	*hist;
}	t_engine;

typedef t_res(*t_oper_f)(t_engine *engine, t_flag this);

#endif