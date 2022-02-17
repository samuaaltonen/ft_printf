/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:28:13 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/17 13:33:32 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_percent(t_conf **conf)
{
	if ((*conf)->width - 1 > 0 && !(*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - 1);
	ft_putchar_n('%', &((*conf)->n));
	if ((*conf)->width - 1 > 0 && (*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - 1);
}
