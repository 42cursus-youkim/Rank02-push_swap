/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:30:14 by youkim            #+#    #+#             */
/*   Updated: 2021/12/13 10:50:18 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//	@func
/*
** < opers.c > */

t_res	oper_swap(t_engine *engine, t_flag from);
t_res	oper_push(t_engine *engine, t_flag from);
t_res	oper_rotate(t_engine *engine, t_flag from);
t_res	oper_rev_rotate(t_engine *engine, t_flag from);
/*
** < opers_util.c > */

t_deque	*get_deque(t_engine *engine, t_flag from);
void	set_deques_from_to(t_engine *e, t_deque *deqs[2], t_flag from);
t_res	opers(t_engine *engine, t_flag from, int size, t_inst insts[]);
t_res	operb(t_engine *engine, t_inst inst);
t_res	oper(t_engine *engine, t_flag from, t_inst inst);
/*
** < util_compares.c > */

bool	is_big(t_engine *e, t_flag f, int pivot[2]);
bool	is_mid(t_engine *e, t_flag f, int pivot[2]);
bool	is_smol(t_engine *e, t_flag f, int pivot[2]);
/*
** < util_numbers.c > */

int		head_num(t_engine *engine, t_flag from);
int		tail_num(t_engine *engine, t_flag from);
void	set_pivot(t_engine *e, t_flag from, int size, int pivot[2]);
void	set_sectors(int sectors[4], int size);
void	set_dequnpack(t_engine *e, t_flag from, int size, int arr[]);
/*
** < util_quicksort.c > */

void	move_node_b_to_a(t_engine *e, int pivot[2], int sectors[4]);
void	move_node_a_to_b(t_engine *e, int pivot[2], int sectors[4]);
void	move_node_initial(t_engine *e, int pivot[2], int sectors[4]);
void	rewind_sector(t_engine *e, int sectors[3], t_sortflag which[2]);
#endif