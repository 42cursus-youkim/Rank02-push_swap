/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:33:26 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 15:27:58 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FIXME: remove later
//	NOTE: remove the whole file on prod, uses PRINTF
void	engine_showcase_oper(t_engine *engine)
{
	const t_inst	inst[4] = {SWAP, ROT, RROT, PUSH};
	const char		*oper_name[4] = { "SWAP", "ROT", "RROT", "PUSH"};

	del_ydeque(engine->a); del_ydeque(engine->b);
	engine->a = new_ydeque(3, (int [3]){1, 2, 3});
	engine->b = new_ydeque(3, (int [3]){11, 12, 13});
	printf("%s<START>%s\n", REDHB, END);
	// engine_visualize(engine);
	for (t_flag which = STK_A; which <= STK_B; which++) {
		for (int i = 0; i < 4; i++) {
			printf("%sSTACK %s:%s ", HRED, which == STK_A ? "A" : "B", END);
			printf("%s%s%s\n", UCYN, oper_name[i], END);
			t_res res = oper(engine, which, inst[i]);
			if (res == ERR)
				printf("%s%s%s\n", HBLU, "ERR", END);
			engine_visualize(engine);
		}
	}
}

//	NOTE: remove the whole file on prod, uses PRINTF
void	engine_visualize(t_engine *engine)
{
	const int		size = ymax(engine->a->size, engine->b->size);
	const t_deque	*deq[3] = {engine->a, engine->b, engine->hist};
	const t_dnode	*curs[3] = {deq[0]->head, deq[1]->head, deq[2]->head};

	for (int i = 0; i < size; i++) {
		printf("%2d: ", i);
		for (int j = 0; j < 2; j++) {
			if (curs[j]) {
				if (i >= size - deq[j]->size) {
					printf("%2d ", curs[j]->num);
					curs[j] = curs[j]->lower;
				} else printf(". ");
			} else printf(". ");
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
