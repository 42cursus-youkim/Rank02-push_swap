/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/14 20:33:05 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	check_input(const int argc, const char *argv[])
// {
// 	check_duplicate(argc, argv);
// }
void	solve(t_engine *engine)
{
	quicksort(engine, STK_A, get_deque(engine, STK_A)->size);
	// partition(engine, STK_A, 8, result);
}

int	main(void) //(const int argc, const char *argv[])
{
	t_engine	engine;

	// check_input(argc, argv);
	// init_engine(&engine, argc, argv);
	init_engine(&engine, 8, (int []){1, 5, 2, 3, 8, 6, 7, 4});
	// engine_showcase_oper(&engine);
	// engine_visualize(&engine);
	solve(&engine);
	// smolsort_3(&engine, STK_A);
	// oper(&engine, STK_A, PUSH);
	engine_visualize(&engine);
	// yassert(is_deque_sorted(&engine), "deque is not sorted");
	del_engine(&engine);
	return (0);
}
