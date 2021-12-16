/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:55:35 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 13:07:44 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_big(t_engine *e, int size, t_flag from)
{
	int	pivot[2];
	int	psize[3] = {0, 0, 0};

	printf("size: %d\n", size);
	if (size <= 3)
		return ;
	set_pivot(e, from, size, pivot);
	printf("pivots : %d, %d\n", pivot[LO], pivot[HI]);
	printf("size: %d\n", size);
	while (--size >= 0)
	{
		if (head_num(e, from) >= pivot[HI])
		{
			oper(e, from, ROT);
			psize[BIG]++;
		}
		else if (head_num(e, from) >= pivot[LO])
		{
			oper(e, from, PUSH);
			psize[MID]++;
		}
		else
		{
			oper(e, from, PUSH);
			oper(e, !from, ROT);
			psize[SMOL]++;
		}
	}
	printf("BIG %d MID %d SMOL %d\n", psize[SMOL], psize[MID], psize[BIG]);
	// partition_big(e, psize[BIG], from);
	// partition_big(e, psize[MID], !from);
	// partition_to_3(e, psize[SMOL], !from);
}
