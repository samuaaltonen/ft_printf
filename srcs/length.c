/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:07:05 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/10 15:07:28 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Handles length modifieds (l, llu, hh etc.):
 * hh	= 1 (char)
 * h	= 2 (short)
 * l	= 3 (long)
 * ll	= 4 (long long)
 * L	= 5 (long double)
*/
void	handle_length(t_conf **conf, char **cursor)
{
	int	move;

	if (!(*cursor) || !(**cursor))
		return ;
	if (!(**cursor == 'h' || **cursor == 'l' || **cursor == 'L'))
		return ;
	move = 1;
	if (**cursor == 'h')
	{
		(*conf)->length = 2;
		if (*((*cursor) + 1) == 'h')
		{
			(*conf)->length = 1;
			move++;
		}
	}
	if (**cursor == 'l')
	{
		(*conf)->length = 3;
		if (*((*cursor) + 1) == 'l')
		{
			(*conf)->length = 4;
			move++;
		}
	}
	if (**cursor == 'L')
		(*conf)->length = 5;
	(*cursor) += move;
}