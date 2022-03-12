/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:55:08 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/12 09:36:46 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	init_float(t_conf **conf)
{
	long double	number;

	if ((*conf)->length == 5)
		number = va_arg((*conf)->ap, long double);
	else
		number = va_arg((*conf)->ap, double);
	if ((*conf)->precision < 0)
		(*conf)->precision = 6;
	if (ft_floatsign(number))
	{
		(*conf)->is_negative = 1;
		number = -number;
	}
	else
		(*conf)->is_negative = 0;
	return (number);
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

static void	float_output_sign_zeroes(t_conf **conf, char *ftoa)
{
	int	len;

	if ((*conf)->is_negative || (*conf)->flag_addsign)
	{
		if ((*conf)->is_negative)
			ft_putchar_n('-', &((*conf)->n));
		else
			ft_putchar_n('+', &((*conf)->n));
	}
	len = ft_strlen(ftoa);
	if ((*conf)->precision > len)
		ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->precision - len);
	if ((*conf)->flag_zeropadded_override && (*conf)->width > len)
	{
		if ((*conf)->is_negative || (*conf)->flag_addsign)
			ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len - 1);
		else
			ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len);
	}
}

static int	float_special_cases(char **ftoa, long double number, t_conf **conf)
{
	t_ldouble_cast	parts;

	parts.f = number;
	if (parts.s_parts.exponent == 32767)
	{
		if (parts.s_parts.mantissa == 0)
			*ftoa = ft_strdup("inf");
		else
		{
			*ftoa = ft_strdup("nan");
			(*conf)->is_negative = 0;
		}
		(*conf)->precision = 3;
		return (1);
	}
	return (0);
}

void	conversion_float(t_conf **conf)
{
	char		*ftoa;
	long double	number;
	int			len;

	number = init_float(conf);
	ftoa = NULL;
	if (!float_special_cases(&ftoa, number, conf))
	{
		ftoa = ft_ftoa(number, (*conf)->precision);
		if (!ftoa)
			exit_error(MSG_ALLOC_FAILED);
	}
	len = float_width(conf, ftoa);
	if ((*conf)->width > len
		&& !(*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded_override)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	float_output_sign_zeroes(conf, ftoa);
	ft_putstr_n(ftoa, &((*conf)->n));
	if ((*conf)->width > len
		&& (*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded_override)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	if (ftoa)
		free(ftoa);
}
