/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:02:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 16:59:35 by youkim           ###   ########.fr       */
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
	COUNTER = 3,
}	t_sortres;

//@func
/*
** < number_utils.c > */

int		head_num(t_engine *engine, t_flag from);
int		tail_num(t_engine *engine, t_flag from);
void	set_pivot(t_engine *e, t_flag from, int size, int pivot[2]);
void	set_dequnpack(t_engine *e, t_flag from, int size, int arr[]);
bool	is_sorted(t_engine *engine, t_flag from);
/*
** < quicksort.c > */

void	partition_mid(t_engine *e, int size);
void	partition_initial(t_engine *e, int psize[4]);
void	partition_big(t_engine *e, t_flag from, int size);
/*
** < quicksort_utils.c > */

bool	is_big(t_engine *e, t_flag f, int pivot[2]);
bool	is_mid(t_engine *e, t_flag f, int pivot[2]);
bool	is_mid_after_big(t_engine *e, t_flag f, int pivot[2]);
void	do_mid_and_big(t_engine *e, t_flag f, int psize[4]);
void	move_node(t_engine *e, t_flag f, int pivot[2], int psize[4]);
/*
** < smolsort.c > */

void	smolsort(t_engine *e, t_flag from, int given_size);
#endif