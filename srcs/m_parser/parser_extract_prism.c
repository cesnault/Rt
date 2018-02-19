/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_prism.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:40:48 by cesnault          #+#    #+#             */
/*   Updated: 2017/07/13 20:34:30 by cesnault         ###   ########.fr       */
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

void					init_pts_prisme(t_spe_object *spe, t_vect3d *vec)
{
	vec[0].x = spe->origin->x - spe->dim->x / 2.0;
	vec[0].y = spe->origin->y + spe->dim->y / 2.0;
	vec[0].z = spe->origin->z;
	vec[1].x = spe->origin->x - spe->dim->x / 2.0;
	vec[1].y = spe->origin->y - spe->dim->y / 2.0;
	vec[1].z = spe->origin->z + spe->dim->z / 2.0;
	vec[2].x = spe->origin->x - spe->dim->x / 2.0;
	vec[2].y = spe->origin->y - spe->dim->y / 2.0;
	vec[2].z = spe->origin->z - spe->dim->z / 2.0;
	vec[3].x = spe->origin->x + spe->dim->x / 2.0;
	vec[3].y = spe->origin->y + spe->dim->y / 2.0;
	vec[3].z = spe->origin->z;
	vec[4].x = spe->origin->x + spe->dim->x / 2.0;
	vec[4].y = spe->origin->y - spe->dim->y / 2.0;
	vec[4].z = spe->origin->z + spe->dim->z / 2.0;
	vec[5].x = spe->origin->x + spe->dim->x / 2.0;
	vec[5].y = spe->origin->y - spe->dim->y / 2.0;
	vec[5].z = spe->origin->z - spe->dim->z / 2.0;
}

void					make_pts_to_prism(t_all_pobject *mimi,\
		t_spe_object *spe, t_vect3d *vec)
{
	t_generic_triangle	gt;

	gt.mimi = mimi;
	gt.spe = spe;
	make_triangle_bitch(gt, vec[0], vec[2], vec[1]);
	make_triangle_bitch(gt, vec[3], vec[5], vec[4]);
	make_triangle_bitch(gt, vec[0], vec[2], vec[3]);
	make_triangle_bitch(gt, vec[2], vec[5], vec[3]);
	make_triangle_bitch(gt, vec[0], vec[1], vec[3]);
	make_triangle_bitch(gt, vec[3], vec[1], vec[4]);
	make_triangle_bitch(gt, vec[1], vec[5], vec[4]);
	make_triangle_bitch(gt, vec[5], vec[1], vec[2]);
}

void					parser_extract_prism(int fd, int type,\
t_all_pobject *mimi)
{
	t_spe_object		*spe;
	t_vect3d			vec[6];
	int					c;

	spe = parser_extract_spe_object(fd, type);
	spe->rot->x = (spe->rot->x) * (2.0 * 3.14) / 360.0;
	spe->rot->y = (spe->rot->y) * (2.0 * 3.14) / 360.0;
	spe->rot->z = (spe->rot->z) * (2.0 * 3.14) / 360.0;
	init_pts_prisme(spe, vec);
	c = 0;
	while (c < 6)
	{
		calcul_rot(&(vec[c]), spe->origin, spe->rot);
		c++;
	}
	make_pts_to_prism(mimi, spe, vec);
	spe_object_destroy(&(spe));
}
