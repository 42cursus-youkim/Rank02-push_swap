/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:05:09 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 20:27:55 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smolsort_b_to_a(t_engine *e, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		oper(e, STK_B, PUSH);
	smolsort(e, STK_A, size);
}

void	b_to_a(t_engine *e, int size)
{
	int	pivot[2];
	int	sectors[4];

	if (size <= 2)
		return ((void)smolsort_b_to_a(e, size));
	set_sectors(sectors, size);
	set_pivot(e, STK_B, size, pivot);
	move_node_b_to_a(e, pivot, sectors);
	a_to_b(e, sectors[BIG]);
	rewind_sector(e, sectors, (t_sortflag [2]){MID, SMOL});
	a_to_b(e, sectors[MID]);
	b_to_a(e, sectors[SMOL]);
}
