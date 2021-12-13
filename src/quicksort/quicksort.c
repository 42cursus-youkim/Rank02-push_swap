/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:04:00 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 21:00:56 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	roll_down(t_engine *e, t_flag from, int *prots)
{
	oper(e, from, ROT);
	(*prots)++;
}

static void	roll_back_up(t_engine *e, t_flag from, int rots)
{
	while (--rots >= 0)
		oper(e, from, RROT);
}

void	partition(t_engine *e, t_flag from, int size)
{
	int		rots;
	int		pivot;

	if (size <= 0 || size > get_deque(e, from)->size)
		return ;
	rots = 0;
	pivot = tail_num(e, from);
	while (--size >= 0)
	{
		if (head_num(e, from) <= pivot)
			oper(e, from, PUSH);
		else
			roll_down(e, from, &rots);
	}
	roll_back_up(e, from, rots);
}
