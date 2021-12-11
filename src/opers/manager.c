/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:12:27 by youkim            #+#    #+#             */
/*   Updated: 2021/12/11 18:21:42 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*get_deque(t_engine *engine, t_flag which)
{
	if (which == STACK_A)
		return (engine->a);
	else if (which == STACK_B)
		return (engine->b);
	else if (which == STACK_BOTH)
		yerror("get_deque", "STACK_BOTH is only allowed in oper_manager");
	yerror("get_deque", "tried to choose nonexistant stack");
	return (NULL);
}

t_deque	*get_deque_reversed(t_engine *engine, t_flag which)
{
	if (!(STACK_A <= which && which <= STACK_B))
		yerror("get_deque_reversed", "tried to choose nonexistant stack");
	return (get_deque(engine, 1 - which));
}

/*	is it SA? SB? or SS? this function checks it for you!
	usage: oper_manager(engine, (t_op[3]){SA, SB, SS}, op, func);
*/
static void	oper_manager(t_engine *engine,
		const t_op choice[3], t_op op, t_oper_f oper_f)
{
	if (!choice[STACK_BOTH] && op == choice[STACK_BOTH])
		yerror("oper_manager", "tried to choose nonexistant stack");
	if (op == choice[STACK_A] || op == choice[STACK_BOTH])
		oper_f(engine, STACK_A);
	if (op == choice[STACK_B] || op == choice[STACK_BOTH])
		oper_f(engine, STACK_B);
}

/*	handles all 11 operations, use enum t_op to choose
	TODO: record operation to engine->hist
*/
void	oper(t_engine *engine, t_op op)
{
	const t_op	swap[3] = {SA, SB, SS};
	const t_op	push[3] = {PA, PB, NOP};
	// const t_op	rotate[3] = {RA, RB, RR};
	// const t_op	rev_rotate[3] = {RRA, RRB, RRR};

	if (swap[0] <= op && op <= swap[2])
		oper_manager(engine, swap, op, oper_swap);
	else if (push[0] <= op && op <= push[1])
		oper_manager(engine, push, op, oper_push);
	// else if (rotate[0] <= op && op <= rotate[2])
	// 	oper_manager(engine, rotate, op, oper_rotate);
	// else if (rev_rotate[0] <= op && op <= rev_rotate[2])
	// 	oper_manager(engine, rev_rotate, op, oper_rev_rotate);
	else
		yerror("oper", "tried to choose nonexistant operation");
}

//	enum -> const string
const char	*get_op_name(t_op op)
{
	const static char	*op_name[11] = {
		"SA", "SB", "SS", "PA", "PB", "RA", "RB", "RR", "RRA", "RRB", "RRR"
	};

	if (!(SA <= op && op <= RRR))
		yerror("get_op_name", "tried to get nonexistant operation name");
	return (op_name[op]);
}
