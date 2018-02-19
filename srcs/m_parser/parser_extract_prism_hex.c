/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_prism_cyl.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:50:37 by cesnault          #+#    #+#             */
/*   Updated: 2017/07/13 20:35:32 by cesnault         ###   ########.fr       */
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

static void				init_pts_prism_hex(t_spe_object *spe, t_vect3d *vec)
{
	int					c;
	int					rot;
	t_vect3d			v_rot;

	c = 0;
	rot = 0;
	v_rot = vect3d_init2(0.0, 0.0, 0.0);
	while (c < 6)
	{
		vec[c].x = spe->origin->x + spe->dim->x / 2.0;
		vec[c].y = spe->origin->y;
		vec[c].z = spe->origin->z + spe->dim->z / 2.0;
		calcul_rot(&(vec[c]), spe->origin, &v_rot);
		rot += 60;
		v_rot.z = (rot) * (2.0 * 3.14) / 360.0;
		c++;
	}
	while (c < 12)
	{
		vec[c].x = vec[c - 6].x;
		vec[c].y = vec[c - 6].y;
		vec[c].z = vec[c - 6].z - spe->dim->z;
		c++;
	}
}

static t_vect3d			generate_center_point(t_vect3d *vec, int size)
{
	int					c;
	t_vect3d			v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	c = 0;
	while (c < size)
	{
		v.x += vec[c].x;
		v.y += vec[c].y;
		v.z += vec[c].z;
		c++;
	}
	v.x /= (double)(size);
	v.y /= (double)(size);
	v.z /= (double)(size);
	return (v);
}

static void				make_pts_prism_to_hex2(t_generic_triangle gt,\
t_vect3d *vec)
{
	make_triangle_bitch(gt, vec[0], vec[1], vec[6]);
	make_triangle_bitch(gt, vec[1], vec[7], vec[6]);
	make_triangle_bitch(gt, vec[1], vec[2], vec[7]);
	make_triangle_bitch(gt, vec[7], vec[2], vec[8]);
	make_triangle_bitch(gt, vec[2], vec[3], vec[9]);
	make_triangle_bitch(gt, vec[9], vec[8], vec[2]);
	make_triangle_bitch(gt, vec[3], vec[10], vec[4]);
	make_triangle_bitch(gt, vec[9], vec[10], vec[3]);
	make_triangle_bitch(gt, vec[4], vec[11], vec[5]);
	make_triangle_bitch(gt, vec[11], vec[4], vec[10]);
	make_triangle_bitch(gt, vec[5], vec[6], vec[0]);
	make_triangle_bitch(gt, vec[6], vec[5], vec[11]);
}

static void				make_pts_prism_to_hex(t_all_pobject *mimi,\
		t_spe_object *spe, t_vect3d *vec)
{
	t_vect3d			p;
	t_generic_triangle	gt;

	gt.mimi = mimi;
	gt.spe = spe;
	p = generate_center_point(vec, 6);
	make_triangle_bitch(gt, vec[1], vec[0], p);
	make_triangle_bitch(gt, vec[2], vec[1], p);
	make_triangle_bitch(gt, p, vec[3], vec[2]);
	make_triangle_bitch(gt, p, vec[4], vec[3]);
	make_triangle_bitch(gt, p, vec[5], vec[4]);
	make_triangle_bitch(gt, p, vec[0], vec[5]);
	p = generate_center_point(&(vec[6]), 6);
	make_triangle_bitch(gt, p, vec[7], vec[6]);
	make_triangle_bitch(gt, p, vec[8], vec[7]);
	make_triangle_bitch(gt, p, vec[9], vec[8]);
	make_triangle_bitch(gt, p, vec[10], vec[9]);
	make_triangle_bitch(gt, p, vec[11], vec[10]);
	make_triangle_bitch(gt, p, vec[6], vec[11]);
	make_pts_prism_to_hex2(gt, vec);
}

void					parser_extract_prism_hex(int fd, int type,\
		t_all_pobject *mimi)
{
	t_spe_object		*spe;
	t_vect3d			vec[12];
	int					c;

	spe = parser_extract_spe_object(fd, type);
	spe->rot->x = (spe->rot->x) * (2.0 * 3.14) / 360.0;
	spe->rot->y = (spe->rot->y) * (2.0 * 3.14) / 360.0;
	spe->rot->z = (spe->rot->z) * (2.0 * 3.14) / 360.0;
	init_pts_prism_hex(spe, vec);
	c = 0;
	while (c < 12)
	{
		calcul_rot(&(vec[c]), spe->origin, spe->rot);
		c++;
	}
	make_pts_prism_to_hex(mimi, spe, vec);
	spe_object_destroy(&(spe));
}
