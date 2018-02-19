/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:07:47 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:07:49 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "type.h"
# include "generic_parser.h"

t_texture					*parser_extract_bmp(char *str);
t_texture					*parser_extract_png(char *str);

t_color_light				*color_light_init(float r, float g, float b);

int							type_perlin(char *str);

/*
**  found field type(ex : pos : )
*/
int							field_type(char *str);

int							field_type_texture(char *str);

/*
** parser type obj : found type of form
*/
int							parser_type_obj(char *str);

/*
**  function to update to improve
*/
t_pobject					*parser_extract_generic(int fd, int type,\
		t_all_pobject *mimi);

/*
**  ------------
** initalistion du tableau d objet
*/
t_all_pobject				*init_all_pobject(unsigned int size);

/*
**  ajouter un objet dans le tableau d objet
*/
void						add_pobject_in_all(t_all_pobject *all,\
t_pobject *obj);

/*
**  ajout d une adresse void dirrectement dans la structure
*/
void						add_void_in_pobject(t_all_pobject *all,\
void *data, unsigned int type);

/*
** creation d un pobject
*/
t_pobject					*pobject_create(void *obj, int type);

/*
** main parser biatch
*/
t_all_pobject				*main_parser(char *name);

/*
**  function on big level
** verif begining of data
*/
int							parser_extract_verif(int fd);

/*
**  extract cam: (vector dim and pos)
*/
t_cam						*parser_extract_cam(int fd);

t_obj						*parser_extract_obj(int fd);

t_ptextu					*parser_extract_texture(int fd, char *str);

t_light						*parser_extract_light(int fd);

t_texture					*parser_extract_perlin(char *str);

t_spe_object				*parser_extract_spe_object(int fd, int type_obj);

t_obj						*parser_extract_spheroid(int fd);

void						parser_extract_rectangle(int fd, int type,\
		t_all_pobject *mimi);
void						parser_rectangle(t_all_pobject *mimi,
	t_spe_object *spe);

t_generic_param				*parser_extract_generic_param(int fd);

t_spe_object				*extract_spe_object(int fd, int type_obj);
t_obj						*parser_extract_triangle(int fd);

void						init_pts_square(t_spe_object *spe, t_vect3d *vec);
void						make_pts_square_all(t_all_pobject *mimi,\
		t_spe_object *spe, t_vect3d *vec);
void						parser_extract_square(int fd, int type,\
		t_all_pobject *mimi);

void						parser_extract_pyramid(int fd, int type,\
		t_all_pobject *mimi);

void						parser_extract_hypercube(int fd, int type,\
		t_all_pobject *mimi);

/*
** prism
*/
void						parser_extract_prism(int fd, int type,\
		t_all_pobject *mimi);

void						parser_extract_prism_hex(int fd,\
		int type, t_all_pobject *mimi);

/*
** read line fie the type object
*/

int							found_type_obj_to_extract(int fd);

int							type_texture(char *str);

#endif
