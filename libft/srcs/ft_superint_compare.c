/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_compare.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:00:59 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/10 22:01:14 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Compares two superints. Returns: 
 * positive if a is higher than b
 * 0 if a is same as b
 * negative if a is less than b
*/
int	ft_superint_compare(t_superint **a, t_superint **b)
{
	if ((*a)->count != (*b)->count)
		return ((*a)->count - (*b)->count);
	return ((*a)->numbers[(*a)->count - 1] - (*b)->numbers[(*b)->count - 1]);
}
