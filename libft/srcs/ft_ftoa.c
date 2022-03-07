/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:50:11 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/07 21:06:57 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_ftoa_pos(long double number, int precision)
{
	char		*str;
	long double	magnitude;
	long double	temp;
	int			digits;

	precision++;
	digits = ft_count_digits_ld(number) + precision;
	magnitude = 10 * ft_pow(10, precision);
	temp = magnitude * (number - ft_floor(number));
	str = ft_strnew(sizeof(char) * (digits + 2));
	if (!str)
		return (NULL);
	str[digits + 2] = '|';
	append_digit(&str, number);
	ft_append_char(&str, '.');
	if (temp < magnitude / 10)
		ft_append_char(&str, '0');
	append_digit(&str, temp);
	fill_zeroes(&str);
	str[digits + 2] = 0;
	ft_fa_round(&str, digits, 0);
	trim_to_precision(&str, precision);
	return (str);
}

char	*ft_ftoa(long double number, int precision)
{
	char	*temp;
	char	*joined;

	if (ft_floatsign(number))
	{
		temp = ft_ftoa_pos(-number, precision);
		joined = ft_strjoin("-", temp);
		free(temp);
		return (joined);
	}
	return (ft_ftoa_pos(number, precision));
}
