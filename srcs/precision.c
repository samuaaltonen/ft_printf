/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:08:09 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/10 15:08:51 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Parses precision and saves it to conf.
*/
void	handle_precision(t_conf **conf, char **cursor)
{
	if (**cursor == '.')
	{
		(*conf)->precision = ft_atoi(*cursor + 1);
		*cursor += 1 + ft_count_digits((*conf)->precision);
	}
}
