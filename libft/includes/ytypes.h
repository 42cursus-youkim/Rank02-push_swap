/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ytypes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:46:51 by youkim            #+#    #+#             */
/*   Updated: 2021/11/26 11:47:24 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YTYPES_H
# define YTYPES_H

typedef enum e_res
{
	OK = 0,
	ERR = -1,
	UNSET = -1,
}	t_res;

typedef void	(*t_del_f)(void *data);

#endif