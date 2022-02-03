/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:23:37 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/03 13:26:37 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdarg.h>
# include "libft.h"

typedef struct s_types
{
	unsigned char		int_c;
	int					int_i;
	long				int_l;
	long long			int_ll;
	unsigned long long	int_ull;
	char				*string;
	double				*floating;
}	t_types;

int	ft_printf(const char *format, ...);

#endif
