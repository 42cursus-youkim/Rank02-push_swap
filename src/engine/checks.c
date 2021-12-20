/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:55:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 17:33:11 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(const int argc, const char *argv[])
{
	t_vec	vec;

	vec.x = 0;
	while (++vec.x < argc)
	{
		vec.y = vec.x;
		while (++vec.y < argc)
		{
			if (ystrequ(argv[vec.x], argv[vec.y]))
				yerror("check_duplicate", "duplicate values");
		}
	}
}

bool	is_sort_complete(t_engine *engine)
{
	int				i;
	t_dnode			*curs;
	const t_deque	*deq = engine->a;

	if (engine->b->size != 0)
		return (false);
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

static void	add_values(t_deque *deq, char *strs[])
{
	t_vec	vec;
	int		n;

	vec_set(&vec, (t_vec){-1, -1});
	while (strs[++vec.x])
	{
		vec.y = -1;
		while (++vec.y < ystrlen(strs[vec.x]))
			yassert(
				is_char(strs[vec.x][vec.y], DIGIT)
				|| ystrchri("-+ ", strs[vec.x][vec.y]) >= 0,
				"add_values", "invalid char");
		yassert(is_int_overflow(strs[vec.x]) == false,
			"add_values", "int overflow!");
		yassert(yatoi(strs[vec.x], &n) == OK, "add_values", "invalid input!");
		ydeque_push_back(deq, new_ydequenode(n));
	}
	del_ystrarr(strs);
}

t_deque	*check_and_get_input(const int argc, const char *argv[])
{
	int		i;
	t_deque	*deq;

	check_duplicate(argc, argv);
	i = 0;
	deq = new_ydeque(0, NULL);
	while (++i < argc)
		add_values(deq, new_ysplit(argv[i], ' '));
	return (deq);
}
