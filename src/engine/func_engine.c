/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:55:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 09:52:54 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_deque_sorted(t_engine *engine)
{
	int		i;
	t_dnode	*curs;

	if (engine->a->size == 0 || engine->b->size > 0)
		return (false);
	i = 0;
	curs = engine->a->head->lower;
	while (++i < engine->a->size)
	{
		printf("%d: %d, up: %d\n", i, curs->num, curs->upper->num);
		if (curs->num < curs->upper->num)
			return (false);
		curs = curs->lower;
	}
	return (true);
}

t_res	engine_solve(t_engine *engine)
{
	if (is_deque_sorted(engine))
		return (OK);
	return (ERR);
}
