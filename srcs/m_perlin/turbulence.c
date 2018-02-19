/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turbulence.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:56:01 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/09 17:10:44 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "perlin.h"

/*
** permet d obtenir un bruit aleatoire coherents
*/

double		turbulence(double *pos,\
double **noise, double size, int *dim)
{
	double	v;
	double	init_size;

	v = 0.0;
	init_size = size;
	while (size >= 1.0)
	{
		v += smooth_noise(pos[0] / size, pos[1] / size, noise,\
		dim) * size;
		size /= 2.0;
	}
	return (128.0 * v / init_size);
}
