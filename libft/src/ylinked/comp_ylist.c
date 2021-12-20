/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_ylist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:51:10 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 16:44:34 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ylistlen(t_list *lst)
{
	int		len;

	len = 0;
	while (lst && len++ >= 0)
		lst = lst->next;
	return (len);
}

t_list	*ylistindex(t_list *lst, int index)
{
	int		i;

	i = 0;
	while (lst && i++ < index)
		lst = lst->next;
	return (lst);
}

void	ydeque_show(t_deque *deque)
{
	int		i;
	t_dnode	*curs;
	char	*numstr;

	i = -1;
	curs = deque->head;
	ywrite(1, "deq => [");
	while (++i < deque->size)
	{
		numstr = new_yitoa(curs->num);
		ywritecolors(1, YEL, (char *[]){numstr, NULL});
		if (i != deque->size - 1)
			ywrite(1, ", ");
		del_ystr(numstr);
		curs = curs->lower;
	}
	ywrite(1, "]\n");
}
