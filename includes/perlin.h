/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:09:20 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:09:22 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERLIN_H
# define PERLIN_H

# define WIDTH 500
# define HEIGHT 500

# include "texture.h"

enum		e_typeperlin
{
	SMOOTH,
	WOOD,
	MARBLE
};

double		**generate_double_alea(int height, int width);

void		free_tab2d(double ***str, int size);

double		smooth_noise(double x, double y, double **noise,\
int dim[2]);

double		turbulence(double *pos, double **noise,\
double size, int *dim);

void		smooth_texture(t_texture *text, double **noise, double zoom);

void		marble_texture(t_texture *text, double **noise, double zoom);

void		wood_texture(t_texture *text, double **noise, double zoom);

t_texture	*perlin_texture_generator(t_point dim, int type,\
char *name, int zoom);

#endif
