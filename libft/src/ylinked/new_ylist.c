/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:45:54 by youkim            #+#    #+#             */
/*   Updated: 2021/12/07 17:39:22 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	returns NULL if allocation fails
t_list	*new_ylist(void *content)
{
	t_list	*lst;

	lst = ymalloc(sizeof(t_list));
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
