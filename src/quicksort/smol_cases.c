/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:46:02 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 21:01:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_engine *e, t_flag from)
{
	t_dnode	*curs[3];

	if (get_deque(e, from)->size != 3)
		yerror("sort_3", "size != 3!!! why even call????");
	curs[0] = get_deque(e, from)->head;
	curs[1] = curs[0]->lower;
	curs[2] = curs[1]->lower;
    // u, m, d = stacks.a
    // if u < m < d:
    //     stacks(RA, SA)
    // elif d < u < m:
    //     stacks(RRA, SA)
    // elif m < d < u:
    //     stacks(SA)
    // elif u < d < m:
    //     stacks(RRA)
    // elif m < u < d:
    //     stacks(RA)
}