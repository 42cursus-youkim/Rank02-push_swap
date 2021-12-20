/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylinked.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:22:56 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 15:25:49 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YLINKED_H
# define YLINKED_H

//	===== Linked List =====
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//	===== Deque =====
typedef struct s_dnode
{
	int				num;
	struct s_dnode	*upper;
	struct s_dnode	*lower;
}	t_dnode;

/*	head: uppermost
	tail: lowermost
*/
typedef struct s_deque
{
	int		size;
	t_dnode	*head;
	t_dnode	*tail;
}	t_deque;

//	@func
/*
** < alloc_ydeque.c > */

t_dnode	*new_ydequenode(int num);
t_deque	*new_ydeque(int size, int nums[]);
void	del_ydeque(t_deque *deque);
/*
** < comp_ylist.c > */

int		ylistlen(t_list *lst);
t_list	*ylistindex(t_list *lst, int index);
void	ydeque_show(t_deque *deque);
/*
** < mod_ydeque.c > */

void	ydeque_push(t_deque *deque, t_dnode *new);
void	ydeque_push_back(t_deque *deque, t_dnode *new);
t_dnode	*ydeque_pop(t_deque *deque);
t_dnode	*ydeque_pop_back(t_deque *deque);
/*
** < new_ylist.c > */

t_list	*new_ylist(void *content);
#endif