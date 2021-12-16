/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:55:35 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 16:27:49 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_b(t_engine *e, int size)
{
	int	pivot[2];
	int	psize[3] = {0, 0, 0};
	const t_flag from = STK_B;

	set_pivot(e, from, size, pivot);
	if (size <= 3)
		return ;
	while (--size >= 0)
	{
		if (head_num(e, from) >= pivot[HI])
		{
			oper(e, from, PUSH);
			psize[BIG]++;
		}
		// else if (head_num(e, from) >= pivot[LO])
		// {
		// 	oper(e, from, PUSH);
		// 	oper(e, !from, ROT);
		// 	oper(e, from, ROT);
		// 	psize[MID]++;
		// 	psize[SMOL]++;
		// }
		else if (head_num(e, from) >= pivot[LO])
		{
			oper(e, from, PUSH);
			oper(e, !from, ROT);
			psize[MID]++;
		}
		else
		{
			oper(e, from, ROT);
			psize[SMOL]++;
		}
	}
	for (int i = 0; i < psize[MID]; i++)
		oper(e, !from, RROT);
	for (int i = 0; i < psize[SMOL]; i++)
	{
		oper(e, from, RROT);
		oper(e, from, PUSH);
	}
}

void	partition(t_engine *e, t_flag from, int size)
{
	int	pivot[2];
	int	psize[4] = {0, 0, 0, size};

	if (size <= 3)
		return;
	set_pivot(e, from, size, pivot);
	move_node(e, from, pivot, psize);
	// if (psize[BIG] > 3)
	// 	partition(e, from, psize[BIG]);
	// else
	// 	smolsort(e, from, 3);
	// {
	// 	// if (psize[BIG] > 3)
	// 	// 	partition(e, psize[BIG], from);
	// 	// else
	// 	// 	smolsort(e, from);
	// 	// if (psize[MID] > 3)
	// 	// 	partition_b(e, psize[MID]);
	// 	for (int i = 0; i < psize[MID]; i++)
	// 	{
	// 		oper(e, from, PUSH);
	// 	}
	// 	for (int i = 0; i < psize[SMOL]; i++)
	// 	{
	// 		oper(e, !from, RROT);
	// 		oper(e, !from, PUSH);
	// 	}
	// }
}
// if (psize[MID] > 3)
// 	partition_b(e, psize[MID]);
// for (int i = 0; i < psize[MID]; i++)
// 	oper(e, !from, PUSH);
// printf("BIG %d MID %d SMOL %d\n", psize[SMOL], psize[MID], psize[BIG]);
// partition_big(e, psize[MID], !from);
// partition_to_3(e, psize[SMOL], !from);
