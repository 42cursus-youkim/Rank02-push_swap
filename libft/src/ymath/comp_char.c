/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:45:55 by youkim            #+#    #+#             */
/*   Updated: 2021/12/14 21:03:32 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	check if given character has given flag, or-wise
	[usage] LOWER, UPPER, ALPHA, DIGIT, ALNUM, ASCII
	is_char('a', LOWER) -> true
	is_char('A', LOWER | UPPER) -> true
	is_char('A', ALPHA) -> true
*/
bool	is_char(char c, t_cflag_b flag)
{
	int				i;
	bool			result;
	const t_cflag_b	types[4] = {LOWER, UPPER, DIGIT, ASCII};
	const char		comp[4][2] = {
		{'a', 'z'}, {'A', 'Z'}, {'0', '9'}, {0, 127}};

	i = -1;
	result = false;
	while (++i < 4)
		if (flag & types[i])
			result |= comp[i][0] <= c && c <= comp[i][1];
	return (result);
}
