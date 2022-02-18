/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:08:09 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/18 14:34:54 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Parses precision and saves it to conf.
*/
void	handle_precision(t_conf **conf, char **cursor)
{
	int	digits;

	if (**cursor == '.')
	{
		(*cursor)++;
		if (**cursor == '*')
		{
			(*conf)->precision = va_arg((*conf)->ap, int);
			(*cursor)++;
			return ;
		}
		(*conf)->flag_zeropadded = 0;
		(*conf)->precision = ft_atoi(*cursor);
		digits = ft_count_digits((*conf)->precision);
		if (!ft_isdigit(**cursor))
			digits = 0;
		*cursor += digits;
		if (**cursor == '*')
		{
			va_arg((*conf)->ap, int);
			(*cursor)++;
		}
	}
}
