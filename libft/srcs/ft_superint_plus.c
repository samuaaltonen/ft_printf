/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:45:20 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/09 14:08:52 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Adds second superint to the first one.
*/
int	ft_superint_plus(t_superint **addto, t_superint **add)
{
	t_ull	temp;
	t_ull	carry;
	int		i;

	i = -1;
	carry = 0;
	while (++i < (*add)->count || carry)
	{
		if ((*addto)->allocated < i - 1 && !ft_superint_expand(addto))
			return (0);
		temp = ((t_ull)(*addto)->numbers[i]);
		if (i < (*add)->count)
			temp += ((t_ull)(*add)->numbers[i]);
		temp += carry;
		carry = 0;
		if (temp >= 1000000000)
			carry = temp / 1000000000;
		if (temp >= 1000000000)
			(*addto)->numbers[i] = temp % 1000000000;
		else
			(*addto)->numbers[i] = temp;
		if (i > (*addto)->count - 1)
			(*addto)->count++;
	}
	return (1);
}
