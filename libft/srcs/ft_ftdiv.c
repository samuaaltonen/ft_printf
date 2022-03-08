/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftdiv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:01:05 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/08 22:03:05 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Converts exponential form of float to division of 2 integers. 
 * Example:
 * 0.5f = 1.0 * 2^-1 [int part = 1][mantissa = 0][exponent (nonbiased) = -1]
 * ==> (0 + 1 * 2^52) / (1 * 2^53) = 2^-1 = 0.5f
 *     ([mantissa] + 1 * 2^52) / (1 * 2^(52 - [exponent (nonbiased)]))
 *     numerator               / denumerator
*/
void	ft_ftdiv(double number, t_ull *n, t_ull *d)
{
	t_sll			exponent_normal;
	t_ull			mantissa_sum;
	t_double_cast	ldouble_cast;

	ldouble_cast.f = number;
	mantissa_sum = (((t_ull) 1) << 52) + ldouble_cast.s_parts.mantissa;
	exponent_normal = ldouble_cast.s_parts.exponent - 1023 - 52;
	*n = 0;
	*d = mantissa_sum;
	if (exponent_normal > 0)
	{
		*n = mantissa_sum;
		*n <<= exponent_normal;
		*d = 1;
		return ;
	}
	*n = mantissa_sum;
	*d = ((t_ull) 1) << -exponent_normal;
}

/*
 * Scales given numerator and denumerator by adding zeros so that the result
 * of division casted to int is allways one digit.
 * If log10 is higher than 0 it means that the original number is 10 or
 * higher, therefore we need to scale denumerator up.
 * Similarly if log10 is less than 0, we scale numerator up.
 * Only scales up to avoid losing any precision.
*/
void	ft_ftdiv_scale(int log10, t_ull *n, t_ull *d)
{
	if (log10 < 0)
	{
		while (log10 < 0)
		{
			*n *= 10;
			log10++;
		}
		return ;
	}
	while (log10 > 0)
	{
		*d *= 10;
		log10--;
	}
}
