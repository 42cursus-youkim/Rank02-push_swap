/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ysplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:16:46 by youkim            #+#    #+#             */
/*   Updated: 2021/12/07 17:39:28 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char delim)
{
	int		i;
	int		count;
	bool	prev_delim;

	i = -1;
	count = 1;
	prev_delim = false;
	while (s[++i])
	{
		if (s[i] == delim)
			prev_delim = true;
		else if (prev_delim)
		{
			prev_delim = false;
			count++;
		}
	}
	return (count);
}

static int	wordlen(int i, char const *s, char const c)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	**write_words(char **strarr, int words, char const *s, char c)
{
	int	i;
	int	j;
	int	word_idx;

	i = 0;
	word_idx = -1;
	while (++word_idx < words)
	{
		while (s[i] == c)
			i++;
		strarr[word_idx] = new_ystrm(wordlen(i, s, c));
		if (!strarr[word_idx])
		{
			del_ystrs(strarr);
			free(strarr);
			return (NULL);
		}
		j = 0;
		while (s[i] && s[i] != c)
			strarr[word_idx][j++] = s[i++];
	}
	return (strarr);
}

char	**new_ysplit(char const *s, char c)
{
	char	**strarr;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	strarr = ymalloc((words + 1) * sizeof(char *));
	strarr[words] = NULL;
	return (write_words(strarr, words, s, c));
}
