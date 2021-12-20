/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yhash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:40:39 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 12:53:21 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	FNV-1a hash algorithm
uint64_t	yhash_fnv1a(const char *key)
{
	int			i;
	uint64_t	hash;

	i = -1;
	hash = FNV_OFFSET;
	while (key[++i])
	{
		hash ^= key[i];
		hash *= FNV_PRIME;
	}
	return (hash);
}
