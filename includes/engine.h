/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:28 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 09:05:44 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "libft.h"

//	@func
/*
** < checks.c > */

void		check_duplicate(const int argc, const char *argv[]);
bool		is_sort_complete(t_engine *engine);
/*
** < engine.c > */

void		init_engine(t_engine *engine, t_deque *input);
void		del_engine(t_engine *engine);
void		engine_print_opers(t_engine *engine);
const char	*get_op_name(t_op op);
#endif