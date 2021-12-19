/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_compares.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:08:35 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 19:55:57 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_big(t_engine *e, t_flag f, int pivot[2])
{
	const int	num = head_num(e, f);

	return (pivot[HI] <= num);
}

bool	is_mid(t_engine *e, t_flag f, int pivot[2])
{
	const int	num = head_num(e, f);

	return (pivot[LO] <= num && num < pivot[HI]);
}

bool	is_smol(t_engine *e, t_flag f, int pivot[2])
{
	const int	num = head_num(e, f);

	return (num < pivot[LO]);
}

bool	is_mid_after_big(t_engine *e, t_flag f, int pivot[2])
{
	return (is_mid(e, f, pivot)
		&& get_deque(e, f)->head->lower->num >= pivot[HI]);
}

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