/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:55:03 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/11 01:30:15 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*division_to_string(int log10, int precision, t_superint **n,
								t_superint **d)
{
	t_superint	*mod;
	t_ull		result;
	int			i;
	char		*ftoa;

	if (log10 > 0)
		ftoa = ft_strnew(log10 + precision + 2);
	else
		ftoa = ft_strnew(precision + 3);
	mod = ft_superint_new(0, 3);
	if (!ftoa || !mod)
		return (NULL);
	i = 0;
	while ((log10 >= 0 && i <= (log10 + precision + 1))
		|| (i <= (precision + 1)))
	{
		if (ft_superint_divide_samesize(n, d, &mod, &result) <= 0)
			return (NULL);
		ft_append_char(&ftoa, '0' + result);
		if (!ft_superint_clone(n, &mod)
			|| !ft_superint_multiply_int(n, 10))
			return (NULL);
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

char	*ft_ftoa_positive(long double number, int precision)
{
	t_superint	*numerator;
	t_superint	*denumerator;
	int		log10;
	char	*str;

	if (number < 0)
		number = -number;
	log10 = ft_log10(number);
	if (!ft_ftdiv(number, &numerator, &denumerator)
		|| !ft_ftdiv_scale(log10, &numerator, &denumerator))
		return (NULL);
	if (ft_iszero(number))
		ft_superint_zero(&numerator);
	str = division_to_string(log10, precision, &numerator, &denumerator);
	ft_superint_destroy(&numerator);
	ft_superint_destroy(&denumerator);
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

/*
 * Converts long double into string with given precision.
*/
char	*ft_ftoa(long double number, int precision)
{
	char	*ftoa;
	char	*joined;

	if (number < 0)
	{
		ftoa = ft_ftoa_positive(-number, precision);
		joined = ft_strjoin("-", ftoa);
		free(ftoa);
		return (joined);
	}
	return (ft_ftoa_positive(number, precision));
}
