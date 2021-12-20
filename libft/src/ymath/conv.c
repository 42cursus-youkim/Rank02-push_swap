/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:46:48 by youkim            #+#    #+#             */
/*   Updated: 2021/12/15 16:40:52 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	yswap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//	convert input to one of -1, 0, 1
int	normalized(int n)
{
	if (n > 0)
		return (1);
	else if (n < 0)
		return (-1);
	else
		return (0);
}

//	returns pseudo-random number
int	yrand(void)
{
	static unsigned int	r = 2151901553;

	r = (r * 1103515245 + 30029) % 479001599;
	return (r);
}

char	*new_yitoa(int n)
{
	char	*str;
	int		digit;
	long	num;

	num = n;
	if (num == 0)
		return (new_ystr("0"));
	digit = ydigitlen(num);
	if (num < 0)
		digit++;
	str = new_ystrm(digit);
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[--digit] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}

//	pass reference to n to convert str to int
t_res	yatoi(const char *str, int *n)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	if (!str)
		return (ERR);
	while (ystrchri("\t\n\v\f\r ", str[i]) >= 0)
		i++;
	if (ystrchri("-+", str[i]) >= 0)
		if (str[i++] == '-')
			sign = -1;
	while (is_char(str[i], DIGIT))
		num = num * 10 + (str[i++] - '0');
	*n = sign * num;
	return (OK);
}
