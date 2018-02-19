/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pts_is_adj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:16:37 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/22 21:16:59 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"

static int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int			ft_pts_is_adj(t_point *pts1, t_point *pts2)
{
	int res_x;
	int res_y;

	if (!pts1 || !pts2)
		return (0);
	res_x = ft_pts_get_x(pts1) - ft_pts_get_x(pts2);
	res_y = ft_pts_get_y(pts1) - ft_pts_get_y(pts2);
	if (res_x == 0 && ft_abs(res_y) == 1)
		return (1);
	if (ft_abs(res_x) == 1 && res_y == 0)
		return (1);
	return (0);
}
