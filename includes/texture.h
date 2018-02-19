/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:08:56 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:08:59 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "rgb.h"
# include "ft_point.h"
# include "type.h"

t_texture			*texture_init(char *name, int width, int height);

/*
** add pixel in texture struct at cord x y
*/
void				texture_add_pixel(t_texture *text, t_rgb rgb, int x, int y);

t_rgb				*texture_get_pixel(t_texture *text, int x, int y);

void				convert_xyz_to_uv(t_vect3d *pos, float *u,\
float *v, int *index);

void				texture_destroy(t_texture **text);

t_texture			*texture_dup(t_texture *text);

#endif
