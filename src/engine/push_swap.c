/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 20:01:21 by youkim           ###   ########.fr       */
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
	const int	size = engine->a->size;

	if (size <= 3)
		return ((void)smolsort(engine, STK_A, size));
	partition_initial(engine);
}

int	main(const int argc, const char *argv[])
{
	t_engine	engine;

	check_input(argc, argv);
	init_engine(&engine, get_input(argc, argv));
	solve(&engine);
	yassert(is_sorted(&engine, STK_A) && engine.b->size == 0, "not sorted!");
	engine_print_opers(&engine);
	del_engine(&engine);
	return (0);
}
