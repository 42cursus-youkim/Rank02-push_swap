/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:04:11 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 17:10:32 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	returns true if value matches any of the values in the list
	usage: yany(value, 4, (int []){1, 2, 3, 4})
*/
bool	yanyi(int value, int size, const int arr[])
{
	if (size <= 0)
		yerror("yany", "i must be greater than 0");
	while (arr[--size])
		if (value == arr[size])
			return (true);
	return (false);
}

//	numstr is supposed to be "-123" or "123"
bool	is_int_overflow(char *numstr)
{
	int	i;
	int	n;

	yatoi(numstr, &n);
	i = ystrchri(numstr, '-');
	if (i >= 0 && n > 0)
		return (true);
	else if (i == ERR && n < 0)
		return (true);
	return (false);
}
