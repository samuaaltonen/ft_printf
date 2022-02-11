/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:44:33 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/11 12:15:52 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_pointer(t_conf **conf)
{
	int		i;
	int		len;
	char	*itoa;

	itoa = ft_itoa_base(va_arg((*conf)->ap, long long), 16);
	if (itoa)
	{
		len = ft_strlen(itoa) + 2;
		if ((*conf)->width - len > 0 && !(*conf)->flag_leftadjusted)
			ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
		ft_putstr("0x");
		i = 0;
		while (itoa[i])
		{
			ft_putchar(ft_tolower(itoa[i]));
			i++;
		}
		if ((*conf)->width - len > 0 && (*conf)->flag_leftadjusted)
			ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
		(*conf)->n += 2 + i;
		free(itoa);
	}
}
