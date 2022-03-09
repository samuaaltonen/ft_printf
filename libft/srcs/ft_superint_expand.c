/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_expand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:10:05 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/09 13:11:00 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Doubles the allocated area of superint and copies values over.
*/
int	ft_superint_expand(t_superint **addto)
{
	int			i;
	t_superint	*expanded;

	expanded = ft_superint_new(0, (*addto)->allocated * 2);
	if (!expanded)
		return (0);
	i = 0;
	while (i < (*addto)->count)
	{
		expanded->numbers[i] = (*addto)->numbers[i];
		i++;
	}
	ft_superint_destroy(addto);
	*addto = expanded;
	return (1);
}
