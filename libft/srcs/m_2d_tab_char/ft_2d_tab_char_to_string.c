/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_char_to_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:57:36 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/19 18:05:02 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "ft_2d_tab_char.h"

void	ft_2d_tab_char_to_string(t_2d_tab_char *tab_2d)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < tab_2d->dim)
	{
		while (x < tab_2d->dim)
		{
			ft_putchar(tab_2d->tab[y][x]);
			x++;
		}
		x = 0;
		y++;
		ft_putchar('\n');
	}
}
