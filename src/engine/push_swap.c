/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/15 20:26:43 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_input(const int argc, const char *argv[])
{
	if (argc || argv)
		return ;
	// check_duplicate(argc, argv);
}

void	solve(t_engine *engine)
{
	// initial_partitioning(engine);
	partition(engine, STK_A, engine->a->size);
	partition(engine, STK_B, engine->b->size);
}

int	main(const int argc, const char *argv[])
{
	t_engine	engine;

	check_input(argc, argv);
	// init_engine(&engine, new_ydeque(3, (int []){1, 2, 3}));
	init_engine(&engine, get_input(argc, argv));
	// printf("sorted: %d\n", is_sorted(&engine, STK_A));
	// engine_showcase_oper(&engine);
	// engine_visualize(&engine);
	solve(&engine);
	// smolsort(&engine, STK_A);
	// oper(&engine, STK_A, PUSH);
	// engine_visualize(&engine);
	// yassert(is_deque_sorted(&engine), "deque is not sorted");
	engine_print_opers(&engine);
	del_engine(&engine);
	return (0);
}
