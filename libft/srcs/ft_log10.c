/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:07:55 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/08 21:06:52 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_zero(long double number)
{
	t_ldouble_cast	ldouble_cast;

	ldouble_cast.f = number;
	if (ldouble_cast.s_parts.exponent == 0
		&& ldouble_cast.s_parts.mantissa == 0)
		return (1);
	return (0);
}

/*
 * Returns log10 of given double. In case when input number is 0, returns 0.
 * Example:
 * log10(number) = exponent <=> 10^exponent = number
 * i.e. 
 * log10(0.1) would be -1
 * log10(0) would be inf (returns 0)
 * log10(1) would be 0
 * log10(10) would be 1
 * log10(123456) would be 5.09... (returns int so 5)
*/
int	ft_log10(long double number)
{
	int	exponent;

	if (is_zero(number))
		return (0);
	exponent = 0;
	if (number > 1.L)
	{
		while (number > 1.L)
		{
			number = number / 10;
			exponent++;
		}
		return (exponent - 1);
	}
	while (number < 1.L)
	{
		number = number * 10;
		exponent--;
	}
	return (exponent);
}
