/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 20:02:08 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_engine	engine;

	init_engine(&engine, 2, (int []){2, 1, 3, 4, 5});
	// operl(&engine, SA);
	// oper(&engine, PB);
	// engine_showcase_oper(&engine);
	// engine_visualize(&engine);
	printf("%d\n", engine_solve(&engine));
	del_engine(&engine);
	return (0);
}
