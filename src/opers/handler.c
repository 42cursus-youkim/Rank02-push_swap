/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:12:27 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 21:03:20 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_one_ops_ok(const t_op choice[3], t_op op, t_res stat[2])
{
	return (op != choice[STK_BOTH] && (stat[STK_A] == OK || stat[STK_B] == OK));
}

static bool	is_two_ops_ok(const t_op choice[3], t_op op, t_res stat[2])
{
	return (op == choice[STK_BOTH] && stat[STK_A] == OK && stat[STK_B] == OK);
}

static t_res	oper_handle_result(t_engine *engine,
		const t_op choice[3], t_op op, t_res stat[2])
{
	if (is_one_ops_ok(choice, op, stat) || is_two_ops_ok(choice, op, stat))
		ydeque_push(engine->hist, new_ydequenode(op));
	else
	{
		if (stat[STK_A] == OK)
			ydeque_push(engine->hist, new_ydequenode(choice[STK_A]));
		else if (stat[STK_B] == OK)
			ydeque_push(engine->hist, new_ydequenode(choice[STK_B]));
		return (ERR);
	}
	return (OK);
}

/*	is it SA? SB? or SS? this function checks it for you!
	usage: oper_manager(engine, (t_op[3]){SA, SB, SS}, op, func);
*/
static t_res	oper_manager(t_engine *engine,
		const t_op choice[3], t_op op, t_oper_f oper_f)
{
	t_res	stat[2];

	stat[STK_A] = UNSET;
	stat[STK_B] = UNSET;
	if (!choice[STK_BOTH] && op == choice[STK_BOTH])
		yerror("oper_manager", "tried to choose nonexistant stack");
	if (op == choice[STK_A] || op == choice[STK_BOTH])
		stat[STK_A] = oper_f(engine, STK_A);
	if (op == choice[STK_B] || op == choice[STK_BOTH])
		stat[STK_B] = oper_f(engine, STK_B);
	return (oper_handle_result(engine, choice, op, stat));
}

/*	handles all 11 operations, use enum t_op to choose
*/
t_res	oper(t_engine *engine, t_op op)
{
	int				i;
	const t_op		ops[4][3] = {
		{SA, SB, SS}, {RA, RB, RR}, {RRA, RRB, RRR}, {PA, PB, NOP}};
	const t_oper_f	oper_f[4] = {
		oper_swap, oper_rotate, oper_rev_rotate, oper_push};

	if (!(SA <= op && op <= RRR))
		yerror("oper", "tried to choose nonexistant operation");
	i = -1;
	while (++i < 3)
		if (ops[i][0] <= op && op <= ops[i][2])
			return (oper_manager(engine, ops[i], op, oper_f[i]));
	return (oper_manager(engine, ops[i], op, oper_f[i]));
}
