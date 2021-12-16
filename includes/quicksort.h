/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:02:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/16 12:45:37 by youkim           ###   ########.fr       */
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
}	t_sortres;

//@func
/*
** < number_utils.c > */

int		head_num(t_engine *engine, t_flag from);
int		tail_num(t_engine *engine, t_flag from);
void	set_pivot(t_engine *e, t_flag from, int size, int pivot[2]);
int		get_pivot(t_engine *e, t_flag from, int size);
void	set_dequnpack(t_engine *e, t_flag from, int size, int arr[]);
/*
** < quicksort.c > */

void	partition_to_3(t_engine *e, int size, t_flag from, int pivot[2]);
/*
** < quicksort_dprec.c > */

void	quicksort(t_engine *e, t_flag from, int size);
/*
** < quicksort_utils.c > */

bool	is_sorted(t_engine *engine, t_flag from);
void	reset_sortcounter(t_sortres result[2]);
void	send_to_other(t_engine *e, t_flag from, t_sortres result[2]);
void	roll_down(t_engine *e, t_flag from, t_sortres result[2]);
void	roll_back_up(t_engine *e, t_flag from, int rots);
/*
** < smolsort.c > */

void	smolsort(t_engine *e, t_flag from);
#endif