/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:56:56 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 10:04:43 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ymax(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ymin(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ymedian(int size, int arr[])
{
	yqsort(size, arr);
	return (arr[size / 2]);
}

//	returns how many digits the number has
int	ydigitlen(long long n)
{
	int	digit;

	digit = 0;
	if (n < 0)
	{
		n /= -10;
		digit++;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}
