/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:31:28 by youkim            #+#    #+#             */
/*   Updated: 2021/12/14 19:47:43 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_res	oper_swap(t_engine *engine, t_flag from)
{
	t_deque	*deq;
	t_dnode	*nodes[2];

	deq = get_deque(engine, from);
	if (deq->size < 2)
		return (ERR);
	nodes[0] = ydeque_pop(deq);
	nodes[1] = ydeque_pop(deq);
	ydeque_push(deq, nodes[0]);
	ydeque_push(deq, nodes[1]);
	return (OK);
}

static t_res	oper_push(t_engine *engine, t_flag from)
{
	t_deque		*deqs[2];

	set_deques_from_to(engine, deqs, from);
	if (deqs[STK_FROM]->size < 1)
		return (ERR);
	ydeque_push(deqs[STK_TO], ydeque_pop(deqs[STK_FROM]));
	return (OK);
}

static t_res	oper_rotate(t_engine *engine, t_flag from)
{
	t_deque		*deq;

	deq = get_deque(engine, from);
	if (deq->size < 2)
		return (ERR);
	ydeque_push_back(deq, ydeque_pop(deq));
	return (OK);
}

static t_res	oper_rev_rotate(t_engine *engine, t_flag from)
{
	t_deque		*deq;

	deq = get_deque(engine, from);
	if (deq->size < 2)
		return (ERR);
	ydeque_push(deq, ydeque_pop_back(deq));
	return (OK);
}

//	deque agnostic instructions for actual algorithm
t_res	oper(t_engine *engine, t_flag from, t_inst inst)
{
	const t_op		ops[2][4] = {{SA, RA, RRA, PA}, {SB, RB, RRB, PB}};
	const t_oper_f	oper_f[4] = {
		oper_swap, oper_rotate, oper_rev_rotate, oper_push};

	if (!((from == STK_A || from == STK_B) && (SWAP <= inst && inst <= PUSH)))
		return (ERR);
	ydeque_push_back(engine->hist, new_ydequenode(ops[from][inst]));
	return (oper_f[inst](engine, from));
}
