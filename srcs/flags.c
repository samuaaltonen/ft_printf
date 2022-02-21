/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:07:49 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/21 17:15:56 by saaltone         ###   ########.fr       */
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
 * Skip flag chars
*/
void	skip_extra_flags(char **cursor)
{
	if (**cursor == '#'
		|| **cursor == '0'
		|| **cursor == '-'
		|| **cursor == ' '
		|| **cursor == '+')
	{
		(*cursor)++;
		skip_extra_flags(cursor);
	}
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
	if (**cursor == '0' && (*conf)->precision == -1)
	{
		(*conf)->flag_zeropadded = 1;
		(*conf)->flag_zeropadded_override = 1;
	}
	if (**cursor == '-')
		(*conf)->flag_leftadjusted = 1;
	if (**cursor == ' ')
		(*conf)->flag_addspace = 1;
	if (**cursor == '+')
		(*conf)->flag_addsign = 1;
	if ((*conf)->flag_zeropadded && (*conf)->flag_leftadjusted)
		(*conf)->flag_zeropadded = 0;
	(*cursor)++;
	handle_flags(conf, cursor);
}
