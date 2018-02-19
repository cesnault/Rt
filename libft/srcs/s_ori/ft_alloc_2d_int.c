/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_2d_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 22:05:56 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/06 22:06:43 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ori.h"

int		**ft_alloc_2d_int(int y, int x)
{
	int	**tab;
	int	c_y;

	c_y = 0;
	if (!(tab = malloc(sizeof(int *) * y)))
		return (0);
	while (c_y < y)
	{
		if (!(tab[c_y] = malloc(sizeof(int) * (x + 1))))
		{
			ft_putstr_fd("ft_alloc_2d_int: bug alloc\n", 2);
			return (0);
		}
		c_y++;
	}
	return (tab);
}
