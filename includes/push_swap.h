/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:10:56 by youkim            #+#    #+#             */
/*   Updated: 2021/12/19 19:48:39 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//	===== library =====
# include "libft.h"

//	===== structure =====
# include "structure.h"

// ===== main =====
# include "engine.h"
# include "utils.h"
# include "quicksort.h"

# define printf(...) // fprintf(stderr, __VA_ARGS__)
# define operl(engine, op) 				\
		do { oper(engine, op);			\
			system("clear");			\
			engine_visualize(engine);	\
			usleep(200000); } while (0);
# define VIZUAL engine_visualize(e);
#endif