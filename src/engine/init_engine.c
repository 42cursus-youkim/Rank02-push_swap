/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:31:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/11 15:54:40 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	init_engine(t_engine *engine)
{
	engine->a = new_ydeque(0, NULL);
	engine->b = new_ydeque(0, NULL);
	engine->hist = new_ydeque(0, NULL);
}

void	del_engine(t_engine *engine)
{
	del_ydeque(engine->a);
	del_ydeque(engine->b);
	del_ydeque(engine->hist);
}
