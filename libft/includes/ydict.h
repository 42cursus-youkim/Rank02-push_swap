/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yhashmap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:29:34 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 12:28:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YDICT_H
# define YDICT_H

# include "ytypes.h"

typedef enum e_dictconfig
{
	YDICT_INITIAL_CAPACITY = 8,
	FNV_OFFSET = 14695981039346656037UL,
	FNV_PRIME = 1099511628211UL,
}	t_dictconfig;

typedef struct s_ditem
{
	char	*key;
	void	*value;
}	t_ditem;

typedef struct s_dict
{
	int		size;
	int		capacity;
	t_ditem	**items;
	t_del_f	del_value;
}	t_dict;

//	@func
/*
** < del_ydict.c > */

void		no_free(void *data);
void		del_ydictitem(t_dict *dict, int id);
void		del_ydict(t_dict *dict);
/*
** < new_ydict.c > */

t_ditem		*new_ydictitem(const char *key, void *value);
t_ditem		**new_ydictitem_arr(int capacity);
t_dict		*new_ydict(t_del_f del_value);
t_dict		*new_ydictinits(char *key[], char *value[]);
/*
** < ycharmap.c > */

char		**new_ycharmap(char symbols[], char *values[]);
void		del_ycharmap(void *map);
void		ycharmap_visualize(char **map);
/*
** < ydict_expand.c > */

int			ydict_expand(t_dict *dict);
/*
** < ydict_get.c > */

int			ydict_getid(int capacity, char *key);
void		*ydict_get(t_dict *dict, char *key);
char		*ydict_getd(t_dict *dict, char *key, char *defaultv);
/*
** < ydict_property.c > */

void		ydict_visualize(t_dict *dict);
/*
** < ydict_set.c > */

void		ydict_set(t_dict *dict, char *key, void *value);
/*
** < ydict_status.c > */

bool		is_input_valid(const t_dict *dict, const char *key,
				const void *value);
bool		is_key_vacant(const t_dict *dict, int id);
bool		is_key_update(const t_dict *dict, int id, const char *key);
bool		is_dict_almostfull(const t_dict *dict);
bool		is_capacity_overflow(const t_dict *dict);
/*
** < yhash.c > */

uint64_t	yhash_fnv1a(const char *key);
#endif