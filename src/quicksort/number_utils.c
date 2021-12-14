/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:51:43 by youkim            #+#    #+#             */
/*   Updated: 2021/12/14 20:26:18 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	head_num(t_engine *engine, t_flag from)
{
	return (get_deque(engine, from)->head->num);
}

int	tail_num(t_engine *engine, t_flag from)
{
	return (get_deque(engine, from)->tail->num);
}

void	set_head_nums(t_engine *e, t_flag from, int size, int arrs[])
{
	int		i;
	t_dnode	*curs;

	yassert(size <= get_deque(e, from)->size, "can't unpack that big");
	i = -1;
	curs = get_deque(e, from)->head;
	while (++i < size)
	{
		arrs[i] = curs->num;
		curs = curs->lower;
	}
}
