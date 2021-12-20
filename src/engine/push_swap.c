/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 09:44:17 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_input(const int argc, const char *argv[])
{
	if (argc || argv)
		return ;
	// check_duplicate(argc, argv);
}

int	main(const int argc, const char *argv[])
{
	t_engine	engine;

	check_input(argc, argv);
	init_engine(&engine, get_input(argc, argv));
	quicksort(&engine);
	yassert(is_sort_complete(&engine), "not sorted!");
	engine_print_opers(&engine);
	del_engine(&engine);
	return (0);
}
