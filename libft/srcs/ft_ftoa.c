/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:50:11 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/16 14:11:02 by saaltone         ###   ########.fr       */
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

static void	fill_zeroes(char **str)
{
	int		i;

	i = 0;
	while ((*str)[i] != '|')
	{
		if (!(*str)[i])
			(*str)[i] = '0';
		i++;
	}
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
	while ((*str)[last_empty] && (*str)[last_empty] != '|')
		last_empty++;
	if ((*str)[last_empty] == '|')
		return (0);
	current_digit = number - remainders * 10;
	if (current_digit < 0 || current_digit > 9)
		current_digit = 0;
	(*str)[last_empty] = current_digit + '0';
	return (ft_floor(number));
}

static long double	get_precision_magnitude(int precision)
{
	long double	magnitude;
	int			i;

	i = 0;
	magnitude = 10;
	while (i < precision)
	{
		magnitude *= 10;
		i++;
	}
	return (magnitude);
}

char	*ft_ftoa(long double number, int precision)
{
	char		*str;
	long double	magnitude;
	long double	temp;
	int			digits;

	precision++;
	digits = ft_count_digits_ld(number) + precision;
	magnitude = get_precision_magnitude(precision);
	temp = magnitude * (number - ft_floor(number));
	str = ft_strnew(sizeof(char) * (digits + 2));
	if (!str)
		return (NULL);
	str[digits + 2] = '|';
	append_digit(&str, number);
	append_dot(&str);
	append_digit(&str, temp);
	fill_zeroes(&str);
	str[digits + 2] = 0;
	ft_fa_round(&str, digits + 1, 0);
	str[ft_strlen(str) - 1] = 0;
	return (str);
}
