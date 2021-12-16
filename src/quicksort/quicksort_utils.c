/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:02:07 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 16:28:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_big(t_engine *e, t_flag f, int pivot[2])
{
	return (head_num(e, f) >= pivot[HI]);
}

static bool	is_mid(t_engine *e, t_flag f, int pivot[2])
{
	return (pivot[HI] > head_num(e, f) && head_num(e, f) >= pivot[LO]);
}

static bool	is_mid_after_big(t_engine *e, t_flag f, int pivot[2])
{
	return (is_mid(e, f, pivot)
		&& get_deque(e, f)->head->lower->num >= pivot[HI]);
}

static void	do_mid_and_big(t_engine *e, t_flag f, int psize[4])
{
	oper(e, f, PUSH);
	operb(e, ROT);
	psize[MID]++;
	psize[BIG]++;
	psize[COUNTER]--;
}

void	move_node(t_engine *e, t_flag f, int pivot[2], int psize[4])
{
	while (--psize[COUNTER] >= 0)
	{
		if (psize[COUNTER] > 0 && is_mid_after_big(e, f, pivot))
			do_mid_and_big(e, f, psize);
		else if (is_big(e, f, pivot))
		{
			oper(e, f, ROT);
			psize[BIG]++;
		}
		else if (is_mid(e, f, pivot))
		{
			oper(e, f, PUSH);
			oper(e, !f, ROT);
			psize[MID]++;
		}
		else
		{
			oper(e, f, PUSH);
			psize[SMOL]++;
		}
	}
}
