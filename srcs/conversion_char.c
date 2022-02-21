/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:46:17 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/21 14:00:07 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_char(t_conf **conf)
{
	char	left_filler;

	left_filler = ' ';
	if ((*conf)->flag_zeropadded || (*conf)->flag_zeropadded_override)
		left_filler = '0';
	if ((*conf)->width - 1 > 0 && !(*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(left_filler, &((*conf)->n), (*conf)->width - 1);
	ft_putchar_n(va_arg((*conf)->ap, int), &((*conf)->n));
	if ((*conf)->width - 1 > 0 && (*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - 1);
}
