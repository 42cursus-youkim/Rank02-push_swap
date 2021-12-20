/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ydict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:23:42 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 10:31:08 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	creates a new dictonary item, with key and value
t_ditem	*new_ydictitem(const char *key, void *value)
{
	t_ditem	*item;

	item = ymalloc(sizeof(t_ditem));
	item->key = new_ystr(key);
	item->value = value;
	return (item);
}

//	creates new NULL-set array of items
t_ditem	**new_ydictitem_arr(int capacity)
{
	int		id;
	t_ditem	**items;

	items = ycalloc(capacity, sizeof(t_ditem *));
	if (!items)
		return (NULL);
	id = -1;
	while (++id < capacity)
		items[id] = NULL;
	return (items);
}

//	initializes dictionary, NULLs items, saves
static void	ydict_setup(t_dict *dict, t_del_f del_value)
{
	dict->size = 0;
	dict->capacity = YDICT_INITIAL_CAPACITY;
	dict->items = new_ydictitem_arr(dict->capacity);
	if (del_value)
		dict->del_value = del_value;
	else
		dict->del_value = no_free;
}

/*	creates an empty dict with destructor. pass NULL for constant values.
	Internal structure assumes all items are of SAME TYPE.
	(at least they could be freed with same destructor)
*/
t_dict	*new_ydict(t_del_f del_value)
{
	t_dict	*dict;

	dict = ymalloc(sizeof(t_dict));
	ydict_setup(dict, del_value);
	if (dict->items)
		return (dict);
	else
	{
		free(dict->items);
		free(dict);
		return (NULL);
	}
}

//	creates a new dict with allocated string k,v
t_dict	*new_ydictinits(char *key[], char *value[])
{
	int		i;
	t_dict	*dict;

	dict = new_ydict(NULL);
	if (!dict)
		return (NULL);
	i = -1;
	while (key[++i] && value[i])
		ydict_set(dict, key[i], value[i]);
	return (dict);
}
