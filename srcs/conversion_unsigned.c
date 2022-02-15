/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:03:23 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/15 14:14:29 by saaltone         ###   ########.fr       */
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

/*
 * Handles unsigned decimal (u) conversion.
*/
void	conversion_unsigned(t_conf **conf)
{
	int					len;
	unsigned long long	number;

	number = get_va_arg_unsigned(conf);
	len = ft_count_digits_ull(number);
	if ((*conf)->width - len > 0
		&& !(*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	if ((*conf)->width - len > 0
		&& !(*conf)->flag_leftadjusted
		&& (*conf)->flag_zeropadded)
		ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len);
	unsigned_output(number, &((*conf)->n));
	if ((*conf)->width - len > 0 && (*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	(*conf)->n += len;
}
