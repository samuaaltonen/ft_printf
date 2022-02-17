/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:38:20 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/17 13:40:30 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_conf **conf, char *str, int len)
{
	int		i;

	if ((*conf)->width - len > 0 && !(*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	if ((*conf)->width - len > 0 && (*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	(*conf)->n += i;
}

void	conversion_string(t_conf **conf)
{
	char	*str;
	int		len;

	str = va_arg((*conf)->ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if ((*conf)->precision >= 0 && len > (*conf)->precision)
		len = (*conf)->precision;
	print_str(conf, str, len);
}
