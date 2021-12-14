/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:41:54 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 21:08:00 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*get_deque(t_engine *engine, t_flag from)
{
	if (from == STK_A)
		return (engine->a);
	else if (from == STK_B)
		return (engine->b);
	else if (from == STK_BOTH)
		yerror("get_deque", "STK_BOTH is only allowed in oper_manager");
	yerror("get_deque", "tried to choose nonexistant stack");
	return (NULL);
}

void	set_deques_from_to(t_engine *engine, t_deque *deqs[2], t_flag from)
{
	if (!(from == STK_A || from == STK_B))
		yerror("get_deques_from_to", "tried to choose nonexistant stack");
	deqs[STK_FROM] = get_deque(engine, from);
	deqs[STK_TO] = get_deque(engine, !from);
}

const char	*get_op_name(t_op op)
{
	const static char	*op_name[11] = {
		"SA", "SB", "SS", "PA", "PB", "RA", "RB", "RR", "RRA", "RRB", "RRR"};

	if (!(SA <= op && op <= RRR))
		yerror("get_op_name", "tried to get nonexistant operation name");
	return (op_name[op]);
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
