/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ydict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:45:52 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 10:00:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	does nothing, for placeholder destructor
void	no_free(void *data)
{
	if (!data || data)
		return ;
}

void	del_ydictitem(t_dict *dict, int id)
{
	t_ditem	*item;

	item = dict->items[id];
	del_ystr(item->key);
	dict->del_value(item->value);
	free(item);
}

//	uses internal function pointer as destructor.
void	del_ydict(t_dict *dict)
{
	int	id;

	if (!dict)
		yerror("del_ydict", "tried to free nonexsistant ydict struct");
	id = -1;
	while (++id < dict->capacity)
		if (dict->items[id])
			del_ydictitem(dict, id);
	free(dict->items);
	free(dict);
}
