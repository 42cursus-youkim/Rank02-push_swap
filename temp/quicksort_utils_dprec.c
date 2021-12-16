/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils_dprec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:26:36 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 17:04:54 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_engine *e, t_flag from, int size)
{
	int	*arr;
	int	res;

	yassert(size > 0, "get_pivot: size is 0");
	yassert(size <= get_deque(e, from)->size, "get_pivot:size is too big");
	arr = ymalloc(size * sizeof(int));
	set_dequnpack(e, from, size, arr);
	yqsort(size, arr);
	res = ymedian(size, arr);
	free(arr);
	return (res);
	// printf("size: %d\n", size);
	// for (int i = 0; i < size; i++)
	// 	printf("%d ", arr[i]);
	// printf("\nsize / 2: %d\n", size / 2);
	// printf("median: %d\n", arr[size / 2]);
	// return (arr[size / 2]);
	// int		i;
	// t_dnode	*curs;
}

void	reset_sortcounter(t_sortres result[2])
{
	result[ROTS] = 0;
	result[PUSHES] = 0;
}

void	send_to_other(t_engine *e, t_flag from, t_sortres result[2])
{
	oper(e, from, PUSH);
	result[PUSHES]++;
}

void	roll_down(t_engine *e, t_flag from, t_sortres result[2])
{
	oper(e, from, ROT);
	result[ROTS]++;
}

void	roll_back_up(t_engine *e, t_flag from, int rots)
{
	while (--rots >= 0)
		oper(e, from, RROT);
}
