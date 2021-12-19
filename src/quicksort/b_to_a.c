/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:05:09 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 20:12:52 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	rewind_sector(e, psize, (t_sortflag [2]){MID, SMOL});
	// for (int i = 0; i < psize[MID]; i++) // rewind mid
	// {
	// 	oper(e, STK_A, RROT);
	// }
	// for (int i = 0; i < psize[SMOL]; i++) // rewind smol
	// {
	// 	oper(e, STK_B, RROT);
	// }
	a_to_b(e, psize[MID]);
	b_to_a(e, psize[SMOL]);
}
