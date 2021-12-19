/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:55:35 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 20:23:55 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	assumes deque size is at least bigger than 3
void	partition_initial(t_engine *e)
{
	int	size;
	int	pivot[2];
	int	psize[3];

	size = e->a->size;
	set_sectors(psize, 3);
	set_pivot(e, STK_A, size, pivot);
	while (--size >= 0)
	{
		if (is_big(e, STK_A, pivot))
		{
			oper(e, STK_A, ROT);
			psize[BIG]++;
		}
		else if (is_mid(e, STK_A, pivot))
		{
			oper(e, STK_A, PUSH);
			psize[MID]++;
		}
		else
		{
			oper(e, STK_A, PUSH);
			oper(e, STK_B, ROT);
			psize[SMOL]++;
		}
	}
	a_to_b(e, psize[BIG]);
	b_to_a(e, psize[MID]);
	b_to_a(e, psize[SMOL]);
}

void	a_to_b(t_engine *e, int size)
{
	int	pivot[2];
	int	sectors[4];

	if (size <= 2)
		return ((void)smolsort(e, STK_A, size));
	set_sectors(sectors, size);
	set_pivot(e, STK_A, size, pivot);
	move_node_a_to_b(e, pivot, sectors);
	rewind_sector(e, sectors, (t_sortflag [2]){BIG, MID});
	a_to_b(e, sectors[BIG]);
	b_to_a(e, sectors[MID]);
	b_to_a(e, sectors[SMOL]);
}
