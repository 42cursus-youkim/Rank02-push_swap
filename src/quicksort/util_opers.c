/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_opers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:09:50 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 17:12:32 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_mid_big(t_engine *e, t_flag f, int psize[4])
{
	oper(e, f, PUSH);
	operb(e, ROT);
	psize[MID]++;
	psize[BIG]++;
	psize[COUNTER]--;
}

void	send_big_down(t_engine *e, t_flag f, int psize[4])
{
	oper(e, f, ROT);
	psize[BIG]++;
}

void	send_mid_down(t_engine *e, t_flag f, int psize[4])
{
	oper(e, f, PUSH);
	oper(e, !f, ROT);
	psize[MID]++;
}

void	send_smol_up(t_engine *e, t_flag f, int psize[4])
{
	oper(e, f, PUSH);
	psize[SMOL]++;
}