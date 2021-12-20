/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ydeque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:00:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 15:24:57 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	push new node to uppermost
void	ydeque_push(t_deque *deque, t_dnode *new)
{
	if (new == NULL)
		yerror("ydeque_push", "node trying to push does not exsist");
	if (deque->head == NULL)
	{
		deque->head = new;
		deque->tail = new;
	}
	else
	{
		new->upper = deque->tail;
		new->lower = deque->head;
		deque->head->upper = new;
		deque->tail->lower = new;
		deque->head = new;
	}
	deque->size++;
}

void	ydeque_push_back(t_deque *deque, t_dnode *new)
{
	if (new == NULL)
		yerror("ydeque_push_back", "node trying to push does not exsist");
	if (deque->head == NULL)
	{
		deque->head = new;
		deque->tail = new;
	}
	else
	{
		new->upper = deque->tail;
		new->lower = deque->head;
		deque->head->upper = new;
		deque->tail->lower = new;
		deque->tail = new;
	}
	deque->size++;
}

//	pop uppermost node, returns pointer to it
t_dnode	*ydeque_pop(t_deque *deque)
{
	t_dnode	*curs;

	if (deque->size == 0)
		yerror("ydeque_pop", "deque is empty");
	curs = deque->head;
	if (deque->size == 1)
	{
		deque->head = NULL;
		deque->tail = NULL;
	}
	else
	{
		deque->head = deque->head->lower;
		deque->head->upper = deque->tail;
		deque->tail->lower = deque->head;
	}
	curs->lower = NULL;
	curs->upper = NULL;
	deque->size--;
	return (curs);
}

t_dnode	*ydeque_pop_back(t_deque *deque)
{
	t_dnode	*curs;

	if (deque->size == 0)
		yerror("ydeque_pop_back", "deque is empty");
	curs = deque->tail;
	if (deque->size == 1)
	{
		deque->head = NULL;
		deque->tail = NULL;
	}
	else
	{
		deque->tail = deque->tail->upper;
		deque->head->upper = deque->tail;
		deque->tail->lower = deque->head;
	}
	curs->upper = NULL;
	curs->lower = NULL;
	deque->size--;
	return (curs);
}
