/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_multiply.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:39:21 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/09 22:09:42 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Multiplies superint with an integer.
*/
int	ft_superint_multiply_int(t_superint **target, int multiplier)
{
	t_ull	temp;
	int		i;
	int		carry;

	if (multiplier <= 0)
	{
		ft_superint_zero(target);
		return (0);
	}
	i = -1;
	carry = 0;
	while (++i < (*target)->count || carry)
	{
		if ((*target)->allocated < i + 1 && !ft_superint_expand(target))
			return (0);
		temp = carry;
		carry = 0;
		if (i < (*target)->count)
			temp += (t_sll)(*target)->numbers[i] * multiplier;
		if (temp >= 1000000000)
			carry = temp / 1000000000;
		if (temp >= 1000000000)
			(*target)->numbers[i] = temp % 1000000000;
		else
			(*target)->numbers[i] = temp;
		if (i > (*target)->count - 1)
			(*target)->count++;
	}
	return (1);
}

/*
 * Multiplies superint with another superint.
*/
int	ft_superint_multiply(t_superint **target, t_superint **multiplier)
{
	t_superint	*copy;
	t_superint	*temp;
	int			i;

	if (ft_superint_iszero(target) || ft_superint_iszero(multiplier))
	{
		ft_superint_zero(target);
		return (1);
	}
	copy = ft_superint_new(0, 10);
	temp = ft_superint_new(0, 10);
	if (!temp || !ft_superint_clone(&copy, target))
		return (0);
	i = -1;
	while (++i < (*multiplier)->count)
	{
		if (!ft_superint_multiply_int(target, (*multiplier)->numbers[i])
			|| !ft_superint_shift(target, i)
			|| !ft_superint_plus(&temp, target)
			|| !ft_superint_clone(target, &copy))
			return (0);
	}
	ft_superint_swap(&temp, target);
	ft_superint_destroy(&temp);
	ft_superint_destroy(&copy);
	return (1);
}
