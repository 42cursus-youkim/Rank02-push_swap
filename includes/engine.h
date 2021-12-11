/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:28 by youkim            #+#    #+#             */
/*   Updated: 2021/12/11 18:30:55 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "libft.h"
typedef struct s_engine
{
	t_deque	*a;
	t_deque	*b;
	t_deque	*hist;
}	t_engine;

//	@func
/*
** < func_engine.c > */

void	engine_showcase_oper(t_engine *engine);
void	engine_visualize(t_engine *engine);
/*
** < init_engine.c > */

void	init_engine(t_engine *engine, int size, int *nums);
void	del_engine(t_engine *engine);
//	@end
#endif