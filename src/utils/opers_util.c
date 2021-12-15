/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:41:54 by youkim            #+#    #+#             */
/*   Updated: 2021/12/15 10:10:54 by youkim           ###   ########.fr       */
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

const char	*get_op_name(t_op op)
{
	const static char	*op_name[11] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

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
