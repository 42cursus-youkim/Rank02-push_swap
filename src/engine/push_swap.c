/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 16:48:59 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_values(t_deque *deq, char *strs[])
{
	int		i;
	int		n;

	i = -1;
	while (strs[++i])
	{
		yassert(yatoi(strs[i], &n) == OK, "add_values", "invalid input!");
		ydeque_push_back(deq, new_ydequenode(n));
	}
	del_ystrarr(strs);
}

static t_deque	*get_input(const int argc, const char *argv[])
{
	int		i;
	t_deque	*deq;

	i = 0;
	deq = new_ydeque(0, NULL);
	while (++i < argc)
		add_values(deq, new_ysplit(argv[i], ' '));
	return (deq);
}

int	main(const int argc, const char *argv[])
{
	t_deque		*input;
	t_engine	engine;

	input = get_input(argc, argv);
	init_engine(&engine, input);
	quicksort(&engine);
	engine_print_opers(&engine);
	yassert(is_sort_complete(&engine), "main", "not sorted!");
	del_engine(&engine);
	return (0);
}
