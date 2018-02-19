/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_pts_map_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:56:17 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/16 23:56:33 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d_pts_map.h"
#include <stdlib.h>
#include "ft_ori.h"

t_2d_pts_map		*ft_2d_pts_map_init(t_2d_tab_int *tab)
{
	int				c;
	t_2d_pts_map	*marie;

	if (!tab)
		ft_putstr_fd("Tab doesn t exist ...\n", 2);
	if (!(marie = malloc(sizeof(t_2d_pts_map))))
		return (0);
	marie->x = tab->x;
	marie->y = tab->y;
	if (!(marie->map = malloc(sizeof(t_point *) * marie->y)))
		return (0);
	c = 0;
	while (c < marie->y)
	{
		if (!(marie->map[c] = malloc(sizeof(t_point) * marie->x)))
			return (0);
		c++;
	}
	return (marie);
}
