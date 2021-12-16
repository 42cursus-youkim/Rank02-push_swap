/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:55:35 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 17:52:17 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_initial(t_engine *e, int psize[4])
{
	int	pivot[2];

	set_pivot(e, STK_A, e->a->size, pivot);
	move_node(e, STK_A, pivot, psize);
	a_to_b(e, psize[BIG]);
}

void	b_to_a(t_engine *e, int size)
{
	int	pivot[2];
	int	psize[3] = {0, 0, 0};

	if (size <= 3)
		return;
	set_pivot(e, STK_A, size, pivot);
	rewind_partition(e, STK_B, size);
	while (--size >= 0)
	{
		if (is_big(e, STK_B, pivot))
		{
			oper(e, STK_B, PUSH);
			psize[BIG]++;
		}
		else if (is_mid(e, STK_B, pivot))
		{
			oper(e, STK_B, PUSH);
			oper(e, STK_A, ROT);
			psize[MID]++;
		}
		else
		{
			oper(e, STK_B, ROT);
			psize[SMOL]++;
		}
	}
}

void	a_to_b(t_engine *e, int size)
{
	int	pivot[2];
	int	psize[4] = {0, 0, 0, size};
	// const t_flag from = STK_A;

	printf("big\n");
	set_pivot(e, STK_A, size, pivot);
	move_node(e, STK_A, pivot, psize);
	{
		if (psize[BIG] > 3)
			a_to_b(e, psize[BIG]);
		else
			smolsort(e, STK_A, 3);
		// if (psize[MID] > 3)
		// 	b_to_a(e, psize[MID]);
	}
	return ;
	{
		for (int i = 0; i < psize[MID]; i++) // return mid
		{
			oper(e, STK_B, RROT);
			oper(e, STK_B, PUSH);
		}
		for (int i = 0; i < psize[SMOL]; i++) // return smol
		{
			oper(e, STK_B, PUSH);
		}
	}
}
// if (psize[MID] > 3)
// 	partition_b(e, psize[MID]);
// for (int i = 0; i < psize[MID]; i++)
// 	oper(e, !from, PUSH);
// printf("BIG %d MID %d SMOL %d\n", psize[SMOL], psize[MID], psize[BIG]);
// partition_big(e, psize[MID], !from);
// partition_to_3(e, psize[SMOL], !from);
