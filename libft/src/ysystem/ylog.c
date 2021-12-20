/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:29:52 by youkim            #+#    #+#             */
/*   Updated: 2021/12/20 16:25:18 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	log at STDOUT, but does not kill process
void	ywarn(char *warn)
{
	ywritecolors(1, YEL, (char *[]){"[Warning]\n    ", warn, "\n", NULL});
}

//	log at STDERR, kill process
void	yerror(char *where, char *err)
{
	ywritecolors(2, BHRED, (char *[]){
		"[Error! @ ", where, "]\n    ", err, "\n", NULL});
	yexit(1);
}

int	ycheckerr(int statement, char *err)
{
	if (statement == ERR)
		yerror("ycheckerr", err);
	return (statement);
}

void	yassert(bool statement, char *where, char *err)
{
	if (!statement)
		yerror(where, err);
}
