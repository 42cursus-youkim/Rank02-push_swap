/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:26:36 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 10:19:59 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_engine *engine, t_flag from)
{
	int				i;
	t_dnode			*curs;
	const t_deque	*deq = get_deque(engine, from);

	if (deq->size <= 1)
		return (true);
	i = 0;
	curs = deq->head->lower;
	while (++i < engine->a->size)
	{
		if (curs->num < curs->upper->num)
			return (false);
		curs = curs->lower;
	}
	return (true);
}

void	reset_sortcounter(t_sortres result[2])
{
	result[ROTS] = 0;
	result[PUSHES] = 0;
}

void	send_to_other(t_engine *e, t_flag from, t_sortres result[2])
{
	oper(e, from, PUSH);
	result[PUSHES]++;
}

void	roll_down(t_engine *e, t_flag from, t_sortres result[2])
{
	oper(e, from, ROT);
	result[ROTS]++;
}

void	roll_back_up(t_engine *e, t_flag from, int rots)
{
	while (--rots >= 0)
		oper(e, from, RROT);
}
