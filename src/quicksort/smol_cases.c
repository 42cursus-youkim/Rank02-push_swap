/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:46:02 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 21:25:13 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_3(t_dnode *head, int *pup, int *pmid, int *pdown)
{
	*pup = head->num;
	*pmid = head->lower->num;
	*pdown = head->lower->lower->num;
}

void	sort_3(t_engine *e, t_flag from)
{
	int	up;
	int	mid;
	int	down;

	if (get_deque(e, from)->size != 3)
		yerror("sort_3", "size != 3!!! why even call????");
	set_3(get_deque(e, from)->head, &up, &mid, &down);
	if (mid < up && up < down)
		oper(e, from, SWAP);
	else if (up < down && down < mid)
		opers(e, from, 2, (t_inst []){RROT, SWAP});
	else if (mid < down && down < up)
		oper(e, from, ROT);
	else if (down < up && up < mid)
		oper(e, from, RROT);
	else if (down < mid && mid < up)
		opers(e, from, 2, (t_inst []){ROT, SWAP});
}
