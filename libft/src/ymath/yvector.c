/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yvector.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:49:28 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 16:13:33 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vec_set(t_vec *v1, t_vec v2)
{
	v1->x = v2.x;
	v1->y = v2.y;
}

void	vec_update(t_vec *v1, t_vec v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
}
