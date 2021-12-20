/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ystr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:42:56 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 11:53:02 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	returns length of strings appended.
int	ystrcpy(char *dst, const char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (ystrlen(src));
}

/*	looks like strjoin but is memory safe, by replacing the original string
	returns: length of joined string, usage: ystr_append(&str, STRING)
*/
int	ystr_append(char **pstr, char *src)
{
	const int	org_len = ystrlen(*pstr);
	const int	src_len = ystrlen(src);
	const int	new_len = org_len + src_len;
	char		*new;

	new = new_ystrm(new_len);
	ystrcpy(new, *pstr);
	ystrcpy(new + org_len, src);
	del_ystr(*pstr);
	*pstr = new;
	return (new_len);
}

/*	colorize given string. memory safe!
	(frees given string then reallocates with colorized one)
	usage: ystr_color(&str, RED)
*/
void	ystr_color(char **pstr, char *color)
{
	char	*new;

	new = new_ystrjoin((char *[]){color, *pstr, END, 0});
	free(*pstr);
	*pstr = new;
}

//	replace given NEW string with OLD string. memory safe!
void	ystr_replace(char **pstr, char *new_str)
{
	char	*new;

	new = new_str;
	del_ystr(*pstr);
	*pstr = new;
}

//	new str from sliced range.
char	*new_yslice(const char *str, int start, int end)
{
	int		i;
	char	*new_str;

	if (start < 0 || end < 0 || start > end || end > ystrlen(str))
		return (NULL);
	i = end - start;
	new_str = new_ystrm(i);
	if (!new_str)
		return (NULL);
	while (i-- > 0)
		new_str[i] = str[start + i];
	return (new_str);
}
