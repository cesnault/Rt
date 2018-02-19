/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:02:20 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 19:03:08 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <math.h>

void			calcul_rot(t_vect3d *pts, t_vect3d *ori, t_vect3d *rad)
{
	t_vect3d	riri;
	t_vect3d	tmp;

	riri.x = pts->x - ori->x;
	riri.y = pts->y - ori->y;
	riri.z = pts->z - ori->z;
	tmp.x = riri.x * cos(rad->z) - riri.y * sin(rad->z);
	tmp.y = riri.x * sin(rad->z) + riri.y * cos(rad->z);
	tmp.z = riri.z;
	riri.x = tmp.x;
	riri.y = tmp.y * cos(rad->x) - tmp.z * sin(rad->x);
	riri.z = tmp.y * sin(rad->x) + tmp.z * cos(rad->x);
	tmp.x = riri.z * sin(rad->y) + riri.x * cos(rad->y);
	tmp.y = riri.y;
	tmp.z = riri.z * cos(rad->y) - riri.x * sin(rad->y);
	pts->x = ori->x + tmp.x;
	pts->y = ori->y + tmp.y;
	pts->z = ori->z + tmp.z;
}
