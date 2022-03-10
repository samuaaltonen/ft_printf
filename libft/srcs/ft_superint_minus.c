/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_minus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:41:54 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/10 21:40:21 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	update_count(t_superint **superint)
{
	if ((*superint)->count <= 1)
		return ;
	if ((*superint)->numbers[(*superint)->count - 1] == 0)
	{
		(*superint)->count--;
		update_count(superint);
	}
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
			return (ft_superint_zero(from));
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
	update_count(from);
	return (1);
}

/*
 * Substract int from superint
*/
int	ft_superint_minus_int(t_superint **from, int minus)
{
	t_sll	temp;
	int		i;

	i = 0;
	while (minus)
	{
		if (i > (*from)->count - 1)
			return (ft_superint_zero(from));
		temp = (t_sll)(*from)->numbers[i] - minus;
		minus = 0;
		if (temp < 0)
		{
			(*from)->numbers[i] = 1000000000 + temp;
			minus = -temp;
		}
		else
			(*from)->numbers[i] = temp;
		i++;
	}
	return (1);
}

