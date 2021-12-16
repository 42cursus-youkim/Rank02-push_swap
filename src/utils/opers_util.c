/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:41:54 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 15:39:34 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*get_deque(t_engine *engine, t_flag from)
{
	if (from == STK_A)
		return (engine->a);
	else if (from == STK_B)
		return (engine->b);
	else
		yerror("get_deque", "tried to choose nonexistant stack");
	return (NULL);
}

void	set_deques_from_to(t_engine *e, t_deque *deqs[2], t_flag from)
{
	if (!(from == STK_A || from == STK_B))
		yerror("get_deques_from_to", "tried to choose nonexistant stack");
	deqs[STK_FROM] = get_deque(e, from);
	deqs[STK_TO] = get_deque(e, !from);
}

t_res	opers(t_engine *engine, t_flag from, int size, t_inst insts[])
{
	int		i;
	t_res	result;

	i = -1;
	result = OK;
	while (++i < size)
		result = ymin(result, oper(engine, from, insts[i]));
	return (result);
}

t_res	operb(t_engine *engine, t_inst inst)
{
	const t_op		ops[3] = {SS, RR, RRR};
	const t_oper_f	oper_f[3] = {oper_swap, oper_rotate, oper_rev_rotate};

	if (!(SWAP <= inst && inst <= RROT))
		return (ERR);
	ydeque_push_back(engine->hist, new_ydequenode(ops[inst]));
	return (ymin(oper_f[inst](engine, STK_A), oper_f[inst](engine, STK_B)));
}

//	deque agnostic instructions for actual algorithm
t_res	oper(t_engine *engine, t_flag from, t_inst inst)
{
	const t_op		ops[2][4] = {{SA, RA, RRA, PB}, {SB, RB, RRB, PA}};
	const t_oper_f	oper_f[4] = {
		oper_swap, oper_rotate, oper_rev_rotate, oper_push};

	if (!((from == STK_A || from == STK_B) && (SWAP <= inst && inst <= PUSH)))
		return (ERR);
	ydeque_push_back(engine->hist, new_ydequenode(ops[from][inst]));
	return (oper_f[inst](engine, from));
}
