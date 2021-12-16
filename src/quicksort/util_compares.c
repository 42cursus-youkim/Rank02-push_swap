/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_compares.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:08:35 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 17:09:31 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_big(t_engine *e, t_flag f, int pivot[2])
{
	return (head_num(e, f) >= pivot[HI]);
}

bool	is_mid(t_engine *e, t_flag f, int pivot[2])
{
	return (pivot[HI] > head_num(e, f) && head_num(e, f) >= pivot[LO]);
}

bool	is_mid_after_big(t_engine *e, t_flag f, int pivot[2])
{
	return (is_mid(e, f, pivot)
		&& get_deque(e, f)->head->lower->num >= pivot[HI]);
}
