/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:55:09 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/15 17:19:15 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	int_output(long long number, int *n)
{
	if (number < 0)
		number = -1 * number;
	if (number >= 10)
		int_output(number / 10, n);
	ft_putchar(number % 10 + '0');
	(*n)++;
}

static void	int_output_sign(t_conf **conf, long long number)
{
	if (number < 0 || (*conf)->flag_addsign)
	{
		if (number < 0)
			ft_putchar_n('-', &((*conf)->n));
		else
			ft_putchar_n('+', &((*conf)->n));
	}
}

static int	int_width(t_conf **conf, long long number)
{
	int	width;

	width = ft_count_digits(number);
	if ((*conf)->precision > width)
		width = (*conf)->precision;
	if ((*conf)->flag_addsign || number < 0)
		width++;
	if ((*conf)->flag_addspace)
		width++;
	return (width);
}

static void	int_output_zeroes(t_conf **conf, long long number)
{
	int	len;

	len = ft_count_digits(number);
	if ((*conf)->precision > len)
		ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->precision - len);
	if ((*conf)->flag_zeropadded && (*conf)->width > len)
	{
		if (number < 0 || (*conf)->flag_addsign)
			ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len - 1);
		else
			ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len);
	}
}

/*
 * Handles signed decimal (d, i) conversion.
 *
 * Note: Adds zeropadding when precision is higher than digit count, even
 *       though when zeropadding flag is not set.
*/
void	conversion_int(t_conf **conf)
{
	int			len;
	long long	number;

	number = get_va_arg(conf);
	len = int_width(conf, number);
	if ((*conf)->width > len
		&& !(*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	int_output_sign(conf, number);
	int_output_zeroes(conf, number);
	int_output(number, &((*conf)->n));
	if ((*conf)->width > len
		&& (*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
}
