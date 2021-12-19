/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_compares_optimized.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:50:39 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 20:54:50 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_mid_then_big(t_engine *e, t_flag f, int pivot[2], int sectors[4])
{
	return (sectors[COUNT] >= 2
		&&is_mid(e, f, pivot)
		&& get_deque(e, f)->head->lower->num >= pivot[HI]);
}

bool	is_mid_then_smol(t_engine *e, t_flag f, int pivot[2], int sectors[4])
{
	return (sectors[COUNT] >= 2
		&& is_mid(e, f, pivot)
		&& get_deque(e, f)->head->lower->num < pivot[LO]);
}
