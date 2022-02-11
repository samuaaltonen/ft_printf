/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:20:12 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/11 14:23:07 by saaltone         ###   ########.fr       */
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
	{'s', conversion_string},
	{'c', conversion_char},
	{'p', conversion_pointer},
	{'n', conversion_n},
	{'x', conversion_hexadecimal},
	{0, NULL},
	};

	dispatch_conversion((t_dispatch_identifier *) conversions, conf, cursor);
}
