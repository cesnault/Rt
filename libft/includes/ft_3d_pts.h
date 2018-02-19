/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_pts.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 00:01:15 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/17 00:01:49 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_3D_PTS_H
# define FT_3D_PTS_H

typedef struct	s_3d_pts
{
	int			x;
	int			y;
	int			z;
}				t_3d_pts;

typedef struct	s_3d_pts_color
{
	t_3d_pts	*pts;
	int			color;
}				t_3d_pts_color;

t_3d_pts		*my_3d_pts_init(int x, int y, int z);

void			my_3d_pts_destroy(t_3d_pts **pts);

t_3d_pts_color	*my_3d_pts_color_init(int x, int y, int z, int colors);

void			my_3d_pts_color_destroy(t_3d_pts_color **pts);

#endif
