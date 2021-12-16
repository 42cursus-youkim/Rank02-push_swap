/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:51:43 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 11:40:55 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	head_num(t_engine *engine, t_flag from)
{
	return (get_deque(engine, from)->head->num);
}

int	tail_num(t_engine *engine, t_flag from)
{
	return (get_deque(engine, from)->tail->num);
}

void	set_pivot(t_engine *e, t_flag from, int size, int pivot[2])
{
	int		i;
	int		*arr;
	t_dnode	*curs;

	yassert(size > 0, "set_pivot: size is 0");
	yassert(size <= get_deque(e, from)->size, "set_pivot:size is too big");
	curs = get_deque(e, from)->head;
	arr = ymalloc(size * sizeof(int));
	set_dequnpack(e, from, size, arr);
	yqsort(size, arr);
	i = -1;
	pivot[LO] = ERR;
	pivot[HI] = ERR;
	while (++i < size)
	{
		if (curs->num == arr[size / 3])
			pivot[LO] = i;
		if (curs->num == arr[size / 3 * 2])
			pivot[HI] = i;
		curs = curs->lower;
	}
	yassert(pivot[LO] != ERR && pivot[HI] != ERR,
		"set_pivot: could not find pivots");
	free(arr);
}

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

void	set_dequnpack(t_engine *e, t_flag from, int size, int arr[])
{
	int		i;
	t_dnode	*curs;

	yassert(size <= get_deque(e, from)->size, "can't unpack that much");
	i = -1;
	curs = get_deque(e, from)->head;
	while (++i < size)
	{
		arr[i] = curs->num;
		curs = curs->lower;
	}
}
