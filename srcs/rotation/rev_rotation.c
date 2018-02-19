/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:31:24 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/19 20:31:25 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include <math.h>

void	inv_rotation_x(t_vect3d *vect, double angle, int reverse)
{
	t_vect3d tmp;

	tmp.x = vect->x;
	tmp.y = vect->y * cos((reverse * angle) * M_PI / 180) +\
vect->z * sin((reverse * angle) * M_PI / 180);
	tmp.z = vect->y * -1 * sin((reverse * angle) * M_PI / 180) +\
vect->z * cos((reverse * angle) * M_PI / 180);
	vect->x = tmp.x;
	vect->y = tmp.y;
	vect->z = tmp.z;
}

void	inv_rotation_y(t_vect3d *vect, double angle, int reverse)
{
	t_vect3d tmp;

	tmp.x = vect->x * cos((reverse * angle) * M_PI / 180) -\
vect->z * sin((reverse * angle) * M_PI / 180);
	tmp.y = vect->y;
	tmp.z = (vect->x * sin((reverse * angle) * M_PI / 180)) +\
vect->z * cos((reverse * angle) * M_PI / 180);
	vect->x = tmp.x;
	vect->y = tmp.y;
	vect->z = tmp.z;
}

void	inv_rotation_z(t_vect3d *vect, double angle, int reverse)
{
	t_vect3d tmp;

	tmp.x = vect->x * cos((reverse * angle) * M_PI / 180) +\
vect->y * sin((reverse * angle) * M_PI / 180);
	tmp.y = -1 * vect->x * sin((reverse * angle) * M_PI / 180) +\
vect->y * cos((reverse * angle) * M_PI / 180);
	tmp.z = vect->z;
	vect->x = tmp.x;
	vect->y = tmp.y;
	vect->z = tmp.z;
}

void	rev_rotation(t_vect3d *vect, t_vect3d *rot, int reverse)
{
	inv_rotation_z(vect, rot->z, reverse);
	inv_rotation_y(vect, rot->y, reverse);
	inv_rotation_x(vect, rot->x, reverse);
}
