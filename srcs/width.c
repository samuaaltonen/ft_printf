/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:08:11 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/17 17:43:48 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Parses width and saves it to conf.
*/
void	handle_width(t_conf **conf, char **cursor)
{
	if (**cursor == '*')
	{
		(*conf)->width = va_arg((*conf)->ap, int);
		if ((*conf)->width < 0)
		{
			(*conf)->width *= -1;
			(*conf)->flag_leftadjusted = 1;
		}
		(*cursor)++;
	}
	if (ft_isdigit(**cursor))
	{
		(*conf)->width = ft_atoi(*cursor);
		*cursor += ft_count_digits((*conf)->width);
	}
	if (**cursor == '*')
		(*cursor)++;
}
