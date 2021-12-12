/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:55:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 21:00:32 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_deque_sorted(t_engine *engine)
{
	int		i;
	t_dnode	*curs;

	if (engine->a->size == 0 || engine->b->size > 0)
		return (false);
	i = 0;
	curs = engine->a->head->lower;
	while (++i < engine->a->size)
	{
		printf("%d: %d, up: %d\n", i, curs->num, curs->upper->num);
		if (curs->num < curs->upper->num)
			return (false);
		curs = curs->lower;
	}
	return (true);
}

//	TODO: better pivot selection
void	partition(t_engine *engine, t_flag what, int size)
{
	int		rots;
	int		pivot;

	if (size <= 0 || size > engine->a->size)
		return ;
	rots = 0;
	pivot = engine->a->tail->num;
	while (--size >= 0)
	{
		printf("%d\n", engine->a->head->num);
		if (engine->a->head->num <= pivot)
			inst(engine, what, PUSH);
		else
		{
			inst(engine, what, ROT);
			rots++;
		}
	}
	while (--rots >= 0)
		inst(engine, what, RROT);
}

t_res	engine_solve(t_engine *engine)
{
	if (is_deque_sorted(engine))
		return (OK);
	return (ERR);
}

//	deque agnostic instructions for actual algorithm
t_res	inst(t_engine *engine, t_flag what, t_inst inst)
{
	const t_op		ops[2][4] = {{SA, RA, RRA, PB}, {SB, RB, RRB, PA}};

	if (!(what == STK_A || what == STK_B || (SWAP <= inst && inst <= PUSH)))
		return (ERR);
	return (oper(engine, ops[what][inst]));
}
