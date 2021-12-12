/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:12:27 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 14:24:15 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_one_ops_ok(
	 const t_op choice[3], t_op op, t_status stat[2])
{
	return ((op != choice[STACK_BOTH]
			&& (
				stat[STACK_A] == SUCCESS
				|| stat[STACK_B] == SUCCESS
			)));
}

static bool	is_two_ops_ok(
	 const t_op choice[3], t_op op, t_status stat[2])
{
	return (op == choice[STACK_BOTH]
		&& stat[STACK_A] == SUCCESS
		&& stat[STACK_B] == SUCCESS);
}

static t_status	oper_handle_result(t_engine *engine,
		const t_op choice[3], t_op op, t_status stat[2])
{
	if (is_one_ops_ok(choice, op, stat) || is_two_ops_ok(choice, op, stat))
		ydeque_push(engine->hist, new_ydequenode(op));
	else
	{
		if (stat[STACK_A] == SUCCESS)
			ydeque_push(engine->hist, new_ydequenode(choice[STACK_A]));
		else if (stat[STACK_B] == SUCCESS)
			ydeque_push(engine->hist, new_ydequenode(choice[STACK_B]));
		return (ERROR);
	}
	return (SUCCESS);
}

/*	is it SA? SB? or SS? this function checks it for you!
	usage: oper_manager(engine, (t_op[3]){SA, SB, SS}, op, func);
*/
static t_status	oper_manager(t_engine *engine,
		const t_op choice[3], t_op op, t_oper_f oper_f)
{
	t_status	stat[2];

	stat[STACK_A] = UNSET;
	stat[STACK_B] = UNSET;
	if (!choice[STACK_BOTH] && op == choice[STACK_BOTH])
		yerror("oper_manager", "tried to choose nonexistant stack");
	if (op == choice[STACK_A] || op == choice[STACK_BOTH])
		stat[STACK_A] = oper_f(engine, STACK_A);
	if (op == choice[STACK_B] || op == choice[STACK_BOTH])
		stat[STACK_B] = oper_f(engine, STACK_B);
	return (oper_handle_result(engine, choice, op, stat));
}

/*	handles all 11 operations, use enum t_op to choose
	TODO: record operation to engine->hist
*/
t_status	oper(t_engine *engine, t_op op)
{
	t_status	stat;
	const t_op	swap[3] = {SA, SB, SS};
	const t_op	push[3] = {PA, PB, NOP};
	const t_op	rotate[3] = {RA, RB, RR};
	const t_op	rev_rotate[3] = {RRA, RRB, RRR};

	stat = UNSET;
	if (swap[0] <= op && op <= swap[2])
		stat = oper_manager(engine, swap, op, oper_swap);
	else if (push[0] <= op && op <= push[1])
		stat = oper_manager(engine, push, op, oper_push);
	else if (rotate[0] <= op && op <= rotate[2])
		stat = oper_manager(engine, rotate, op, oper_rotate);
	else if (rev_rotate[0] <= op && op <= rev_rotate[2])
		stat = oper_manager(engine, rev_rotate, op, oper_rev_rotate);
	else
		yerror("oper", "tried to choose nonexistant operation");
	return (stat);
}
