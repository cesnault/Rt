/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pts_tostring_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:17:01 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/09 14:17:02 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include "ft_ori.h"

void	ft_pts_tostring_fd(t_point *pts, int fd)
{
	if (!pts)
	{
		ft_putstr_fd("ft_pts_tostring_fd : error pts doesn't exist\n", 2);
		return ;
	}
	ft_putstr_fd("t_point[x:", fd);
	ft_putnbr_fd(ft_pts_get_x(pts), fd);
	ft_putstr_fd(";y:", fd);
	ft_putnbr_fd(ft_pts_get_y(pts), fd);
	ft_putstr_fd("]\n", fd);
}
