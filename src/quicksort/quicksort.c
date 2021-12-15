/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:04:00 by youkim            #+#    #+#             */
/*   Updated: 2021/12/15 20:21:31 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_partitioning(t_engine *e)
{
	int	i;
	int	pivot;

	i = e->a->size;
	pivot = get_pivot(e, STK_A, e->a->size);
	while (--i >= 0)
	{
		if (head_num(e, STK_A) <= pivot)
			oper(e, STK_A, PUSH);
		else
			oper(e, STK_A, ROT);
	}
}

static int	check(t_engine *e, t_flag from, int size, t_sortres result[2])
{
	yassert(size <= get_deque(e, from)->size, "size is too big");
	reset_sortcounter(result);
	return (get_pivot(e, STK_A, size));
}

//	result[2] holds the number of rotations, and number of pushes
void	a_to_b(t_engine *e, int size)
{
	int			pivot;
	t_sortres	result[2];

	if (get_deque(e, STK_A)->size <= 3)
		return ((void)smolsort(e, STK_A));
	pivot = check(e, STK_A, size, result);
	while (--size >= 0)
	{
		if (head_num(e, STK_A) <= pivot)
			send_to_other(e, STK_A, result);
		else
			roll_down(e, STK_A, result);
	}
	roll_back_up(e, STK_A, result[rots]);
	// quicksort(e, STK_A, result[rots]);
	// quicksort(e, !STK_A, result[pushes]);
}
