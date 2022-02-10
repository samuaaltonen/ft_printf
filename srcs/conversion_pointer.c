/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:44:33 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/10 16:57:36 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_pointer(t_conf **conf)
{
	int		i;
	char	*itoa;

	itoa = ft_itoa_base(va_arg((*conf)->ap, long long), 16);
	if (itoa)
	{
		i = 0;
		ft_putstr("0x");
		while (itoa[i])
		{
			ft_putchar(ft_tolower(itoa[i]));
			i++;
		}
		(*conf)->n += 2 + i;
		free(itoa);
	}
}
