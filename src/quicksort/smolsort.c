/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smolsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:46:02 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 16:40:07 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smolsort_2(t_engine *e, t_flag from)
{
	int	n[2];

	set_dequnpack(e, from, 2, n);
	if (n[UP] > n[MID])
		oper(e, from, SWAP);
}

static void	smolsort_3(t_engine *e, t_flag from)
{
	int	n[3];

	set_dequnpack(e, from, 3, n);
	if (n[MID] < n[UP] && n[UP] < n[DOWN])
		oper(e, from, SWAP);
	else if (n[UP] < n[DOWN] && n[DOWN] < n[MID])
		opers(e, from, 2, (t_inst []){RROT, SWAP});
	else if (n[MID] < n[DOWN] && n[DOWN] < n[UP])
		oper(e, from, ROT);
	else if (n[DOWN] < n[UP] && n[UP] < n[MID])
		oper(e, from, RROT);
	else if (n[DOWN] < n[MID] && n[MID] < n[UP])
		opers(e, from, 2, (t_inst []){ROT, SWAP});
}

//	for smol size <= 3
void	smolsort(t_engine *e, t_flag from, int given_size)
{
	const int	size = ymin(given_size, get_deque(e, from)->size);

	if (size <= 1 || is_sorted(e, from))
		return ;
	if (size == 3)
		smolsort_3(e, from);
	else if (size == 2)
		smolsort_2(e, from);
}
