/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:27:13 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 15:01:22 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	wrapper for hash that returns index got from hash
int	ydict_getid(int capacity, char *key)
{
	return (yhash_fnv1a(key) % (uint64_t)capacity);
}

static bool	does_itemmatch(t_ditem *item, char *key)
{
	return (item && item->key && ystrequ(item->key, key));
}

//	finds value by key, return NULL is not found
void	*ydict_get(t_dict *dict, char *key)
{
	int		i;
	int		id;

	id = ydict_getid(dict->capacity, key);
	i = id - 1;
	while (++i < dict->capacity)
		if (does_itemmatch(dict->items[i], key))
			return (dict->items[i]->value);
	i = -1;
	while (++i < id)
		if (does_itemmatch(dict->items[i], key))
			return (dict->items[i]->value);
	return (NULL);
}

//	finds value by key, return default value if not found
char	*ydict_getd(t_dict *dict, char *key, char *defaultv)
{
	char	*value;

	value = ydict_get(dict, key);
	if (!value)
		return (defaultv);
	return (value);
}
