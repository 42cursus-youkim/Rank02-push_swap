/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 17:32:57 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(const int argc, const char *argv[])
{
	t_deque		*input;
	t_engine	engine;

	input = check_and_get_input(argc, argv);
	init_engine(&engine, input);
	quicksort(&engine);
	engine_print_opers(&engine);
	yassert(is_sort_complete(&engine), "main", "not sorted!");
	del_engine(&engine);
	return (0);
}
