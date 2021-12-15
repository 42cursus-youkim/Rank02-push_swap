/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:04:00 by youkim            #+#    #+#             */
/*   Updated: 2021/12/15 19:25:47 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_sortcounter(t_sortres result[2])
{
	result[rots] = 0;
	result[pushes] = 0;
}

static void	send_to_other(t_engine *e, t_flag from, t_sortres result[2])
{
	oper(e, from, PUSH);
	result[pushes]++;
}

static void	roll_down(t_engine *e, t_flag from, t_sortres result[2])
{
	oper(e, from, ROT);
	result[rots]++;
}

static void	roll_back_up(t_engine *e, t_flag from, int rots)
{
	while (--rots >= 0)
		oper(e, from, RROT);
}

/*
	result[2] holds the number of rotations, and number of pushes
*/
void	quicksort(t_engine *e, t_flag from, int size)
{
	int			pivot;
	t_sortres	result[2];

	// engine_visualize(e);
	// if (size == 1 && from == STK_B)
	// 	return ((void)oper(e, from, PUSH));
	if (is_sorted(e) || size == 1 || size > get_deque(e, from)->size)
		return ;
	if (get_deque(e, from)->size <= 3)
		return ((void)smolsort(e, from));
	pivot = get_pivot(e, from, size);
	reset_sortcounter(result);
	while (--size >= 0)
	{
		if (head_num(e, from) <= pivot)
			send_to_other(e, from, result);
		else
			roll_down(e, from, result);
	}
	roll_back_up(e, from, result[rots]);
	// quicksort(e, from, result[rots]);
	// quicksort(e, !from, result[pushes]);
}
