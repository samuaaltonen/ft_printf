/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fa_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:03:06 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/16 14:17:18 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	prepend_one(char **number)
{
	char	*temp;

	temp = *number;
	*number = ft_strjoin("1", temp);
	free(temp);
	return (1);
}

/*
 * Rounds float to given precision. Float is inputted as ascii string. Returns
 * 1 if rounding has modified the string.
*/
int	ft_fa_round(char **number, int rounding_start, int leftover)
{
	if (!number || (int) ft_strlen(*number) < rounding_start)
		return (0);
	if (rounding_start < 0)
		return (prepend_one(number));
	if ((*number)[rounding_start] == '.')
		return (ft_fa_round(number, rounding_start - 1, leftover));
	if ((*number)[rounding_start] + leftover < '5')
	{
		if (!leftover)
			(*number)[rounding_start] = '0';
		else
			(*number)[rounding_start]++;
		return (1);
	}
	if (!leftover)
	{
		(*number)[rounding_start] = '0';
		return (ft_fa_round(number, rounding_start - 1, 1));
	}
	(*number)[rounding_start]++;
	if ((*number)[rounding_start] <= '9')
		return (1);
	(*number)[rounding_start] = '0';
	ft_fa_round(number, rounding_start - 1, 1);
	return (0);
}
