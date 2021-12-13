/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:31:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 20:15:21 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*get_input(const int argc, const char *argv[])
{
	int		i;
	t_dnode	*node;
	t_deque	*deque;

	i = argc;
	deque = new_ydeque(0, NULL);
	while (--i > 0)
	{
		node = new_ydequenode(yatoi(argv[i]));
		ydeque_push(deque, node);
	}
	ydeque_show(deque);
	return (deque);
}

void	init_engine(t_engine *engine, int size, int nums[])
{
	engine->a = new_ydeque(size, nums); //get_input(argc, argv);
	engine->b = new_ydeque(0, NULL);
	engine->hist = new_ydeque(0, NULL);
}

void	del_engine(t_engine *engine)
{
	del_ydeque(engine->a);
	del_ydeque(engine->b);
	del_ydeque(engine->hist);
}
