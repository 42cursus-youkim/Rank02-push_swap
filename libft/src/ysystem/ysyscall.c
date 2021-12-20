/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysyscall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:40:48 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 16:44:25 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	just an wrapper for write() but without annoying length parameter
int	ywrite(int fd, char *str)
{
	return (write(fd, str, ystrlen(str)));
}

/*	write but with array and colors
	usage: ywritecolors(1, YEL, (char *[2]){"hello", NULL});
*/
int	ywritecolors(int fd, char *color, char *strs[])
{
	int	i;
	int	result;

	i = -1;
	result = ywrite(fd, color);
	while (strs[++i])
		result += ywrite(fd, strs[i]);
	result += ywrite(fd, END);
	return (result);
}

/*	prints out inputs but attempts to free odd indexed strings.
	it wouldn't if the string in question is NULL,
	hence the range for termination. returns length of chars printed.
	usage: del_ywritejoin(1, 4, (char *[]){"str1" newstr() "str2" newstr2()})
*/
int	del_ywrites(int fd, int size, char *strs[])
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	while (++i < size)
	{
		if (strs[i])
			result += ywrite(fd, strs[i]);
		if (strs[i] && i % 2 == 1)
			del_ystr(strs[i]);
	}
	return (result);
}

/*	similar to read but NULL-terminates the string. returns sizes read.
	string size should be at least 1 bigger than the buffer_size.
*/
int	yread(int fd, char *buf, int buffer_size)
{
	int	len;

	len = read(fd, buf, buffer_size);
	buf[len] = '\0';
	return (len);
}
