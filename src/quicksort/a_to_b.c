/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:55:35 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 09:41:54 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	assumes deque size is at least bigger than 3
void	partition_initial(t_engine *e)
{
	int	size;
	int	pivot[2];
	int	sectors[4];

	size = e->a->size;
	set_sectors(sectors, size);
	set_pivot(e, STK_A, size, pivot);
	move_node_initial(e, pivot, sectors);
	a_to_b(e, sectors[BIG]);
	b_to_a(e, sectors[MID]);
	b_to_a(e, sectors[SMOL]);
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
