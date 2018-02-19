/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_pyramid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 20:53:09 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/28 20:56:30 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>
#include <unistd.h>
#include "ft_ori.h"
#include "parser.h"
#include "math.h"
#include "rt.h"
#include "generic_parser.h"

static void			init_pts_pyramid(t_spe_object *spe,\
t_vect3d *vec)
{
	vec[0].x = spe->origin->x;
	vec[0].y = spe->origin->y;
	vec[0].z = spe->origin->z + spe->dim->z / 2.0;
	vec[1].x = spe->origin->x - spe->dim->x / 2.0;
	vec[1].y = spe->origin->y + spe->dim->y / 2.0;
	vec[1].z = spe->origin->z - spe->dim->z / 2.0;
	vec[2].x = spe->origin->x + spe->dim->x / 2.0;
	vec[2].y = spe->origin->y + spe->dim->y / 2.0;
	vec[2].z = spe->origin->z - spe->dim->z / 2.0;
	vec[3].x = spe->origin->x + spe->dim->x / 2.0;
	vec[3].y = spe->origin->y - spe->dim->y / 2.0;
	vec[3].z = spe->origin->z - spe->dim->z / 2.0;
	vec[4].x = spe->origin->x - spe->dim->x / 2.0;
	vec[4].y = spe->origin->y - spe->dim->y / 2.0;
	vec[4].z = spe->origin->z - spe->dim->z / 2.0;
}

static void			make_all_triangle(t_all_pobject *mimi,\
t_spe_object *spe, t_vect3d *vec)
{
	t_generic_triangle p;

	p.spe = spe;
	p.mimi = mimi;
	make_triangle_bitch(p, vec[1], vec[2], vec[3]);
	make_triangle_bitch(p, vec[1], vec[3], vec[4]);
	make_triangle_bitch(p, vec[1], vec[0], vec[2]);
	make_triangle_bitch(p, vec[2], vec[0], vec[3]);
	make_triangle_bitch(p, vec[3], vec[0], vec[4]);
	make_triangle_bitch(p, vec[4], vec[0], vec[1]);
}

void				parser_extract_pyramid(int fd, int type,\
t_all_pobject *mimi)
{
	t_spe_object	*spe;
	t_vect3d		vec[5];
	int				c;

	spe = parser_extract_spe_object(fd, type);
	spe->rot->x = (spe->rot->x) * (2.0 * 3.14) / 360.0;
	spe->rot->y = (spe->rot->y) * (2.0 * 3.14) / 360.0;
	spe->rot->z = (spe->rot->z) * (2.0 * 3.14) / 360.0;
	init_pts_pyramid(spe, (t_vect3d *)vec);
	c = 0;
	while (c < 5)
	{
		calcul_rot(&(vec[c]), spe->origin, spe->rot);
		c++;
	}
	make_all_triangle(mimi, spe, vec);
	return ;
}
