/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:02:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/14 21:08:47 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_H
# define QUICKSORT_H

typedef enum e_loc
{
	up,
	mid,
	down,
}	t_loc;

typedef enum e_sortres
{
	rots = 0,
	pushes = 1,
}	t_sortres;

//@func
/*
** < number_utils.c > */

int		head_num(t_engine *engine, t_flag from);
int		tail_num(t_engine *engine, t_flag from);
void	set_head_nums(t_engine *e, t_flag from, int size, int arrs[]);
/*
** < quicksort.c > */

void	quicksort(t_engine *e, t_flag from, int size);
/*
** < smolsort.c > */

void	smolsort(t_engine *e, t_flag from);
#endif