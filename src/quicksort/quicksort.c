/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:04:00 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 10:50:18 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	roll_down(t_engine *e, t_flag this, int *prots)
{
	oper(e, this, ROT);
	(*prots)++;
}

static void	roll_back_up(t_engine *e, t_flag this, int rots)
{
	while (--rots >= 0)
		oper(e, this, RROT);
}

void	partition(t_engine *e, t_flag this, int size)
{
	int		rots;
	int		pivot;

	if (size <= 0 || size > get_deque(e, this)->size)
		return ;
	rots = 0;
	pivot = tail_num(e, this);
	while (--size >= 0)
	{
		if (head_num(e, this) <= pivot)
			oper(e, this, PUSH);
		else
			roll_down(e, this, &rots);
	}
	roll_back_up(e, this, rots);
}
