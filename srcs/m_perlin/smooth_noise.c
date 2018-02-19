/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:55:50 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 19:29:07 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** realise une interpolation bilineaire entre les deux points x et y
** http://www.f-legrand.fr/scidoc/docimg/image/niveaux/interpolation/
** interpolation.html
*/

double		smooth_noise(double x, double y, double **noise, int dim[2])
{
	double	v;
	double	fract[2];
	int		xx[2];
	int		yy[2];

	fract[0] = x - (int)(x);
	fract[1] = y - (int)(y);
	xx[0] = (((int)(x)) + dim[0]) % dim[0];
	yy[0] = (((int)(y)) + dim[1]) % dim[1];
	xx[1] = (xx[0] + dim[0] - 1) % dim[0];
	yy[1] = (yy[0] + dim[1] - 1) % dim[1];
	v = fract[0] * fract[1] * noise[yy[0]][xx[0]];
	v += (1 - fract[0]) * fract[1] * noise[yy[0]][xx[1]];
	v += fract[0] * (1 - fract[1]) * noise[yy[1]][xx[0]];
	v += (1 - fract[0]) * (1 - fract[1]) * noise[yy[1]][xx[1]];
	return (v);
}
