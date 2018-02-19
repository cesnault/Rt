/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_int_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:59:24 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/16 23:59:38 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d_tab_int.h"
#include <stdlib.h>
#include "ft_ori.h"

t_2d_tab_int		*ft_2d_tab_int_init(int y, int x)
{
	int				c;
	t_2d_tab_int	*tab;

	c = 0;
	if (!(tab = malloc(sizeof(t_2d_tab_int))))
		return (0);
	tab->x = x;
	tab->y = y;
	if (!(tab->tab = malloc(sizeof(int *) * y)))
	{
		ft_putstr_fd("fail alloc 2 ...\n", 2);
		return (0);
	}
	while (c < tab->y)
	{
		if (!(tab->tab[c] = malloc(sizeof(int) * tab->x)))
		{
			ft_putstr_fd("Fail fail alloc ...\n", 2);
			return (0);
		}
		c++;
	}
	return (tab);
}
