/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:17:16 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 15:07:38 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_input_valid(const t_dict *dict, const char *key, const void *value)
{
	return (dict && key && value);
}

bool	is_key_vacant(const t_dict *dict, int id)
{
	return (!dict->items[id]);
}

bool	is_key_update(const t_dict *dict, int id, const char *key)
{
	return (ystrequ(dict->items[id]->key, key));
}

bool	is_dict_almostfull(const t_dict *dict)
{
	return (dict->size >= dict->capacity / 2);
}

bool	is_capacity_overflow(const t_dict *dict)
{
	return (dict->capacity * 2 < dict->capacity);
}
