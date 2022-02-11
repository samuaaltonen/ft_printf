/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:49:16 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/11 15:56:36 by saaltone         ###   ########.fr       */
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

void	ft_putchar_n_repeat(char c, int *n, int repeat)
{
	int	i;

	i = 0;
	while (i < repeat)
	{
		ft_putchar(c);
		i++;
	}
	(*n) += i;
}

void	ft_putstr_case(char *str, int is_uppercase)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (is_uppercase)
			ft_putchar(ft_toupper(str[i]));
		else
			ft_putchar(ft_tolower(str[i]));
		i++;
	}
}
