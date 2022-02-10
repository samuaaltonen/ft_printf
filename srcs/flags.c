/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:07:49 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/10 13:24:21 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Returns 1 if char is valid flag char.
*/
static int	is_flag_character(char c)
{
	if (c == '#'
		|| c == '0'
		|| c == '-'
		|| c == ' '
		|| c == '+')
		return (1);
	return (0);
}

/*
 * Saves flag data to configuration.
*/
void	handle_flags(t_conf **conf, char **cursor)
{
	if (!is_flag_character(**cursor))
		return ;
	if (**cursor == '#')
		(*conf)->flag_hashtag = 1;
	if (**cursor == '0')
		(*conf)->flag_zeropadded = 1;
	if (**cursor == '-')
		(*conf)->flag_leftadjusted = 1;
	if (**cursor == ' ')
		(*conf)->flag_addspace = 1;
	if (**cursor == '+')
		(*conf)->flag_addsign = 1;
	(*cursor)++;
	handle_flags(conf, cursor);
}
