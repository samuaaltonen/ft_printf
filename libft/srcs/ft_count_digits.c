/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:59:36 by saaltone          #+#    #+#             */
/*   Updated: 2021/11/12 11:25:21 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits(int number)
{
	int	digits;

	digits = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / 10;
		digits++;
	}
	return (digits);
}
