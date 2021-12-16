/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:02:07 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 17:38:56 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rewind_partition(t_engine *e, t_flag from, int size)
{
	while (--size >= 0)
		oper(e, from, RROT);
}

void	move_node(t_engine *e, t_flag f, int pivot[2], int psize[4])
{
	while (--psize[COUNTER] >= 0)
	{
		if (psize[COUNTER] > 0 && is_mid_after_big(e, f, pivot))
			send_mid_big(e, f, psize);
		else if (is_big(e, f, pivot))
			send_big_down(e, f, psize);
		else if (is_mid(e, f, pivot))
			send_mid_down(e, f, psize);
		else
			send_smol_up(e, f, psize);
	}
}
