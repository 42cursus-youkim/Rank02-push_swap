/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:55:35 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 19:59:58 by youkim           ###   ########.fr       */
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
	init_array(psize, 3);
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
	b_to_a( e, psize[SMOL]);
}

void	b_to_a(t_engine *e, int size)
{
	int	pivot[2];
	int	psize[3];

	if (size <= 2)
	{
		for (int i = 0; i < size; i++)
			oper(e, STK_B, PUSH);
		return ((void)smolsort(e, STK_A, size));
		 ;
	}
	init_array(psize, 3);
	set_pivot(e, STK_B, size, pivot);

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

	a_to_b(e, psize[BIG]);

	for (int i = 0; i < psize[MID]; i++) // rewind mid
	{
		oper(e, STK_A, RROT);
	}
	for (int i = 0; i < psize[SMOL]; i++) // rewind smol
	{
		oper(e, STK_B, RROT);
	}

	a_to_b(e, psize[MID]);
	b_to_a(e, psize[SMOL]);
}

void	a_to_b(t_engine *e, int size)
{
	int	pivot[2];
	int	psize[3];

	if (size <= 2)
		return ((void)smolsort(e, STK_A, size));
	init_array(psize, 3);
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
			oper(e, STK_B, ROT);
			psize[MID]++;
		}
		else
		{
			oper(e, STK_A, PUSH);
			psize[SMOL]++;
		}
	}

	for (int i = 0; i < psize[BIG]; i++)
		oper(e, STK_A, RROT);
	for (int i = 0; i < psize[MID]; i++)
		oper(e, STK_B, RROT);

	a_to_b(e, psize[BIG]); // [3]
	b_to_a(e, psize[MID]); // [2]
	b_to_a( e, psize[SMOL]);// [1]
}
