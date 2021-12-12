/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:44:15 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 14:19:07 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_engine	engine;

	init_engine(&engine, 3, (int []){1, 2, 3, 4, 5});
	oper(&engine, PB);
	engine_showcase_oper(&engine);
	// engine_visualize(&engine);
	del_engine(&engine);
	return (0);
}
