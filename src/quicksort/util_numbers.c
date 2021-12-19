/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:51:43 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 17:32:29 by youkim           ###   ########.fr       */
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
	int		*arr;
	t_dnode	*curs;

	yassert(size > 0, "set_pivot : size is 0");
	yassert(size <= get_deque(e, from)->size, "set_pivot : size is bigger");
	curs = get_deque(e, from)->head;
	arr = ymalloc(size * sizeof(int));
	set_dequnpack(e, from, size, arr);
	yqsort(size, arr);
	pivot[LO] = arr[size / 3];
	pivot[HI] = arr[(size * 2) / 3];
	yassert(pivot[LO] < pivot[HI], "pivot[LO] >= pivot[HI], what is this sorcery");
	printf("pivot : lo [%dth]%d hi [%dth]%d\n",
		(size / 3) + 1, pivot[LO], (size / 3 * 2 )+ 1, pivot[HI]);
	free(arr);
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

bool	is_sorted(t_engine *engine, t_flag from)
{
	int				i;
	t_dnode			*curs;
	const t_deque	*deq = get_deque(engine, from);

	if (deq->size <= 1)
		return (true);
	i = 0;
	curs = deq->head->lower;
	while (++i < engine->a->size)
	{
		if (curs->num < curs->upper->num)
			return (false);
		curs = curs->lower;
	}
	return (true);
}