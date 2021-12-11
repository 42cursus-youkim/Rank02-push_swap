/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:31:28 by youkim            #+#    #+#             */
/*   Updated: 2021/12/11 19:09:20 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_status	oper_swap(t_engine *engine, t_flag which)
{
	t_deque		*deq;
	t_dequenode	*nodes[2];

	deq = get_deque(engine, which);
	if (deq->size < 2)
		return (ERROR);
	nodes[0] = ydeque_pop(deq);
	nodes[1] = ydeque_pop(deq);
	ydeque_push(deq, nodes[0]);
	ydeque_push(deq, nodes[1]);
	return (SUCCESS);
}

t_status	oper_push(t_engine *engine, t_flag which)
{
	t_deque		*deqs[2];

	deqs[STACK_FROM] = get_deque_reversed(engine, which);
	deqs[STACK_TO] = get_deque(engine, which);
	if (deqs[STACK_FROM]->size < 1)
		return (ERROR);
	ydeque_push(deqs[STACK_TO], ydeque_pop(deqs[STACK_FROM]));
	return (SUCCESS);
}

t_status	oper_rotate(t_engine *engine, t_flag which)
{
	t_deque		*deq;

	deq = get_deque(engine, which);
	if (deq->size < 2)
		return (ERROR);
	ydeque_push_back(deq, ydeque_pop(deq));
	return (SUCCESS);
}

t_status	oper_rev_rotate(t_engine *engine, t_flag which)
{
	t_deque		*deq;

	deq = get_deque(engine, which);
	if (deq->size < 2)
		return (ERROR);
	ydeque_push(deq, ydeque_pop_back(deq));
	return (SUCCESS);
}
