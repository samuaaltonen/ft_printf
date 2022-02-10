/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:25:36 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/10 11:30:50 by saaltone         ###   ########.fr       */
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
	return (1);
}
