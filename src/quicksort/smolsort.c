/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smolsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:46:02 by youkim            #+#    #+#             */
/*   Updated: 2021/12/15 20:21:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smolsort_2(t_engine *e, t_flag from)
{
	int	n[2];

	set_dequnpack(e, from, 2, n);
	if (n[up] > n[mid])
		oper(e, from, SWAP);
}

static void	smolsort_3(t_engine *e, t_flag from)
{
	int	n[3];

	set_dequnpack(e, from, 3, n);
	if (n[mid] < n[up] && n[up] < n[down])
		oper(e, from, SWAP);
	else if (n[up] < n[down] && n[down] < n[mid])
		opers(e, from, 2, (t_inst []){RROT, SWAP});
	else if (n[mid] < n[down] && n[down] < n[up])
		oper(e, from, ROT);
	else if (n[down] < n[up] && n[up] < n[mid])
		oper(e, from, RROT);
	else if (n[down] < n[mid] && n[mid] < n[up])
		opers(e, from, 2, (t_inst []){ROT, SWAP});
}

//	for smol size <= 3
void	smolsort(t_engine *e, t_flag from)
{
	const int	size = get_deque(e, from)->size;

	if (size <= 1 || is_sorted(e, from))
		return ;
	if (size > 3)
		yerror("smolsort", "size > 3!!! why even call????");
	else if (size == 3)
		smolsort_3(e, from);
	else if (size == 2)
		smolsort_2(e, from);
}
