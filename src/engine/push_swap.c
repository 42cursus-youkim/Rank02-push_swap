/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 11:41:25 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(const int argc, const char *argv[])
{
	t_engine	engine;

	init_engine(&engine, argc, argv);
	// check_input(argc, argv);
	// init_engine(&engine, 8, (int []){4, 7, 2, 6, 5, 1, 8, 3});
	// engine_showcase_oper(&engine);
	// partition(&engine, STK_A, 8);
	// engine_visualize(&engine);
	// yassert(is_deque_sorted(&engine), "deque is not sorted");
	del_engine(&engine);
	return (0);
}
