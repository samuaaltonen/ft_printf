/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superint_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:23:25 by saaltone          #+#    #+#             */
/*   Updated: 2022/03/09 11:23:46 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_superint_destroy(t_superint	**superint)
{
	if (!(*superint))
		return ;
	if ((*superint)->numbers)
		free((*superint)->numbers);
	free(*superint);
}
