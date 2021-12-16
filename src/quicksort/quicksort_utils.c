/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:02:07 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 15:58:55 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	head_next_num(t_engine *engine, t_flag from)
{
	return (get_deque(engine, from)->head->lower->num);
}

void	move_node(t_engine *e, t_flag from, int pivot[2], int psize[4])
{
	while (--psize[COUNTER] >= 0)
	{
		if (head_num(e, from) >= pivot[HI])
		{
			oper(e, from, ROT);
			psize[BIG]++;
		}
		else if (head_num(e, from) >= pivot[LO])
		{
			oper(e, from, PUSH);
			if (head_num(e, from) >= pivot[HI])
			{
				operb(e, ROT);
				psize[BIG]++;
				psize[COUNTER]--;
			}
			else
				oper(e, !from, ROT);
			psize[MID]++;
		}
		else if (head_num(e, from) < pivot[LO])
		{
			oper(e, from, PUSH);
			psize[SMOL]++;
		}
		else
			yerror("move_node", "but how?");
	}
}
