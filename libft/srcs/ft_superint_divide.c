/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_divide.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:03:14 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/11 01:38:12 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_overshoot(t_superint **n, t_superint **d, t_superint **temp,
		t_ull *res)
{
	if (ft_superint_compare(temp, n) > 0)
	{
		*res -= 1;
		if (!ft_superint_clone(temp, d)
			|| !ft_superint_multiply_int(temp, *res))
			return (0);
		return (handle_overshoot(n, d, temp, res));
	}
	return (1);
}

/*
 * Divides 2 superints that are same size in magnitude (scaled to same count).
 * Returns negative number on error:
 * -1 division by zero
 * -2 difference in magnitude
 * -3 allocation failed
*/
int	ft_superint_divide_samesize(t_superint **n, t_superint **d,
		t_superint **mod, t_ull *res)
{
	t_superint	*temp;

	if (ft_superint_iszero(d))
		return (-1);
	if (ft_superint_iszero(n))
	{
		*res = 0;
		return (1);
	}
	if (ft_superint_compare(n, d) < 0)
	{
		if (!ft_superint_clone(mod, n))
			return (-3);
		*res = 0;
		return (1);
	}
	if ((*n)->count < (*d)->count)
		*res = 0;
	else
		*res = (*n)->numbers[(*n)->count - 1] / (*d)->numbers[(*d)->count - 1];
	if (*res > 9)
		*res = 9;
	temp = ft_superint_new(0, 3);
	if (!ft_superint_clone(&temp, d)
		|| !ft_superint_multiply_int(&temp, *res))
		return (-3);
	handle_overshoot(n, d, &temp, res);
	if (!ft_superint_clone(mod, n))
		return (-3);
	if (!ft_superint_clone(&temp, d)
		|| !ft_superint_multiply_int(&temp, *res))
		return (-3);
	ft_superint_minus(mod, &temp);
	ft_superint_destroy(&temp);
	return (1);
}
