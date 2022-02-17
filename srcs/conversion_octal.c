/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:06:14 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/17 16:31:47 by saaltone         ###   ########.fr       */
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

static void	octal_prefix(t_conf **conf, char **output, unsigned long long nbr)
{
	char	*joined;

	if (!nbr)
		return ;
	if ((*conf)->flag_hashtag
		&& (**output != '0' || (!nbr && (*conf)->precision == 0)))
	{
		joined = ft_strjoin("0", *output);
		if (!joined)
			exit_error(MSG_ALLOC_FAILED);
		free(*output);
		*output = joined;
	}
}

static void	octal_width(t_conf **conf, char **itoa, unsigned long long number,
						int *len)
{
	if (*itoa && !number && (*conf)->precision == 0 && !(*conf)->flag_hashtag)
	{
		**itoa = '\0';
		*len = 0;
		return ;
	}
	*len = ft_strlen(*itoa);
}

/*
 * Handles octal conversion. Treats given numbers as unsigned.
*/
void	conversion_octal(t_conf **conf)
{
	int					len;
	char				*itoa;
	unsigned long long	number;

	number = get_va_arg_unsigned(conf);
	itoa = ft_itoa_base_ull(number, 8, 0);
	if (!itoa)
		return ;
	octal_precision(conf, &itoa);
	octal_prefix(conf, &itoa, number);
	octal_width(conf, &itoa, number, &len);
	if ((*conf)->width - len > 0
		&& !(*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	if ((*conf)->width - len > 0
		&& !(*conf)->flag_leftadjusted
		&& (*conf)->flag_zeropadded)
		ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len);
	ft_putstr_n_case(itoa, &((*conf)->n), (*conf)->is_uppercase);
	if ((*conf)->width - len > 0 && (*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	free(itoa);
}
