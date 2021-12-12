/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 20:58:48 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_engine	engine;

	init_engine(&engine, 8, (int []){4, 7, 2, 6, 5, 1, 8, 3});
	// operl(&engine, SA);
	// oper(&engine, PB);
	// engine_showcase_oper(&engine);
	engine_visualize(&engine);
	partition(&engine, STK_A, 8);
	engine_visualize(&engine);
	// printf("%d\n", engine_solve(&engine));
	del_engine(&engine);
	return (0);
}
