/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:07:05 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/11 13:07:13 by saaltone         ###   ########.fr       */
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
	if (!(*cursor) || !(**cursor == 'h' || **cursor == 'l' || **cursor == 'L'))
		return ;
	if (**cursor == 'h')
	{
		(*conf)->length = 2;
		if (*((*cursor) + 1) == 'h')
			(*conf)->length = 1;
	}
	if (**cursor == 'l')
	{
		(*conf)->length = 3;
		if (*((*cursor) + 1) == 'l')
			(*conf)->length = 4;
	}
	if (**cursor == 'L')
		(*conf)->length = 5;
	if ((**cursor == 'l' && *((*cursor) + 1) == 'l')
		|| (**cursor == 'h' && *((*cursor) + 1) == 'h'))
			(*cursor)++;
	(*cursor)++;
}
