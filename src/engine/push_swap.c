/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 10:26:16 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_engine	engine;

	init_engine(&engine, 8, (int []){4, 7, 2, 6, 5, 1, 8, 3});
	// operl(&engine, SA);
	// oper(&engine, PB);
	engine_showcase_oper(&engine);
	// engine_visualize(&engine);
	// oper_push(&engine, STK_B);
	// inst(&engine, STK_B, PUSH);
	// partition(&engine, STK_A, 8);
	// engine_visualize(&engine);
	// printf("%d\n", engine_solve(&engine));
	// yassert(is_deque_sorted(&engine), "deque is not sorted");
	del_engine(&engine);
	return (0);
}
