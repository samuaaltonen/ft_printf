/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:08:09 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/17 17:30:48 by saaltone         ###   ########.fr       */
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
		if (*(*cursor + 1) == '*')
		{
			(*conf)->precision = va_arg((*conf)->ap, int);
			(*cursor) += 2;
			return ;
		}
		(*conf)->flag_zeropadded = 0;
		(*conf)->precision = ft_atoi(*cursor + 1);
		digits = ft_count_digits((*conf)->precision);
		if (!ft_isdigit(*(*cursor + 1)))
			digits = 0;
		*cursor += 1 + digits;
	}
}
