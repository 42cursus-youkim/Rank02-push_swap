/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:02:07 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 08:53:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_node_b_to_a(t_engine *e, int pivot[2], int sectors[4])
{
	while (--sectors[COUNT] >= 0)
	{
		if (is_big(e, STK_B, pivot))
		{
			oper(e, STK_B, PUSH);
			sectors[BIG]++;
		}
		else if (is_mid(e, STK_B, pivot))
		{
			sectors[MID]++;
			oper(e, STK_B, PUSH);
			if (sectors[COUNT] > 0 && is_smol(e, STK_B, pivot))
			{
				sectors[SMOL]++;
				sectors[COUNT]--;
				operb(e, ROT);
			}
			else
				oper(e, STK_A, ROT);
		}
		else
		{
			oper(e, STK_B, ROT);
			sectors[SMOL]++;
		}
	}
}

void	move_node_a_to_b(t_engine *e, int pivot[2], int sectors[4])
{
	while (--sectors[COUNT] >= 0)
	{
		if (is_big(e, STK_A, pivot))
		{
			oper(e, STK_A, ROT);
			sectors[BIG]++;
		}
		else if (is_mid(e, STK_A, pivot))
		{
			oper(e, STK_A, PUSH);
			if (sectors[COUNT] > 0 && is_big(e, STK_A, pivot))
			{
				operb(e, ROT);
				sectors[BIG]++;
				sectors[COUNT]--;
			}
			else
				oper(e, STK_B, ROT);
			sectors[MID]++;
		}
		else
		{
			oper(e, STK_A, PUSH);
			sectors[SMOL]++;
		}
	}
}

void	move_node_initial(t_engine *e, int pivot[2], int sectors[4])
{
	while (--sectors[COUNT] >= 0)
	{
		if (is_big(e, STK_A, pivot))
		{
			oper(e, STK_A, ROT);
			sectors[BIG]++;
		}
		else if (is_mid(e, STK_A, pivot))
		{
			oper(e, STK_A, PUSH);
			sectors[MID]++;
		}
		else
		{
			oper(e, STK_A, PUSH);
			if (sectors[COUNT] > 0 && is_big(e, STK_A, pivot))
			{
				operb(e, ROT);
				sectors[BIG]++;
				sectors[COUNT]--;
			}
			else
				oper(e, STK_B, ROT);
			sectors[SMOL]++;
		}
	}
}

//	efficiently rewind both sectors
void	rewind_sector(t_engine *e, int sectors[3], t_sortflag which[2])
{
	int			i;
	const int	size[2] = {sectors[which[STK_A]], sectors[which[STK_B]]};
	const int	both = ymin(size[STK_A], size[STK_B]);
	const int	not_both[2] = {size[STK_A] - both, size[STK_B] - both};

	i = -1;
	while (++i < both)
		operb(e, RROT);
	i = -1;
	while (++i < not_both[STK_A])
		oper(e, STK_A, RROT);
	i = -1;
	while (++i < not_both[STK_B])
		oper(e, STK_B, RROT);
}
