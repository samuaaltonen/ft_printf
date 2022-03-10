/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftdiv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:01:05 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/10 20:07:06 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Converts exponential form of float to division of 2 integers. 
 * Example (single precision but same method for double and extended):
 * 
 * 0.75f = 00111111111000000000000000000000
 * [sign = 0][exponent = 01111111 = 127][mantissa = 11000000000000000000000]
 * Exponent is biased by 127 (offset), so substracting 127 leaves 0 as exponent
 * Mantissa is 6291456
 * 
 * Equation is: (1 + [mantissa] / 2^23) * 2^([exponent]-127)
 *            = (1 + 6291456 / 2^23) * 2^0
 *            = 1 + 6291456 / 8388608 = 1.75
 * 
 * The idea is to modify this equation so that it becomes a fraction of two
 * integers instead of exponential form:
 * 
 * (1 + [mantissa] / 2^23) * 2^([exponent]-127) * 2^0
 * (1 + [mantissa] / 2^23) * 2^([exponent]-127) * 2^(23-23)
 * (1 + [mantissa] / 2^23) * 2^([exponent]-127-23) * 2^23
 * (2^23 + [mantissa]) * 2^([exponent]-127-23)
 * (2^23 + [mantissa]) / 2^-([exponent]-127-23)
 * numerator           / denumerator
*/
void	ft_ftdiv(double number, t_ull *n, t_ull *d)
{
	t_sll			denum_exp;
	t_ull			numerator;
	t_double_cast	ldouble_cast;

	ldouble_cast.f = number;
	numerator = (((t_ull) 1) << 52) + ldouble_cast.s_parts.mantissa;
	denum_exp = ldouble_cast.s_parts.exponent - 1023 - 52;
	if (denum_exp > 0)
	{
		*n = numerator;
		*n <<= denum_exp;
		*d = 1;
		return ;
	}
	*n = numerator;
	*d = ((t_ull) 1) << -denum_exp;
}

/*
 * Scales given numerator and denumerator by adding zeros so that the result
 * of division casted to int is allways one digit.
 * If log10 is higher than 0 it means that the original number is 10 or
 * higher, therefore we need to scale denumerator up.
 * Similarly, if log10 is less than 0, we scale numerator up.
 * Only scales up and not down to avoid losing any precision.
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
