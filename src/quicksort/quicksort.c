/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:55:35 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 17:09:02 by youkim           ###   ########.fr       */
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

	printf("%sb_to_a with size: %d%s\n", HYEL, size, END);
	/*
		. 2
		3 1
		# #
		# #
		A B
	*/
	if (size <= 3)
	{
		for (int i = 0; i < size; i++)
		{
			oper(e, STK_B, PUSH);
		}
		smolsort(e, STK_A, size);
		VIZUAL
		return ;
	}
		// return ;
		// return ((void)smolsort(e, STK_B, size));
	set_pivot(e, STK_B, size, pivot);
	// rewind_partition(e, STK_B, size);
	/*
		. *
		# #
		# #
		A B
	*/
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
	/*
		3 .
		# #
		# #
		2 1
		A B
	*/
	// 3 먼저 정렬하기
	VIZUAL
	{
		a_to_b(e, psize[BIG]);
	}
	VIZUAL
	{
		for (int i = 0; i < psize[MID]; i++) // rewind mid
		{
			oper(e, STK_A, RROT);
		}
		for (int i = 0; i < psize[SMOL]; i++) // rewind smol
		{
			oper(e, STK_B, RROT);
		}
	}
	/*
		2 .
		3 1
		# #
		# #
		A B
	*/
	VIZUAL
	{
		a_to_b(e, psize[MID]);
		b_to_a(e, psize[SMOL]);
	}
	VIZUAL
}

void	a_to_b(t_engine *e, int size)
{
	int	pivot[2];
	int	psize[3] = {0, 0, 0};
	// const t_flag from = STK_A;
	printf("%sa_to_b with size: %d%s\n", HRED, size, END);
	if (size <= 3)
	{
		smolsort(e, STK_A, size);
		VIZUAL
		return ;
	}
	set_pivot(e, STK_A, size, pivot);
	/*
		* .
		# #
		# #
		A B
	*/
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
			oper(e, STK_B, ROT);
			psize[MID]++;
		}
		else
		{
			oper(e, STK_A, PUSH);
			psize[SMOL]++;
		}
	}
	/*
		. 1
		# #
		# #
		3 2
		A B
	*/
	VIZUAL
	{
		for (int i = 0; i < psize[BIG]; i++) // rewind big
		{
			oper(e, STK_A, RROT);
		}
		for (int i = 0; i < psize[MID]; i++) // rewind smol
		{
			oper(e, STK_B, RROT);
		}
	}
	/*
		. 2
		3 1
		# #
		# #
		A B
	*/
	VIZUAL
	{
		a_to_b(e, psize[BIG]); // [3]
		b_to_a(e, psize[MID]); // [2]
		b_to_a(e, psize[SMOL]);// [1]
	}
	VIZUAL
}
// if (psize[MID] > 3)
// 	partition_b(e, psize[MID]);
// for (int i = 0; i < psize[MID]; i++)
// 	oper(e, !from, PUSH);
// printf("BIG %d MID %d SMOL %d\n", psize[SMOL], psize[MID], psize[BIG]);
// partition_big(e, psize[MID], !from);
// partition_to_3(e, psize[SMOL], !from);
