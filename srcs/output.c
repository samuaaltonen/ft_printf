/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:49:16 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/10 11:50:33 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	exit_error(char	*message)
{
	ft_putstr(message);
	exit(EXIT_FAILURE);
}

void	ft_putchar_n(char c, int *n)
{
	ft_putchar(c);
	(*n)++;
}
