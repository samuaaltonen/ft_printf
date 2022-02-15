/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:20:12 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/15 21:04:02 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	dispatch_conversion(t_dispatch_identifier	*conversions,
	t_conf **conf, char **cursor)
{
	int	i;

	i = 0;
	while (conversions[i].identifier)
	{
		if (conversions[i].identifier == **cursor)
		{
			conversions[i].function(conf);
			(*cursor)++;
			return ;
		}
		i++;
	}
}

/*
 * Handles conversion.
*/
void	handle_conversion(t_conf **conf, char **cursor)
{
	static t_dispatch_identifier	conversions[] = {
	{'%', conversion_skip},
	{'s', conversion_string},
	{'c', conversion_char},
	{'p', conversion_pointer},
	{'n', conversion_n},
	{'x', conversion_hexadecimal_lower},
	{'X', conversion_hexadecimal_upper},
	{'o', conversion_octal},
	{'d', conversion_int},
	{'i', conversion_int},
	{'u', conversion_unsigned},
	{'f', conversion_float},
	{0, NULL},
	};

	dispatch_conversion((t_dispatch_identifier *) conversions, conf, cursor);
}
