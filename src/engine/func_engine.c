/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:33:26 by youkim            #+#    #+#             */
/*   Updated: 2021/12/11 18:28:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	NOTE: remove it on prod, uses PRINTF
void	engine_visualize(t_engine *engine)
{
	const int			size = ymax(
		engine->a->size, engine->b->size);
	const t_deque		*deq[2] = {
		engine->a, engine->b};
	const t_dequenode	*curs[2] = {
		deq[0]->head, deq[1]->head};

	for (int i = 0; i < size; i++) {
		printf("%d: ", i);
		for (int j = 0; j < 2; j++) {
			if (curs[j]) {
				if (i >= size - deq[j]->size) {
					printf("%d ", curs[j]->num);
					curs[j] = curs[j]->lower;
				} else { printf(". "); }
			}
			else
				printf(". ");
		}
		printf("\n");
	}
}
