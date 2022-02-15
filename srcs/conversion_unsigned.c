/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:03:23 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/15 17:22:47 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	unsigned_output(unsigned long long number, int *n)
{
	if (number >= 10)
		unsigned_output(number / 10, n);
	ft_putchar(number % 10 + '0');
	(*n)++;
}

static int	unsigned_width(t_conf **conf, long long number)
{
	int	width;

	width = ft_count_digits(number);
	if ((*conf)->precision > width)
		width = (*conf)->precision;
	if ((*conf)->flag_addspace)
		width++;
	return (width);
}

static void	unsigned_output_zeroes(t_conf **conf, long long number)
{
	int	len;

	len = ft_count_digits(number);
	if ((*conf)->precision > len)
		ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->precision - len);
}

/*
 * Handles unsigned decimal (u) conversion.
*/
void	conversion_unsigned(t_conf **conf)
{
	int					len;
	unsigned long long	number;

	number = get_va_arg_unsigned(conf);
	len = unsigned_width(conf, number);
	if ((*conf)->width > len
		&& !(*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	unsigned_output_zeroes(conf, number);
	unsigned_output(number, &((*conf)->n));
	if ((*conf)->width > len
		&& (*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
}