/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:08:11 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/10 15:08:33 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Parses width and saves it to conf.
*/
void	handle_width(t_conf **conf, char **cursor)
{
	if (ft_isdigit(**cursor))
	{
		(*conf)->width = ft_atoi(*cursor);
		*cursor += ft_count_digits((*conf)->width);
	}
}
