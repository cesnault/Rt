/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_pts_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 00:02:31 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/17 00:03:05 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2D_PTS_MAP_H
# define FT_2D_PTS_MAP_H

# include "ft_point.h"
# include "ft_2d_tab_int.h"

/*
** simulate tab 2d
*/

typedef struct	s_2d_pts_map
{
	int			x;
	int			y;
	t_point		**map;
}				t_2d_pts_map;

t_2d_pts_map	*ft_2d_pts_map_init(t_2d_tab_int *tab);

void			ft_2d_pts_map_destroy(t_2d_pts_map **tab);

t_point			*ft_2d_pts_map_min_pts(t_2d_pts_map *tab);

t_point			*ft_2d_pts_map_max_pts(t_2d_pts_map *tab);

#endif
