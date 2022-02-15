/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:55:09 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/15 14:02:43 by saaltone         ###   ########.fr       */
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

/*
 * Handles signed decimal (d, i) conversion.
*/
void	conversion_int(t_conf **conf)
{
	int			len;
	long long	number;

	number = get_va_arg(conf);
	len = ft_count_digits(number);
	if (number < 0 || (*conf)->flag_addsign)
	{
		if (number < 0)
			ft_putchar_n('-', &((*conf)->n));
		else
			ft_putchar_n('+', &((*conf)->n));
		len++;
	}
	if ((*conf)->width - len > 0
		&& !(*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	if ((*conf)->width - len > 0
		&& !(*conf)->flag_leftadjusted
		&& (*conf)->flag_zeropadded)
		ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len);
	int_output(number, &((*conf)->n));
	if ((*conf)->width - len > 0 && (*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	(*conf)->n += len;
}
