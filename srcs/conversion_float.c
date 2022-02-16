/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:55:08 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/16 14:59:48 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	init_float_conf_and_get_number(t_conf **conf)
{
	long double	number;

	if ((*conf)->length == 5)
		number = va_arg((*conf)->ap, long double);
	else
		number = va_arg((*conf)->ap, double);
	if ((*conf)->precision < 0)
		(*conf)->precision = 6;
	if (number < 0)
	{
		(*conf)->is_negative = 1;
		number = -number;
	}
	else
		(*conf)->is_negative = 0;
	return (number);
}

static void	float_output_sign(t_conf **conf)
{
	if ((*conf)->is_negative || (*conf)->flag_addsign)
	{
		if ((*conf)->is_negative)
			ft_putchar_n('-', &((*conf)->n));
		else
			ft_putchar_n('+', &((*conf)->n));
	}
}

static int	float_width(t_conf **conf, char	*ftoa)
{
	int	width;

	width = ft_strlen(ftoa);
	if ((*conf)->precision > width)
		width = (*conf)->precision;
	if ((*conf)->is_negative || (*conf)->flag_addsign)
		width++;
	if ((*conf)->flag_addspace)
		width++;
	return (width);
}

static void	float_output_zeroes(t_conf **conf, char	*ftoa)
{
	int	len;

	len = ft_strlen(ftoa);
	if ((*conf)->precision > len)
		ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->precision - len);
	if ((*conf)->flag_zeropadded && (*conf)->width > len)
	{
		if ((*conf)->is_negative || (*conf)->flag_addsign)
			ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len - 1);
		else
			ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len);
	}
}

void	conversion_float(t_conf **conf)
{
	char		*ftoa;
	long double	number;
	int			len;

	number = init_float_conf_and_get_number(conf);
	ftoa = ft_ftoa(number, (*conf)->precision);
	if (!ftoa)
		return ;
	len = float_width(conf, ftoa);
	if ((*conf)->width > len
		&& !(*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	float_output_sign(conf);
	float_output_zeroes(conf, ftoa);
	ft_putstr_n(ftoa, &((*conf)->n));
	if ((*conf)->width > len
		&& (*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	free(ftoa);
}
