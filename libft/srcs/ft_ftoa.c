/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:50:11 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/15 22:44:52 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	append_dot(char **str)
{
	int		last_empty;

	last_empty = 0;
	while ((*str)[last_empty])
		last_empty++;
	(*str)[last_empty] = '.';
}

static long double	ft_floor(long double number)
{
	long long	max_ull;

	max_ull = (long long) 1 << 62;
	if (number < (long double) max_ull)
		return ((long double)(long long)number);
	return (max_ull + ft_floor(number - (long double) max_ull));
}

static long double	append_digit(char **str, long double number)
{
	int		current_digit;
	int		last_empty;
	double	remainders;

	remainders = 0;
	if (number >= 10)
		remainders = append_digit(str, number / 10);
	last_empty = 0;
	while ((*str)[last_empty])
		last_empty++;
	current_digit = number - remainders * 10;
	if (current_digit < 0 || current_digit > 9)
		current_digit = 0;
	(*str)[last_empty] = current_digit + '0';
	return (ft_floor(number));
}

char	*ft_ftoa(long double number, int precision)
{
	char	*str;

	str = ft_strnew(sizeof(char) * (precision + 2));
	if (!str)
		return (NULL);
	append_digit(&str, number);
	append_dot(&str);
	return (str);
}
