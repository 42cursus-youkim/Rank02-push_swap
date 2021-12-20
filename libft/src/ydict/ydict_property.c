/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ydict_property.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:46:37 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 09:49:36 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	visualize list. only works when EVERY values are string.
void	ydict_visualize(t_dict *dict)
{
	int			id;
	t_ditem		*item;

	id = 0;
	printf("%sID |%-8s|%-6s(%d/%d)%s\n",
		UMAG, "KEY", "VALUE", dict->size, dict->capacity, END);
	while (id < dict->capacity)
	{
		item = dict->items[id];
		if (item && item->key)
			printf("%s%2d |%-8s|%s%s\n",
				HGRN, id++, item->key, item->value, END);
		else
			printf("%2d |%8s|\n", id++, "");
	}
}
