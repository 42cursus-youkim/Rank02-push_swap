/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:33:26 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 15:24:57 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	engine_showcase_oper(t_engine *engine)
{
	int			i;
	t_status	res;

	i = -1;
	del_ydeque(engine->b);
	engine->b = new_ydeque(3, (int [3]){10, 11, 12});
	while (++i <= RRR)
	{
		printf("%s%s%s\n", HRED, get_op_name(i), END);
		res = oper(engine, (t_op)i);
		if (res == ERR)
			printf("%s%s%s\n", HBLU, "ERR", END);
		engine_visualize(engine);
	}
}

//	NOTE: remove it on prod, uses PRINTF
void	engine_visualize(t_engine *engine)
{
	const int			size = ymax(
		engine->a->size, engine->b->size);
	const t_deque		*deq[3] = {
		engine->a, engine->b, engine->hist};
	const t_dnode	*curs[3] = {
		deq[0]->head, deq[1]->head, deq[2]->head};

	for (int i = 0; i < size; i++) {
		printf("%2d: ", i);
		for (int j = 0; j < 2; j++) {
			if (curs[j]) {
				if (i >= size - deq[j]->size) {
					printf("%2d ", curs[j]->num);
					curs[j] = curs[j]->lower;
				} else {
					printf(". ");
				}
			}
			else
				printf(". ");
		}
		printf("\n");
	}
	printf("%s(x%d)%s ", HYEL, deq[2]->size, END);
	for (int i = 0; i < deq[2]->size; i++) {
		printf("%s%s%s ", HYEL, get_op_name(curs[2]->num), END);
		curs[2] = curs[2]->lower;
	}
	printf("\n");
}
