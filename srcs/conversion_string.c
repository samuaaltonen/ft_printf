/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:38:20 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/10 14:27:32 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_string(t_conf **conf)
{
	char	*str;
	int		i;
	int		len;

	str = va_arg((*conf)->ap, char *);
	len = ft_strlen(str);
	if ((*conf)->precision >= 0 && len > (*conf)->precision)
		len = (*conf)->precision;
	if (!(*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	if ((*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	(*conf)->n += i;
}
