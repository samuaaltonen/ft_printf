/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:06:14 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/14 12:19:39 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	octal_precision(t_conf **conf, char **output)
{
	int		i;
	int		len;
	char	*zeros;
	char	*joined;

	if ((*conf)->precision < 0)
		return ;
	len = ft_strlen(*output);
	if ((*conf)->precision > len)
	{
		zeros = ft_strnew((*conf)->precision - len);
		if (!zeros)
			exit_error(MSG_ALLOC_FAILED);
		i = -1;
		while (++i < (*conf)->precision - len)
			zeros[i] = '0';
		joined = ft_strjoin(zeros, *output);
		if (!joined)
			exit_error(MSG_ALLOC_FAILED);
		free(*output);
		free(zeros);
		*output = joined;
	}
}

static void	octal_prefix(t_conf **conf, char **output, long long number)
{
	char	*joined;

	if (!number)
		return ;
	if ((*conf)->flag_hashtag && **output != '0')
	{
		joined = ft_strjoin("0", *output);
		if (!joined)
			exit_error(MSG_ALLOC_FAILED);
		free(*output);
		*output = joined;
	}
}

void	conversion_octal(t_conf **conf)
{
	int			len;
	char		*itoa;
	long long	number;

	number = va_arg((*conf)->ap, long long);
	itoa = ft_itoa_base(number, 8);
	if (itoa)
	{
		octal_precision(conf, &itoa);
		octal_prefix(conf, &itoa, number);
		len = ft_strlen(itoa);
		if ((*conf)->width - len > 0
			&& !(*conf)->flag_leftadjusted
			&& !(*conf)->flag_zeropadded)
			ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
		if ((*conf)->width - len > 0
			&& !(*conf)->flag_leftadjusted
			&& (*conf)->flag_zeropadded)
			ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len);
		ft_putstr_case(itoa, (*conf)->is_uppercase);
		if ((*conf)->width - len > 0 && (*conf)->flag_leftadjusted)
			ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
		(*conf)->n += len;
		free(itoa);
	}
}
