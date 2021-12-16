/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:04:00 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 11:42:05 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check(t_engine *e, t_flag from, int size, t_sortres result[2])
{
	yassert(size <= get_deque(e, from)->size, "size is too big");
	reset_sortcounter(result);
	return (get_pivot(e, from, size));
}

static bool	is_should_send(t_engine *e, t_flag from, int pivot)
{
	if (from == STK_A)
		return (head_num(e, from) <= pivot);
	else
		return (head_num(e, from) >= pivot);
}

//	result[2] holds the number of rotations, and number of pushes
void	quicksort(t_engine *e, t_flag from, int size)
{
	int			pivot;
	t_sortres	result[2];

	if (size <= 1)
		return ;
	// if (get_deque(e, from)->size <= 3)
	// 	return ((void)smolsort(e, from));
	pivot = check(e, from, size, result);
	while (--size >= 0)
	{
		if (is_should_send(e, from, pivot))
			send_to_other(e, from, result);
		else
			roll_down(e, from, result);
	}
	roll_back_up(e, from, result[ROTS]);
	printf("rot: %d, push: %d from: %d\n", result[ROTS], result[PUSHES], from);
	quicksort(e, !from, result[PUSHES]);
	// quicksort(e, from, result[rots]);
}
