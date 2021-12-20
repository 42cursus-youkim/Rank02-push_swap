/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ystr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:54:05 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 16:25:34 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	same as free, but can be used for ff. please ONLY put char * here.
void	del_ystr(void *str)
{
	free((char *)str);
}

//	usage: del_ystr((char *[]){str, ..., NULL});
void	del_ystrs(char *strs[])
{
	int	i;

	yassert(strs, "del_ystrs", "strs is NULL");
	i = -1;
	while (strs[++i])
		del_ystr(strs[i]);
}

void	del_ystrarr(char *strarr[])
{
	yassert(strarr, "del_ystrarr", "strarr is NULL");
	del_ystrs(strarr);
	free(strarr);
}
