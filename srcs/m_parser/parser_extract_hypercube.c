/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_hypercube.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:42:36 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/15 19:10:39 by cesnault         ###   ########.fr       */
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

static void				init_pts_second(t_spe_object *spe,\
t_vect3d *vec)
{
	vec[3].x = spe->origin->x + spe->dim->x;
	vec[3].y = spe->origin->y - spe->dim->y;
	vec[3].z = spe->origin->z - spe->dim->z;
	vec[4].x = spe->origin->x - spe->dim->x;
	vec[4].y = spe->origin->y + spe->dim->y;
	vec[4].z = spe->origin->z + spe->dim->z;
	vec[5].x = spe->origin->x + spe->dim->x;
	vec[5].y = spe->origin->y + spe->dim->y;
	vec[5].z = spe->origin->z + spe->dim->z;
	vec[6].x = spe->origin->x - spe->dim->x;
	vec[6].y = spe->origin->y + spe->dim->y;
	vec[6].z = spe->origin->z - spe->dim->z;
	vec[7].x = spe->origin->x + spe->dim->x;
	vec[7].y = spe->origin->y + spe->dim->y;
	vec[7].z = spe->origin->z - spe->dim->z;
}

static void				init_pts_second_square(t_spe_object *spe,\
t_vect3d *vec)
{
	int					c;

	c = 0;
	vec[0].x = spe->origin->x - spe->dim->x;
	vec[0].y = spe->origin->y - spe->dim->y;
	vec[0].z = spe->origin->z + spe->dim->z;
	vec[1].x = spe->origin->x + spe->dim->x;
	vec[1].y = spe->origin->y - spe->dim->y;
	vec[1].z = spe->origin->z + spe->dim->z;
	vec[2].x = spe->origin->x - spe->dim->x;
	vec[2].y = spe->origin->y - spe->dim->y;
	vec[2].z = spe->origin->z - spe->dim->z;
	init_pts_second(spe, vec);
	while (c < 8)
	{
		calcul_rot(&(vec[c]), spe->origin, spe->rot);
		c++;
	}
}

static void				make_pts_hypercube(t_generic_triangle p,\
t_vect3d *vec_h, t_vect3d *vec_c)
{
	make_triangle_bitch(p, vec_h[0], vec_c[0], vec_c[1]);
	make_triangle_bitch(p, vec_h[1], vec_h[0], vec_c[1]);
	make_triangle_bitch(p, vec_h[4], vec_c[4], vec_c[5]);
	make_triangle_bitch(p, vec_h[5], vec_h[4], vec_c[5]);
	make_triangle_bitch(p, vec_h[4], vec_c[4], vec_c[0]);
	make_triangle_bitch(p, vec_h[0], vec_h[4], vec_c[0]);
	make_triangle_bitch(p, vec_h[5], vec_c[1], vec_c[5]);
	make_triangle_bitch(p, vec_h[5], vec_h[1], vec_c[1]);
	make_triangle_bitch(p, vec_h[2], vec_c[3], vec_c[2]);
	make_triangle_bitch(p, vec_h[2], vec_h[3], vec_c[3]);
	make_triangle_bitch(p, vec_h[6], vec_c[7], vec_c[6]);
	make_triangle_bitch(p, vec_h[6], vec_h[7], vec_c[7]);
	make_triangle_bitch(p, vec_h[6], vec_c[6], vec_c[2]);
	make_triangle_bitch(p, vec_h[2], vec_h[6], vec_c[2]);
	make_triangle_bitch(p, vec_h[7], vec_c[3], vec_c[7]);
	make_triangle_bitch(p, vec_h[7], vec_h[3], vec_c[3]);
	make_triangle_bitch(p, vec_h[5], vec_c[5], vec_c[7]);
	make_triangle_bitch(p, vec_h[7], vec_h[5], vec_c[7]);
	make_triangle_bitch(p, vec_h[0], vec_c[2], vec_c[0]);
	make_triangle_bitch(p, vec_h[0], vec_h[2], vec_c[2]);
	make_triangle_bitch(p, vec_h[4], vec_c[6], vec_c[4]);
	make_triangle_bitch(p, vec_h[4], vec_h[6], vec_c[6]);
	make_triangle_bitch(p, vec_h[1], vec_c[1], vec_c[3]);
	make_triangle_bitch(p, vec_h[3], vec_h[1], vec_c[3]);
}

void					parser_add_hyper(t_all_pobject *mimi,\
t_spe_object *spe, t_vect3d *pts_square)
{
	t_vect3d			vec[8];
	t_generic_triangle	p;

	p.spe = spe;
	p.mimi = mimi;
	init_pts_second_square(spe, vec);
	make_pts_hypercube(p, vec, pts_square);
}

void					parser_extract_hypercube(int fd,\
int type, t_all_pobject *mimi)
{
	t_spe_object		*spe;
	t_vect3d			vec[8];
	int					c;

	spe = parser_extract_spe_object(fd, type);
	spe->rot->x = (spe->rot->x) * (2.0 * 3.14) / 360.0;
	spe->rot->y = (spe->rot->y) * (2.0 * 3.14) / 360.0;
	spe->rot->z = (spe->rot->z) * (2.0 * 3.14) / 360.0;
	init_pts_square(spe, vec);
	c = 0;
	while (c < 8)
	{
		calcul_rot(&(vec[c]), spe->origin, spe->rot);
		c++;
	}
	parser_add_hyper(mimi, spe, vec);
	make_pts_square_all(mimi, spe, vec);
	spe_object_destroy(&(spe));
}
