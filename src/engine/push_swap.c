/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 17:19:40 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_values(t_deque *deq, char *strs[])
{
	t_vec	vec;
	int		n;

	vec_set(&vec, (t_vec){-1, -1});
	while (strs[++vec.x])
	{
		vec.y = -1;
		while (++vec.y < ystrlen(strs[vec.x]))
			yassert(
				is_char(strs[vec.x][vec.y], DIGIT)
				|| ystrchri("-+ ", strs[vec.x][vec.y]) >= 0,
				"add_values", "invalid char");
		printf("%s\n", strs[vec.x]);
		yassert(is_int_overflow(strs[vec.x]) == false,
			"add_values", "int overflow!");
		yassert(yatoi(strs[vec.x], &n) == OK, "add_values", "invalid input!");
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
