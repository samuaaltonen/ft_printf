/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:50:19 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/09 11:54:10 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	superint_init_zeros(t_superint **superint)
{
	int	i;

	i = 0;
	while (i < (*superint)->count)
	{
		((*superint)->numbers)[i] = 0;
		i++;
	}
}

/*
 * Creates superint struct and adds given start value to int. If necessary
 * splits up to 3 integers.
*/
t_superint	*ft_superint_new(t_ull start, int count)
{
	t_superint	*superint;

	superint = (t_superint *)malloc(sizeof(t_superint));
	if (!superint)
		return (NULL);
	superint->allocated = count;
	superint->count = 1;
	superint->numbers = (int *)malloc(sizeof(int) * count);
	if (!(superint->numbers))
		return (NULL);
	superint_init_zeros(&superint);
	(superint->numbers)[0] = start % 1000000000;
	if (start >= 1000000000)
	{
		start /= 1000000000;
		(superint->numbers)[1] = start % 1000000000;
		superint->count++;
	}
	if (start >= 1000000000)
	{
		start /= 1000000000;
		(superint->numbers)[2] = start % 1000000000;
		superint->count++;
	}
	return (superint);
}
