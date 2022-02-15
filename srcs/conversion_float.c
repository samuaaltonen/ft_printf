/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:55:08 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/15 21:37:54 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_float(t_conf **conf)
{
	char		*ftoa;
	long double	number;

	if ((*conf)->length == 5)
		number = va_arg((*conf)->ap, long double);
	else
		number = va_arg((*conf)->ap, double);
	(*conf)->precision = 1000;
	ftoa = ft_ftoa(number, (*conf)->precision);
	ft_putstr(ftoa);
}
