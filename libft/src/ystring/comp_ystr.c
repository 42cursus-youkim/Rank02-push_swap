/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_ystr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:20:55 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 11:30:14 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	length of a string. null termination is not counted.
int	ystrlen(const char *str)
{
	int	i;

	if (!str)
		return (ERR);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

//	compare two null-terminated strings. returns non-zero if they differ
int	ystrcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

//	returns true if two strings are same
bool	ystrequ(const char *s1, const char *s2)
{
	return (ystrcmp(s1, s2) == 0);
}

//	returns index of first char occurence in a string. returns -1 if not found
int	ystrchri(const char *str, const char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}
