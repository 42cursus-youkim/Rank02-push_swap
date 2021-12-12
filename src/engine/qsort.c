/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:04:00 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 21:13:58 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition(t_engine *e, t_flag what, int size)
{
	int		rots;
	int		pivot;

	if (size <= 0 || size > get_deque(e, what)->size)
		return ;
	rots = 0;
	pivot = tail_num(e, what);
	while (--size >= 0)
	{
		if (head_num(e, what) <= pivot)
			inst(e, what, PUSH);
		else
		{
			inst(e, what, ROT);
			rots++;
		}
	}
	while (--rots >= 0)
		inst(e, what, RROT);
}
