/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_vect3d2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:38:37 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/02 19:38:42 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

void			vect3d_set_x(t_vect3d *vec, double x)
{
	if (vec)
		vec->x = x;
}

void			vect3d_set_y(t_vect3d *vec, double y)
{
	if (vec)
		vec->y = y;
}

void			vect3d_set_z(t_vect3d *vec, double z)
{
	if (vec)
		vec->z = z;
}

void			vect3d_destroy(t_vect3d *v)
{
	if (v)
		free(v);
}
