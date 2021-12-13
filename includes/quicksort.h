/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:02:58 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 21:27:22 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_H
# define QUICKSORT_H

// typedef enum e_namedeqends
// {
// 	HI = 0,
// 	MD = 1,
// 	LO = 2,
// }	t_namedeqends;
;
//@func
/*
** < quicksort.c > */

void	partition(t_engine *e, t_flag from, int size);
/*
** < quicksort_utils.c > */

int		head_num(t_engine *engine, t_flag from);
int		tail_num(t_engine *engine, t_flag from);
/*
** < smolsort.c > */

void	smolsort_3(t_engine *e, t_flag from);
#endif