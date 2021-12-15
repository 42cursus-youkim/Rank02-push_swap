/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:31:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/15 17:00:25 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_engine(t_engine *engine, t_deque *input)
{
	engine->a = input;
	engine->b = new_ydeque(0, NULL);
	engine->hist = new_ydeque(0, NULL);
}

void	del_engine(t_engine *engine)
{
	del_ydeque(engine->a);
	del_ydeque(engine->b);
	del_ydeque(engine->hist);
}

void	engine_print_opers(t_engine *engine)
{
	int			i;
	t_dnode		*curs;
	const int	size = engine->hist->size;

	i = -1;
	curs = engine->hist->head;
	while (++i < size)
	{
		ywrite(1, (char *)get_op_name((t_op)curs->num));
		ywrite(1, "\n");
		curs = curs->lower;
	}
}
