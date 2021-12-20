/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:02:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 20:30:03 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_H
# define QUICKSORT_H

typedef enum e_sortflag
{
	ROTS = 0,
	PUSHES = 1,
	LO = 0,
	HI = 1,
	UP = 0,
	MID = 1,
	DOWN = 2,
	BIG = 0,
	SMOL = 2,
	COUNT = 3,
}	t_sortflag;

//@func
/*
** < quicksort.c > */

void	quicksort(t_engine *engine);
void	a_to_b(t_engine *e, int size);
void	b_to_a(t_engine *e, int size);
/*
** < smolsort.c > */

void	smolsort(t_engine *e, t_flag from, int given_size);
#endif