/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:55:35 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 12:45:07 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_to_3(t_engine *e, int size, t_flag from, int pivot[2])
{
	while (--size >= 0)
	{
		if (head_num(e, from) >= pivot[HI])
			oper(e, from, ROT);
		else if (head_num(e, from) >= pivot[LO])
			oper(e, from, PUSH);
		else
		{
			oper(e, from, PUSH);
			oper(e, !from, ROT);
		}
	}
}