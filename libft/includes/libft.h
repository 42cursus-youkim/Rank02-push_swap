/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:55:22 by youkim            #+#    #+#             */
/*   Updated: 2021/12/14 21:07:09 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//	===== includes =====
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "ymath.h"
# include "ystring.h"
# include "ysystem.h"
# include "ydict.h"
# include "ylinked.h"
# include "colors.h"

/*	===== Documentations =====
	refactored libft by @youkim
	needed and lightweight functions, structured

	[comments]
		entry: ===== TEXT ===== ("=" x5)
		prototypes: @func
					used as identifier in hgen
	[doc scopes]
		header: [TEXT]
		each scope is indented

	[file names prefix]
		new_ : functions that needs to be del_ed.
		del_ : frees allocated memory from new_.
		mod_ : modifies given parameter. similar to methods.
		func_: pure functions. do not modify any given params.

	[types acronym]
		int: i, float: f, double: d, char: c, bool: b, string: s
		array: arr, pointer: ptr, function: fn

	[returns]
		default: OK: 0, ERROR: -1
		bool with 'is_': TRUE: true, FALSE: false
		string: OK: non-null value, ERROR: null

	[prefix]
		new_: uses MALLOC / dynamic allocation. somewhat c++ style.
			every malloced pointer should be freed by except for
				the pointer returned by malloc
			except: all dynamically allocated pointer is freed
				before function exit
		del_: FREE memory allocated by new
		y: ALL LIBFT function by @youkim!

	[infix]
		first 3~4 letters of directory.
		e.g y + arr + len => y_arrlen

	[suffix]
		{types}: same function but with different types
			default INT if unspecified
			new_yarrf, del_yarrll
		i / l / f:	return range includes NEGATIVE VALUES,
			-1 based ERROR handling is not possible
		_f: typedefed function pointers
		_verb: acts like an 'METHOD'.
			e.g ystr_color is used like ystr.color()
			recieves 'reference' to modify.
			only use if the function changes state of given value.
			e.g ystrlen is not method
*/

#endif