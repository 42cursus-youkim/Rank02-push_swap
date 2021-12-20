/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ystrjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:37:28 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 17:54:31 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	total length of all strings in arr
static int	total_length(char *strs[])
{
	int	i;
	int	total;

	i = -1;
	total = 0;
	while (strs[++i])
		total += ystrlen(strs[i]);
	return (total);
}

/*	merges multiple strings into one.
	usage: (char *[]){"a", "b", NULL}
	since strs are NOT modified, if you're using exsisting strings,
	you should free them after calling this function.
*/
char	*new_ystrjoin(char *strs[])
{
	char	*res;
	int		i;
	int		idx_res;
	int		idx_strs;

	idx_res = 0;
	idx_strs = -1;
	res = new_ystre(total_length(strs));
	if (!res)
		return (NULL);
	while (strs[++idx_strs])
	{
		i = -1;
		while (strs[idx_strs][++i])
			res[idx_res + i] = strs[idx_strs][i];
		idx_res += i;
	}
	return (res);
}
