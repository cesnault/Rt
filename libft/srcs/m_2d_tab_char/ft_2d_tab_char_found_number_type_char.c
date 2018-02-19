/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_char_found_number_type_char.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 22:23:46 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/20 23:11:21 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d_tab_char.h"

int	ft_2d_tab_char_found_number_type_char(t_2d_tab_char **tab_2d, char c)
{
	int x;
	int y;
	int count;

	if (!tab_2d || !(*tab_2d) || !((*tab_2d)->tab))
		return (0);
	x = 0;
	y = 0;
	count = 0;
	while (y < (*tab_2d)->dim)
	{
		while (x < (*tab_2d)->dim)
		{
			if ((*tab_2d)->tab[y][x] == c)
				count++;
			x++;
		}
		y++;
		x = 0;
	}
	return (count);
}
