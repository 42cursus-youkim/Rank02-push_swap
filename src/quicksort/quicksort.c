/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:04:00 by youkim            #+#    #+#             */
/*   Updated: 2021/12/14 20:11:45 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_sortcounter(t_engine *e, t_flag from, t_sortres result[2])
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
void	partition(t_engine *e, t_flag from, int size, t_sortres result[2])
{
	int	pivot;

	if (size <= 0 || size > get_deque(e, from)->size)
		return ;
	pivot = tail_num(e, from);
	reset_sortcounter(e, from, result);
	while (--size >= 0)
	{
		if (head_num(e, from) <= pivot)
			send_to_other(e, from, result);
		else
			roll_down(e, from, result);
	}
	roll_back_up(e, from, result[rots]);
}
