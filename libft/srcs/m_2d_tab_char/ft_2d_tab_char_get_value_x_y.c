/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_char_get_value_x_y.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:23:35 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/19 19:28:10 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d_tab_char.h"

char	ft_2d_tab_char_get_value_x_y(t_2d_tab_char *tab_2d, int x, int y)
{
	if (!tab_2d || !(tab_2d->tab) || x >= ft_2d_tab_char_get_dim(tab_2d)\
		|| y >= ft_2d_tab_char_get_dim(tab_2d) || x < 0 || y < 0)
		return (0);
	return (tab_2d->tab[y][x]);
}
