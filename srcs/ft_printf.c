/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:22:10 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/21 13:48:36 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_args(t_conf **conf, char **cursor)
{
	if (!(*cursor) || !(**cursor))
		return ;
	if (**cursor != '%')
	{
		ft_putchar_n(**cursor, &((*conf)->n));
		(*cursor)++;
		return ;
	}
	(*cursor)++;
	reset_conf(conf);
	handle_flags(conf, cursor);
	handle_width(conf, cursor);
	handle_precision(conf, cursor);
	handle_length(conf, cursor);
	handle_flags(conf, cursor);
	handle_conversion(conf, cursor);
}

/*
 * Conversion specification is:
 * %[$][flags][width][.precision][length modifier]conversion
*/
int	ft_printf(const char *format, ...)
{
	t_conf	*conf;
	char	*cursor;
	int		n;

	if (!init_conf(&conf))
		exit_error(MSG_ALLOC_FAILED);
	cursor = (char *) format;
	va_start(conf->ap, format);
	while (*cursor)
		handle_args(&conf, &cursor);
	va_end(conf->ap);
	n = conf->n;
	free(conf);
	return (n);
}
