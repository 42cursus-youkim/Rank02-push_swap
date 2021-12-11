/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:31:28 by youkim            #+#    #+#             */
/*   Updated: 2021/12/11 17:46:02 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	oper_swap(t_engine *engine, t_flag which)
{
	t_deque		*deq;
	t_dequenode	*nodes[2];

	deq = get_deque(engine, which);
	nodes[0] = ydeque_pop(deq);
	nodes[1] = ydeque_pop(deq);
	ydeque_push(deq, nodes[0]);
	ydeque_push(deq, nodes[1]);
}

void	oper_push(t_engine *engine, t_flag which)
{
	t_deque		*deqs[2];

	deqs[STACK_FROM] = get_deque_reversed(engine, which);
	deqs[STACK_TO] = get_deque(engine, which);
	ydeque_push(deqs[STACK_TO], ydeque_pop(deqs[STACK_FROM]));
}
