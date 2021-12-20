/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:55:35 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 09:53:04 by youkim           ###   ########.fr       */
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

//	assumes deque size is at least bigger than 3
void	quicksort(t_engine *engine)
{
	int			pivot[2];
	int			sectors[4];
	const int	size = engine->a->size;

	if (size <= 3)
		return ((void)smolsort(engine, STK_A, size));
	else if (is_sort_complete(engine))
		return ;
	set_sectors(sectors, size);
	set_pivot(engine, STK_A, size, pivot);
	move_node_initial(engine, pivot, sectors);
	a_to_b(engine, sectors[BIG]);
	b_to_a(engine, sectors[MID]);
	b_to_a(engine, sectors[SMOL]);
}

void	a_to_b(t_engine *e, int size)
{
	int	pivot[2];
	int	sectors[4];

	if (size <= 2 || (size == 3 && e->a->size == 3))
		return ((void)smolsort(e, STK_A, size));
	set_sectors(sectors, size);
	set_pivot(e, STK_A, size, pivot);
	move_node_a_to_b(e, pivot, sectors);
	rewind_sector(e, sectors, (t_sortflag [2]){BIG, MID});
	a_to_b(e, sectors[BIG]);
	b_to_a(e, sectors[MID]);
	b_to_a(e, sectors[SMOL]);
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
