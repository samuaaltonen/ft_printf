/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:08:46 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/09 22:10:20 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_superint_zero(t_superint **superint)
{
	int	i;

	i = (*superint)->count - 1;
	while (i >= 0)
	{
		(*superint)->numbers[i] = 0;
		i--;
	}
	(*superint)->count = 1;
	return (0);
}
