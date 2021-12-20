/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:27:21 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 10:00:13 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#undef YDICT_INITIAL_CAPACITY
#define YDICT_INITIAL_CAPACITY 16

//	insert new item at empty index of dictionary
static void	ydict_insert(t_dict *dict, int id, char *key, void *value)
{
	t_ditem	*item;

	item = new_ydictitem(key, value);
	dict->items[id] = item;
	dict->size++;
}

//	replace the value of an existing key
static void	ydict_update(t_dict *dict, int id, void *value)
{
	dict->del_value(dict->items[id]->value);
	dict->items[id]->value = value;
}

//	probe around empty index to insert new item
static void	ydict_probe(t_dict *dict, int id, char *key, void *value)
{
	int	i;

	i = id;
	while (++i < dict->capacity)
		if (is_key_vacant(dict, i))
			return (ydict_insert(dict, i, key, value));
	i = 0;
	while (i < id)
		if (is_key_vacant(dict, i++))
			return (ydict_insert(dict, --i, key, value));
	ywarn("dict is full, probe failed");
}

/*	all values provided are MOVED and NOT COPIED!
	insert NULL for destructor if you wish to use constants for values
	key vacant: inserts new item
	key same  : replaces value
	key diff  : probe for empty index
*/
void	ydict_set(t_dict *dict, char *key, void *value)
{
	int	id;

	if (!is_input_valid(dict, key, value))
		yerror("ydict_set", "invalid input!");
	if (is_dict_almostfull(dict))
		if (ydict_expand(dict) == ERR)
			return ;
	id = ydict_getid(dict->capacity, key);
	if (is_key_vacant(dict, id))
		ydict_insert(dict, id, key, value);
	else if (is_key_update(dict, id, key))
		ydict_update(dict, id, value);
	else
		ydict_probe(dict, id, key, value);
}
