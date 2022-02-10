/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:22:10 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/08 15:06:47 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_types(t_types **types)
{
	*types = (t_types *)malloc(sizeof(t_types));
	if (!(*types))
		return (0);
	return (1);
}

int	count_arguments(const char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count++;
		i++;
	}
	return (count);
}

int	somethingsimple(const char *format, va_list ap, t_types **types)
{
	if (format[0] == 'i' || format[0] == 'd')
	{
		(*types)->int_i = va_arg(ap, int);
		ft_putnbr((*types)->int_i);
		return (1);
	}
	if (format[0] == 's')
	{
		(*types)->string = va_arg(ap, char *);
		ft_putstr((*types)->string);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	int			i;
	va_list		ap;
	t_types		*types;

	if (!init_types(&types))
		exit(EXIT_FAILURE);
	i = 0;
	len = ft_strlen(format);
	va_start(ap, format);
	while (i < len)
	{
		if (format[i] == '%')
			i += somethingsimple(format + i + 1, ap, &types);
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	free(types);
	return (0);
}
