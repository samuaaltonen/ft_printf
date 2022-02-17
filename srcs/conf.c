/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:25:36 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/17 14:33:36 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_conf(t_conf **conf)
{
	if (!conf)
		return (0);
	*conf = (t_conf *)malloc(sizeof(t_conf));
	if (!(*conf))
		return (0);
	(*conf)->n = 0;
	(*conf)->width = 0;
	(*conf)->length = 0;
	(*conf)->precision = -1;
	(*conf)->flag_hashtag = 0;
	(*conf)->flag_zeropadded = 0;
	(*conf)->flag_leftadjusted = 0;
	(*conf)->flag_addspace = 0;
	(*conf)->flag_addsign = 0;
	(*conf)->is_uppercase = 0;
	(*conf)->is_negative = 0;
	return (1);
}

/*
 * Resets conf info to get rid of any possible flags from previous conversion.
 * Does not reset n counter.
*/
void	reset_conf(t_conf **conf)
{
	(*conf)->width = 0;
	(*conf)->length = 0;
	(*conf)->precision = -1;
	(*conf)->flag_hashtag = 0;
	(*conf)->flag_zeropadded = 0;
	(*conf)->flag_leftadjusted = 0;
	(*conf)->flag_addspace = 0;
	(*conf)->flag_addsign = 0;
	(*conf)->is_uppercase = 0;
	(*conf)->is_negative = 0;
}
