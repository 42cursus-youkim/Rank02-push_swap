/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:10:56 by youkim            #+#    #+#             */
/*   Updated: 2021/12/12 20:00:26 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "structure.h"
# include "engine.h"
# include "opers.h"

# define operl(engine, op) 				\
		do { oper(engine, op);			\
			system("clear");			\
			engine_visualize(engine);	\
			usleep(400000); } while (0);
#endif