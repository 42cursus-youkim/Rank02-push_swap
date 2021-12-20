/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:18:19 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 15:09:38 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_newkey_vacant(t_ditem **items_n, int id)
{
	return (!items_n[id]);
}

static void	ydict_moveprobeditem(t_ditem **items_n, int id, t_ditem *item)
{
	items_n[id] = item;
}

static void	ydict_probenew(t_ditem **items_n, int cap_n, int id, t_ditem *item)
{
	int	i;

	i = id;
	while (++i < cap_n)
		if (is_newkey_vacant(items_n, i))
			return (ydict_moveprobeditem(items_n, i, item));
	i = -1;
	while (++i < id)
		if (is_newkey_vacant(items_n, i))
			return (ydict_moveprobeditem(items_n, i, item));
	ywarn("could not move item to new array due to NO SPACE LEFT in new array");
}

static void	ydict_move_items(t_dict *dict, t_ditem **items_n, int cap_n)
{
	int		i;
	int		id;
	t_ditem	*item;

	i = 0;
	while (i < dict->capacity)
	{
		item = dict->items[i];
		if (item && item->key)
		{
			id = ydict_getid(cap_n, item->key);
			if (is_newkey_vacant(items_n, id))
				items_n[id] = item;
			else
				ydict_probenew(items_n, cap_n, id, item);
		}
		i++;
	}
	free(dict->items);
	dict->items = items_n;
}

//	creates new dictitems, and moves all items to new array with new hash ids
int	ydict_expand(t_dict *dict)
{
	int		cap_n;
	t_ditem	**items_n;

	if (is_capacity_overflow(dict))
		return (ERR);
	cap_n = dict->capacity * 2;
	items_n = new_ydictitem_arr(cap_n);
	if (!items_n)
		return (ERR);
	ydict_move_items(dict, items_n, cap_n);
	dict->capacity = cap_n;
	return (OK);
}
