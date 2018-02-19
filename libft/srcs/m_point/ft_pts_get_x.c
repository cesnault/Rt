/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pts_get_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:15:57 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/22 21:16:02 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"

int	ft_pts_get_x(t_point *pts)
{
	if (!pts)
		return (0);
	return (pts->x);
}