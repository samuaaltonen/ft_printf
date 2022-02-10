/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:23:37 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/10 14:24:50 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MSG_ALLOC_FAILED "Failed to allocate memory."
# include <stdarg.h>
# include "libft.h"

typedef struct s_conf
{
	va_list			ap;
	int				n;
	int				width;
	int				precision;
	int				flag_hashtag;
	int				flag_zeropadded;
	int				flag_leftadjusted;
	int				flag_addspace;
	int				flag_addsign;
}	t_conf;

int		ft_printf(const char *format, ...);

int		init_conf(t_conf **conf);

void	handle_flags(t_conf **conf, char **cursor);
void	handle_width(t_conf **conf, char **cursor);
void	handle_precision(t_conf **conf, char **cursor);

void	exit_error(char	*message);
void	ft_putchar_n(char c, int *n);
void	ft_putchar_n_repeat(char c, int *n, int repeat);
void	ft_putstr_n(char *str, int *n);

void	conversion_string(t_conf **conf);
void	conversion_char(t_conf **conf);

#endif
