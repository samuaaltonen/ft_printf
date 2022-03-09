/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_shift.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:50:05 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/09 21:50:42 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Shifts superint to the left by shift amount.
*/
int	ft_superint_shift(t_superint **target, int shift)
{
	int	i;

	i = 0;
	while (i < shift)
	{
		if (!ft_superint_multiply_int(target, 2))
			return (0);
		i++;
	}
	return (1);
}
