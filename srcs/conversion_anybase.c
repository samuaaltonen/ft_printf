/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_anybase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:09:33 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/04 16:37:01 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Handles anybase conversion. Converts given base-10 integer to any base.
 * Base is given as precision. Supports bases from 2 to 62.
*/
void	conversion_anybase(t_conf **conf)
{
	int			len;
	char		*itoa;
	long long	number;

	number = get_va_arg(conf);
	if ((*conf)->precision <= 1 || (*conf)->precision > 62)
		(*conf)->precision = 2;
	itoa = ft_itoa_base(number, (*conf)->precision);
	if (!itoa)
		return ;
	len = ft_strlen(itoa);
	if (!number && (*conf)->precision == 0)
		len = 0;
	if ((*conf)->width - len > 0 && !(*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	if ((*conf)->width - len > 0 && !(*conf)->flag_leftadjusted
		&& (*conf)->flag_zeropadded)
		ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len);
	if (!(!number && (*conf)->precision == 0))
		ft_putstr_n(itoa, &((*conf)->n));
	if ((*conf)->width - len > 0 && (*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	free(itoa);
}
