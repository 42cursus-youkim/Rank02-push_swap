/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yalloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:50:57 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 10:00:18 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ymemset(void *b, int c, int len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (--len > 0)
		ptr[len] = c;
	return (b);
}

void	ybzero(void *s, int n)
{
	ymemset(s, 0, n);
}

void	*ycalloc(int count, int size)
{
	void	*ptr;

	ptr = ymalloc(size * count);
	ybzero(ptr, size * count);
	return (ptr);
}

//	identical to malloc but exits program with error if allocation fails
void	*ymalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		yerror("ymalloc", "failed to allocate memory!!");
	return (ptr);
}
