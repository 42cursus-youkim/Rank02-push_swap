/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:55:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 20:36:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(const int argc, const char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ystrequ(argv[i], argv[j]))
				yerror("check_duplicate", "duplicate values");
		}
	}
}

t_deque	*get_input(const int argc, const char *argv[])
{
	int		i;
	int		n;
	t_dnode	*node;
	t_deque	*deque;

	i = argc;
	deque = new_ydeque(0, NULL);
	while (--i > 0)
	{
		yatoi(argv[i], &n);
		node = new_ydequenode(n);
		ydeque_push(deque, node);
	}
	return (deque);
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
