/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:22:10 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/10 11:48:12 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Saves flag data to configuration.
*/
static void	handle_flags(t_conf **conf, char **cursor)
{
	
}

static void	handle_args(t_conf **conf, char **cursor)
{
	if (*cursor != '%')
	{
		(*cursor)++;
		return ;
	}
	handle_flags(conf, cursor);
}

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
