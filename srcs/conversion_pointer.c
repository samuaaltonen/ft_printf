/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:44:33 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/17 16:38:33 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* void	conversion_pointer(t_conf **conf)
{
	int			i;
	int			len;
	char		*itoa;
	long long	ptr;

	ptr = va_arg((*conf)->ap, long long);
	itoa = ft_itoa_base(ptr, 16);
	if (!itoa)
		return ;
	len = ft_strlen(itoa) + 2;
	if ((*conf)->width - len > 0 && !(*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	ft_putstr_n("0x", &((*conf)->n));
	i = 0;
	if (!(!ptr && (*conf)->precision == 0))
	{
		i = -1;
		while (itoa[++i])
			ft_putchar(ft_tolower(itoa[i]));
	}
	if ((*conf)->width - len > 0 && (*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	(*conf)->n += i;
	free(itoa);
} */

static void	pointer_precision(t_conf **conf, char **output)
{
	int		i;
	int		len;
	char	*zeros;
	char	*joined;

	if ((*conf)->precision < 0)
		return ;
	len = ft_strlen(*output);
	if ((*conf)->precision <= len)
		return ;
	zeros = ft_strnew((*conf)->precision - len);
	if (!zeros)
		exit_error(MSG_ALLOC_FAILED);
	i = 0;
	while (i < (*conf)->precision - len)
	{
		zeros[i] = '0';
		i++;
	}
	joined = ft_strjoin(zeros, *output);
	if (!joined)
		exit_error(MSG_ALLOC_FAILED);
	free(*output);
	free(zeros);
	*output = joined;
}

static void	pointer_prefix(t_conf **conf, char **output, unsigned long long nbr)
{
	char	*joined;

	if ((*conf)->flag_zeropadded && !(*conf)->flag_leftadjusted)
	{
		ft_putstr("0x");
		(*conf)->width -= 2;
		(*conf)->n += 2;
		return ;
	}
	if (!nbr && ft_strlen(*output) == 1 && (*conf)->precision == 0)
		(*output)[0] = '\0';
	joined = ft_strjoin("0x", *output);
	if (!joined)
		exit_error(MSG_ALLOC_FAILED);
	free(*output);
	*output = joined;
}

/*
 * Handles pointer conversion.
*/
void	conversion_pointer(t_conf **conf)
{
	int					len;
	char				*itoa;
	unsigned long long	number;

	number = va_arg((*conf)->ap, unsigned long long);
	itoa = ft_itoa_base_ull(number, 16, 0);
	if (!itoa)
		return ;
	pointer_precision(conf, &itoa);
	pointer_prefix(conf, &itoa, number);
	len = ft_strlen(itoa);
	if (!number && (*conf)->precision == 0)
		len = 2;
	if ((*conf)->width - len > 0 && !(*conf)->flag_leftadjusted
		&& !(*conf)->flag_zeropadded)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	if ((*conf)->width - len > 0 && !(*conf)->flag_leftadjusted
		&& (*conf)->flag_zeropadded)
		ft_putchar_n_repeat('0', &((*conf)->n), (*conf)->width - len);
	ft_putstr_n_case(itoa, &((*conf)->n), 0);
	if ((*conf)->width - len > 0 && (*conf)->flag_leftadjusted)
		ft_putchar_n_repeat(' ', &((*conf)->n), (*conf)->width - len);
	free(itoa);
}
