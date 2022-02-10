/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:22:10 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/10 12:09:24 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Handles conversion.
*/
static void	handle_conversion(t_conf **conf, char **cursor)
{
	
}

/*
 * Handles length modifieds (l, llu, hh etc.).
*/
static void	handle_length(t_conf **conf, char **cursor)
{
	
}

static void	handle_args(t_conf **conf, char **cursor)
{
	if (*cursor != '%')
	{
		ft_putchar_n(*cursor, (*conf)->n);
		(*cursor)++;
		return ;
	}
	(*cursor)++;
	handle_flags(conf, cursor);
	handle_length(conf, cursor);
	handle_conversion(conf, cursor);
}

/*
 * Conversion specification is:
 * %[$][flags][width][.precision][length modifier]conversion
*/
int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_conf		*conf;
	char		*cursor;

	if (!init_conf(&conf))
		exit_error(MSG_ALLOC_FAILED);
	cursor = format;
	va_start(ap, format);
	while (*cursor)
		handle_args(&conf, &cursor);
	va_end(ap);
	free(conf);
	return (0);
}
