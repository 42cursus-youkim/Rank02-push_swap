/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ybinary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:27:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 17:37:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	returns length of digits needed to represent bit
int	ybitlen(unsigned int bit)
{
	int	i;

	i = 0;
	while (bit > 0 && ++i)
		bit >>= 1;
	return (i);
}

//	memory safe printout of binary
void	ywriteitob(unsigned int bit)
{
	del_ywrites(1, 3, (char *[5]){HMAG, new_yitob(bit), "\n", NULL, END});
}

char	*new_yitob(unsigned int bit)
{
	char	*str;
	int		i;
	int		bitlen;

	i = -1;
	bitlen = ybitlen(bit);
	str = new_ystrm(bitlen);
	while (++i < bitlen)
		str[i] = "01"[(bit & 1 << (bitlen - i - 1)) != 0];
	return (str);
}
