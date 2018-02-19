/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_char_init_tab_with_value.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:02:25 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/23 03:47:17 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d_tab_char.h"
#include "ft_ori.h"

void	ft_2d_tab_char_init_tab_with_value(t_2d_tab_char **tab_2d)
{
	int				x;
	int				y;
	t_2d_tab_char	*tab_2;

	x = 0;
	y = 0;
	tab_2 = *tab_2d;
	if (!tab_2d || !(*tab_2d))
		return ;
	while (y < tab_2->dim)
	{
		while (x < tab_2->dim)
		{
			tab_2->tab[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}
