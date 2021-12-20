/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ymath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:58:39 by youkim            #+#    #+#             */
/*   Updated: 2021/12/15 11:02:12 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YMATH_H
# define YMATH_H

# include "ytypes.h"

typedef enum e_ctflag_b
{
	LOWER = 0b0001,
	UPPER = 0b0010,
	ALPHA = 0b0011,
	DIGIT = 0b0100,
	ALNUM = 0b0111,
	ASCII = 0b1000,
}	t_cflag_b;

//	number container
typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

//	@func
/*
** < comp_char.c > */

bool	is_char(char c, t_cflag_b flag);
/*
** < comp_num.c > */

int		ymax(int a, int b);
int		ymin(int a, int b);
int		ymedian(int size, int arr[]);
int		ydigitlen(long long n);
/*
** < comp_val.c > */

bool	yanyi(int value, int size, const int arr[]);
bool	is_int_overflow(char *numstr);
/*
** < conv.c > */

void	yswap(int *a, int *b);
int		normalized(int n);
int		yrand(void);
char	*new_yitoa(int n);
t_res	yatoi(const char *str, int *n);
/*
** < ybinary.c > */

int		ybitlen(unsigned int bit);
void	ywriteitob(unsigned int bit);
char	*new_yitob(unsigned int bit);
/*
** < yqsort.c > */

void	yqsort(int size, int arr[]);
/*
** < yvector.c > */

void	vec_set(t_vec *v1, t_vec v2);
void	vec_update(t_vec *v1, t_vec v2);
#endif