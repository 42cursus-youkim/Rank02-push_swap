/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:02:07 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 20:13:55 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	move_node(t_engine *e, t_flag f, int pivot[2], int psize[4])
// {
// 	while (--psize[COUNTER] >= 0)
// 	{
// 		if (psize[COUNTER] > 0 && is_mid_after_big(e, f, pivot))
// 			send_mid_big(e, f, psize);
// 		else if (is_big(e, f, pivot))
// 			send_big_down(e, f, psize);
// 		else if (is_mid(e, f, pivot))
// 			send_mid_down(e, f, psize);
// 		else
// 			send_smol_up(e, f, psize);
// 	}
// }

void	rewind_sector(t_engine *e, int psize[3], t_sortflag which[2])
{
	int	i;

	i = -1;
	while (++i < psize[which[STK_A]])
		oper(e, STK_A, RROT);
	i = -1;
	while (++i < psize[which[STK_B]])
		oper(e, STK_B, RROT);
}
