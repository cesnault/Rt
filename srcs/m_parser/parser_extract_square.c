/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_square.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 22:34:38 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/15 17:27:19 by cesnault         ###   ########.fr       */
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

t_vect3d			*make_origin(t_vect3d *p1, t_vect3d *p2,\
t_vect3d *p3, t_vect3d *p4)
{
	t_vect3d *vec;

	if (!(vec = malloc(sizeof(t_vect3d))))
		malloc_fail("make_origin");
	vec->x = (p1->x + p2->x + p3->x + p4->x) / 4.0;
	vec->y = (p1->y + p2->y + p3->y + p4->y) / 4.0;
	vec->z = (p1->z + p2->z + p3->z + p4->z) / 4.0;
	return (vec);
}

void				init_pts_square(t_spe_object *spe, t_vect3d *vec)
{
	vec[0].x = spe->origin->x - spe->dim->x / 2.0;
	vec[0].y = spe->origin->y - spe->dim->y / 2.0;
	vec[0].z = spe->origin->z + spe->dim->z / 2.0;
	vec[1].x = spe->origin->x + spe->dim->x / 2.0;
	vec[1].y = spe->origin->y - spe->dim->y / 2.0;
	vec[1].z = spe->origin->z + spe->dim->z / 2.0;
	vec[2].x = spe->origin->x - spe->dim->x / 2.0;
	vec[2].y = spe->origin->y - spe->dim->y / 2.0;
	vec[2].z = spe->origin->z - spe->dim->z / 2.0;
	vec[3].x = spe->origin->x + spe->dim->x / 2.0;
	vec[3].y = spe->origin->y - spe->dim->y / 2.0;
	vec[3].z = spe->origin->z - spe->dim->z / 2.0;
	vec[4].x = spe->origin->x - spe->dim->x / 2.0;
	vec[4].y = spe->origin->y + spe->dim->y / 2.0;
	vec[4].z = spe->origin->z + spe->dim->z / 2.0;
	vec[5].x = spe->origin->x + spe->dim->x / 2.0;
	vec[5].y = spe->origin->y + spe->dim->y / 2.0;
	vec[5].z = spe->origin->z + spe->dim->z / 2.0;
	vec[6].x = spe->origin->x - spe->dim->x / 2.0;
	vec[6].y = spe->origin->y + spe->dim->y / 2.0;
	vec[6].z = spe->origin->z - spe->dim->z / 2.0;
	vec[7].x = spe->origin->x + spe->dim->x / 2.0;
	vec[7].y = spe->origin->y + spe->dim->y / 2.0;
	vec[7].z = spe->origin->z - spe->dim->z / 2.0;
}

void				make_pts_square_all2(t_all_pobject *mimi,\
t_spe_object *spe, t_vect3d *vec)
{
	t_generic_triangle gt;

	gt.mimi = mimi;
	gt.spe = spe;
	make_triangle_bitch2(gt, vec[1], vec[7], vec[5]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[1], &vec[3], &vec[5], &vec[7]);
	make_triangle_bitch2(gt, vec[1], vec[3], vec[7]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[1], &vec[3], &vec[5], &vec[7]);
	make_triangle_bitch2(gt, vec[4], vec[7], vec[5]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[4], &vec[5], &vec[6], &vec[7]);
	make_triangle_bitch2(gt, vec[4], vec[6], vec[7]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[4], &vec[5], &vec[6], &vec[7]);
	make_triangle_bitch2(gt, vec[0], vec[2], vec[1]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[0], &vec[2], &vec[1], &vec[3]);
	make_triangle_bitch2(gt, vec[1], vec[2], vec[3]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[0], &vec[2], &vec[1], &vec[3]);
}

void				make_pts_square_all(t_all_pobject *mimi,\
t_spe_object *spe, t_vect3d *vec)
{
	t_generic_triangle gt;

	gt.mimi = mimi;
	gt.spe = spe;
	make_triangle_bitch2(gt, vec[0], vec[5], vec[1]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[0], &vec[1], &vec[4], &vec[5]);
	make_triangle_bitch2(gt, vec[0], vec[4], vec[5]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[0], &vec[1], &vec[4], &vec[5]);
	make_triangle_bitch2(gt, vec[2], vec[6], vec[7]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[2], &vec[3], &vec[6], &vec[7]);
	make_triangle_bitch2(gt, vec[2], vec[7], vec[3]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[2], &vec[3], &vec[6], &vec[7]);
	make_triangle_bitch2(gt, vec[0], vec[6], vec[4]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[0], &vec[2], &vec[4], &vec[6]);
	make_triangle_bitch2(gt, vec[0], vec[2], vec[6]);
	((t_obj *)mimi->all_obj[mimi->size_use - 1]->obj)->origin =\
	make_origin(&vec[0], &vec[2], &vec[4], &vec[6]);
	make_pts_square_all2(mimi, spe, vec);
}

void				parser_extract_square(int fd, int type, t_all_pobject *mimi)
{
	t_spe_object	*spe;
	t_vect3d		vec[8];
	int				c;

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
	make_pts_square_all(mimi, spe, vec);
	spe_object_destroy(&(spe));
}
