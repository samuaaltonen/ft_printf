/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:22:10 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/02 15:24:07 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_types(t_types **types)
{
	*types = (t_types *)malloc(sizeof(t_types));
	if (!(*types))
		return (0);
	(*types)->integer = 0;
	(*types)->string = NULL;
	(*types)->floating = 0;
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

int	test(const char *format, va_list ap, t_types **types)
{
	if (format[0] == 'i')
	{
		(*types)->integer = va_arg(ap, int);
		ft_putnbr((*types)->integer);
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
			i += 1 + test(format + i + 1, ap, &types);
		ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (0);
}
