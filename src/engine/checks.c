/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:55:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/15 19:26:03 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(const int argc, const char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ystrequ(argv[i], argv[j]))
				yerror("check_duplicate", "duplicate values");
		}
	}
}

t_deque	*get_input(const int argc, const char *argv[])
{
	int		i;
	int		n;
	t_dnode	*node;
	t_deque	*deque;

	i = argc;
	deque = new_ydeque(0, NULL);
	while (--i > 0)
	{
		yatoi(argv[i], &n);
		node = new_ydequenode(n);
		ydeque_push(deque, node);
	}
	// ydeque_show(deque);
	return (deque);
}
