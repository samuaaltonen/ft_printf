/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:39:42 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/16 13:59:31 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Floors given long double.
*/
long double	ft_floor(long double number)
{
	long long	max_ull;

	max_ull = (long long) 1 << 62;
	if (number < (long double) max_ull)
		return ((long double)(long long)number);
	return (ft_floor(number / 2) * 2);
}