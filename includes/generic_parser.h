/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:09:09 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:09:11 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_PARSER_H
# define GENERIC_PARSER_H

# include <type.h>
# include "rgb.h"
# include "ft_point.h"

char					*parser_extract_begin(char *begining, char *data);

t_rgb					*parser_extract_rgb(char *begining, char *data);

t_vect3d				*parser_extract_vector(char *begining, char *data);
t_vect3d				*parser_extract_vector2d(char *begining, char *data);

t_point					parser_extract_dim(char *begining, char *data);

t_color_light			*parser_extract_vector_float(char *begining,\
char *data);

char					*parser_extract_string(char *begining, char *data);

int						parser_extract_int(char *begining,\
char *data, int *error);

double					parser_extract_double(char *begining,\
char *data, int *error);

float					parser_extract_float(char *begining,\
char *data, int *error);

t_ptextu				*dup_texture_color(t_ptextu *p, float r,\
float g, float b);

void					make_triangle_bitch(t_generic_triangle t,\
t_vect3d p1, t_vect3d p2, t_vect3d p3);

void					make_triangle_bitch2(t_generic_triangle t,\
t_vect3d p1, t_vect3d p2, t_vect3d p3);

#endif
