/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:55:03 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/08 21:47:26 by saaltone         ###   ########.fr       */
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
static void	set_division_parts(double number, t_ull *n, t_ull *d)
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
static void	scale_division_parts(int log10, t_ull *n, t_ull *d)
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

static char	*division_to_string(int log10, int precision, t_ull *n, t_ull *d)
{
	t_ull	temp;
	int		i;
	char	*ftoa;

	if (log10 > 0)
		ftoa = ft_strnew(log10 + precision + 2);
	else
		ftoa = ft_strnew(precision + 3);
	if (!ftoa)
		return (NULL);
	i = 0;
	while ((log10 >= 0 && i <= (log10 + precision + 1))
		|| (i <= (precision + 1)))
	{
		temp = *n / *d;
		ft_append_char(&ftoa, '0' + temp);
		*n = *n - temp * *d;
		*n *= 10;
		i++;
	}
	return (ftoa);
}

static void	set_zeroes_and_dot(int log10, int precision, char **ftoa)
{
	int	i;

	if (log10 < 0)
	{
		ft_memmove(*ftoa + -log10 + 1, *ftoa, ft_strlen(*ftoa));
		i = 0;
		while (i <= -log10)
		{
			(*ftoa)[i] = '0';
			i++;
		}
		(*ftoa)[1] = '.';
		return ;
	}
	ft_memmove(*ftoa + log10 + 2, *ftoa + log10 + 1, precision + 1);
	(*ftoa)[log10 + 1] = '.';
}

static void	trim_to_precision(char **str, int precision)
{
	int	dot_pos;

	if (!str)
		return ;
	dot_pos = 0;
	while ((*str)[dot_pos] && (*str)[dot_pos] != '.')
		dot_pos++;
	if ((*str)[dot_pos] != '.')
		return ;
	if ((int) ft_strlen(*str) < dot_pos + precision)
		return ;
	(*str)[dot_pos + precision] = 0;
	if ((*str)[ft_strlen(*str) - 1] == '.')
		(*str)[ft_strlen(*str) - 1] = 0;
}

/*
 * Converts long double into string with given precision.
*/
char	*ft_ftoa(long double number, int precision)
{
	t_ull	numerator;
	t_ull	denumerator;
	int		log10;
	char	*str;

	if (number < 0)
		number = -number;
	log10 = ft_log10(number);
	set_division_parts(number, &numerator, &denumerator);
	scale_division_parts(log10, &numerator, &denumerator);
	if (ft_iszero(number))
		numerator = 0;
	str = division_to_string(log10, precision, &numerator, &denumerator);
	if (!str)
		return (NULL);
	set_zeroes_and_dot(log10, precision, &str);
	if (log10 < 0)
		ft_fa_round(&str, precision + 2, 0);
	else
		ft_fa_round(&str, log10 + precision + 2, 0);
	trim_to_precision(&str, precision + 1);
	return (str);
}
