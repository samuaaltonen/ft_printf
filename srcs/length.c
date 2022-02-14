/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:07:05 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/14 17:26:44 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Uses va_arg to get given argument with correct lenght. For char and short
 * (hh, h) it gets the argument as int but then truncates it to char/short by
 * casting. (Because va_arg automatically promotes it to int)
*/
long long	get_va_arg(t_conf **conf)
{
	long long	temp;

	if ((*conf)->length == 0)
		temp = va_arg((*conf)->ap, int);
	if ((*conf)->length == 1)
		temp = (char) va_arg((*conf)->ap, int);
	if ((*conf)->length == 2)
		temp = (short) va_arg((*conf)->ap, int);
	if ((*conf)->length == 3)
		temp = va_arg((*conf)->ap, long);
	if ((*conf)->length == 4)
		temp = va_arg((*conf)->ap, long long);
	if (temp < 0)
		(*conf)->is_negative = 1;
	else
		(*conf)->is_negative = 0;
	return (temp);
}

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
	(*conf)->length = 0;
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
