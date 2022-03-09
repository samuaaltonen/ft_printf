/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_minus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:41:54 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/09 17:50:20 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_to_zero(t_superint **superint)
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

/*
 * Performs substraction for 2 superints. If value goes to negative, sets it to
 * zero.
*/
int	ft_superint_minus(t_superint **from, t_superint **minus)
{
	t_sll	temp;
	t_ull	carry;
	int		i;

	i = -1;
	carry = 0;
	while (++i < (*minus)->count || carry)
	{
		if (i > (*from)->count - 1)
			return (set_to_zero(from));
		temp = (t_sll)(*from)->numbers[i];
		if (i < (*minus)->count)
			temp -= (t_sll)(*minus)->numbers[i];
		temp -= carry;
		carry = 0;
		if (temp < 0)
		{
			(*from)->numbers[i] = 1000000000 + temp;
			carry = -temp;
		}
		else
			(*from)->numbers[i] = temp;
	}
	return (1);
}
