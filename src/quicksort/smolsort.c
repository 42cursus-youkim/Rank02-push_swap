/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smolsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:46:02 by youkim            #+#    #+#             */
/*   Updated: 2021/12/14 19:52:49 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smolsort_3(t_engine *e, t_flag from)
{
	int	n[3];

	if (get_deque(e, from)->size != 3)
		yerror("sort_3", "size != 3!!! why even call????");
	set_head_nums(e, from, 3, n);
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
