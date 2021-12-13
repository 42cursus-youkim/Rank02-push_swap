/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 20:15:11 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	check_input(const int argc, const char *argv[])
// {
// 	check_duplicate(argc, argv);
// }

int	main(void) //(const int argc, const char *argv[])
{
	t_engine	engine;

	// check_input(argc, argv);
	// init_engine(&engine, argc, argv);
	init_engine(&engine, 8, (int []){4, 7, 2, 6, 5, 1, 8, 3});
	// engine_showcase_oper(&engine);
	partition(&engine, STK_A, 8);
	// engine_visualize(&engine);
	// yassert(is_deque_sorted(&engine), "deque is not sorted");
	del_engine(&engine);
	return (0);
}
