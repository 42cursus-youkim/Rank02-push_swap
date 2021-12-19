/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:02:07 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 20:24:58 by youkim           ###   ########.fr       */
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
			oper(e, STK_B, PUSH);
			oper(e, STK_A, ROT);
			sectors[MID]++;
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

void	rewind_sector(t_engine *e, int sectors[3], t_sortflag which[2])
{
	int			i;
	const int	both = ymin(sectors[which[STK_A]], sectors[which[STK_B]]);
	const int	for_a = sectors[which[STK_A]] - both;
	const int	for_b = sectors[which[STK_B]] - both;

	i = -1;
	while (++i < both)
		operb(e, RROT);
	i = -1;
	while (++i < for_a)
		oper(e, STK_A, RROT);
	i = -1;
	while (++i < for_b)
		oper(e, STK_B, RROT);
}
