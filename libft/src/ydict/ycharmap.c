/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ycharmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:38:34 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 11:14:54 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	creates a simple dict of size 256, indexed with char.
	usage: new_ycharmap((char []){'a', 'b', '\0'}, (char *[]){"A", "B", NULL})
*/
char	**new_ycharmap(char symbols[], char *values[])
{
	char	**map;
	int		i;

	map = ycalloc(256, sizeof(char *));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < 256)
		map[i] = NULL;
	i = -1;
	while (symbols[++i] && values[i])
		map[(unsigned char)symbols[i]] = new_ystr(values[i]);
	return (map);
}

void	del_ycharmap(void *map)
{
	int	i;

	i = -1;
	while (++i < 256)
		if (((char **)map)[i])
			del_ystr(((char **)map)[i]);
	free(map);
}

void	ycharmap_visualize(char **map)
{
	int	i;

	i = -1;
	printf("%s ID |%-6s%s\n",
		UMAG, "VALUE", END);
	while (++i < 256)
		if (map[i])
			printf("%s%3d%s%c|%s%-6s%s\n",
				HBLU, i, BHMAG, i, HGRN, map[i], END);
}
