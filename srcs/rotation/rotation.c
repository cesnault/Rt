/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
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

void	rotation_x(t_vect3d *vect, double angle, int reverse)
{
	t_vect3d tmp;

	tmp.x = vect->x;
	tmp.y = vect->y * cos((reverse * angle) * M_PI / 180) -\
vect->z * sin((reverse * angle) * M_PI / 180);
	tmp.z = vect->y * sin((reverse * angle) * M_PI / 180) +\
vect->z * cos((reverse * angle) * M_PI / 180);
	vect->x = tmp.x;
	vect->y = tmp.y;
	vect->z = tmp.z;
}

void	rotation_y(t_vect3d *vect, double angle, int reverse)
{
	t_vect3d tmp;

	tmp.x = vect->x * cos((reverse * angle) * M_PI / 180) +\
vect->z * sin((reverse * angle) * M_PI / 180);
	tmp.y = vect->y;
	tmp.z = -1 * (vect->x * sin((reverse * angle) * M_PI / 180)) +\
vect->z * cos((reverse * angle) * M_PI / 180);
	vect->x = tmp.x;
	vect->y = tmp.y;
	vect->z = tmp.z;
}

void	rotation_z(t_vect3d *vect, double angle, int reverse)
{
	t_vect3d tmp;

	tmp.x = vect->x * cos((reverse * angle) * M_PI / 180) -\
vect->y * sin((reverse * angle) * M_PI / 180);
	tmp.y = vect->x * sin((reverse * angle) * M_PI / 180) +\
vect->y * cos((reverse * angle) * M_PI / 180);
	tmp.z = vect->z;
	vect->x = tmp.x;
	vect->y = tmp.y;
	vect->z = tmp.z;
}

void	rotation(t_vect3d *vect, t_vect3d *rot, int reverse)
{
	rotation_x(vect, rot->x, reverse);
	rotation_y(vect, rot->y, reverse);
	rotation_z(vect, rot->z, reverse);
}
