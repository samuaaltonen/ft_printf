/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_divide.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:03:14 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/10 22:03:31 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Divides 2 superints that are same size in magnitude (scaled to same count).
 * Returns negative number on error:
 * -1 division by zero
 * -2 difference in magnitude
 * -3 allocation failed
*/
int	ft_superint_divide_samesize(t_superint **num, t_superint **denum,
		t_superint **mod, t_ull *result)
{
	t_superint	*temp;
	t_superint	*quotient;
	int			i;

	if (ft_superint_iszero(denum))
		return (-1);
	if ((*num)->count != (*denum)->count)
		return (-2);
	if (ft_superint_iszero(num) || ft_superint_compare(denum, num) < 0)
	{
		*result = 0;
		return (1);
	}
	i = (*num)->count - 1;
	quotient = ft_superint_new((*num)->numbers[i] / (*denum)->numbers[i], 3);
	temp = ft_superint_new(0, 3);
	if (!quotient || !ft_superint_clone(&temp, denum)
		|| !ft_superint_multiply(&temp, &quotient))
		return (-3);
	if (ft_superint_compare(&temp, denum) > 0
		&& !ft_superint_plus_int(&quotient, 1))
		return (-3);
	if (!ft_superint_clone(mod, num))
		return (-3);
	ft_superint_minus(mod, &quotient);
	*result = ft_superint_to_ull(&quotient);
	ft_superint_destroy(&temp);
	ft_superint_destroy(&quotient);
	return (1);
}
