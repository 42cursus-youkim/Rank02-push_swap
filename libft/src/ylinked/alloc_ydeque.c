/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_ydeque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:47:10 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 15:29:57 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dnode	*new_ydequenode(int num)
{
	t_dnode	*node;

	node = ymalloc(sizeof(t_dnode));
	node->num = num;
	node->lower = NULL;
	node->upper = NULL;
	return (node);
}

/*	create new double-linked list with head and tail.
	locating beginning and end of list is done by size,
	since they're endless loop.
	first argument goes to head(top), last to tail(bottom)!
*/
t_deque	*new_ydeque(int size, int nums[])
{
	t_deque	*deque;

	deque = ymalloc(sizeof(t_deque));
	deque->head = NULL;
	deque->tail = NULL;
	deque->size = 0;
	while (--size >= 0)
		ydeque_push(deque, new_ydequenode(nums[size]));
	return (deque);
}

void	del_ydeque(t_deque *deque)
{
	t_dnode	*curs;
	t_dnode	*temp;

	if (!deque)
		yerror("del_ydeque", "deque is NULL");
	curs = deque->head;
	while (--deque->size >= 0)
	{
		temp = curs;
		curs = curs->lower;
		free(temp);
	}
	free(deque);
}
