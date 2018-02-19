/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:10:19 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:10:21 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include "vector.h"
# include "rgb.h"
# include "ft_point.h"

typedef struct				s_generic_param
{
	char					*name;
	t_point					dim;
	float					ambiant;
	int						sepia;
	int						stereo;
	int						antialia;
	int						green;
	int						red;
	int						yellow;
	int						neg;
}							t_generic_param;

typedef struct				s_texture
{
	char					*name;
	t_rgb					**rgb;
	t_point					dim;
}							t_texture;

typedef struct				s_texture_all
{
	t_texture				**textu;
	int						nb;
	int						actual;
}							t_texture_all;

/*
** structure generique de stoquage de structure
*/
typedef struct				s_pobject
{
	void					*obj;
	int						type;
}							t_pobject;

typedef struct				s_ptextu
{
	int						type;
	float					refl_diffuse;
	float					refl_specu;
	float					refract;
	void					*obj;
}							t_ptextu;

typedef struct				s_vect3d
{
	double					x;
	double					y;
	double					z;
}							t_vect3d;

/*
** for the bilinear filters
*/

typedef struct				s_bfi
{
	float					x;
	float					y;
	float					ur;
	float					vr;
	float					uo;
	float					vo;
	t_vect3d				c[4];
}							t_bfi;

/*
** structure generique qui stoquera des structures
** genere par des fonction d eparsing d object
*/
typedef struct				s_all_pobject
{
	t_pobject				**all_obj;
	unsigned int			size_total;
	unsigned int			size_use;
}							t_all_pobject;
void						all_pobject_destroy(t_all_pobject *p);

typedef struct				s_cam
{
	t_vect3d				*origin;
	t_vect3d				*rot;
	t_vect3d				*dir;
}							t_cam;

typedef struct				s_color_light
{
	float					x;
	float					y;
	float					z;
}							t_color_light;

typedef struct				s_obj
{
	char					*name;
	t_vect3d				*origin;
	int						id;
	double					rey;
	t_vect3d				*dir;
	t_ptextu				*texture;
	t_color_light			*color_light;
	t_vect3d				*rot;
	t_vect3d				*intersect;
	t_vect3d				*normal;
	t_vect3d				*p1;
	t_vect3d				*p2;
	t_vect3d				*p3;
	int						type;
	int						neg;
	double					t;
}							t_obj;

typedef struct				s_light
{
	char					*name;
	t_vect3d				*origin;
	t_color_light			*color_light;
	double					shadow;
}							t_light;

typedef struct				s_obj_redim
{
	t_obj					**all_obj;
	unsigned int			size_total;
	unsigned int			size_use;
}							t_obj_redim;

void						obj_redim_init(int size, t_obj_redim *r);
void						obj_redim_push(t_obj_redim *r, t_obj *o);
void						obj_redim_destruct(t_obj_redim **r);

typedef struct				s_light_redim
{
	t_light					**all_light;
	unsigned int			size_total;
	unsigned int			size_use;
}							t_light_redim;

void						light_redim_init(int size, t_light_redim *r);
void						light_redim_push(t_light_redim *r, t_light *o);
void						light_redim_destruct(t_light_redim **r);

typedef struct				s_triangle
{
	char					*name;
	t_vect3d				*p1;
	t_vect3d				*p2;
	t_vect3d				*p3;
	t_ptextu				*texture;
	t_color_light			*color_light;
	t_vect3d				*rot;
	t_vect3d				*intersect;
	t_vect3d				*normal;
	int						id;
	int						type;
	double					t;
}							t_triangle;

/*
**spe object : limited plan, carry
*/
typedef	struct				s_spe_object
{
	int						type;
	char					*name;
	t_vect3d				*origin;
	t_vect3d				*dim;
	t_vect3d				*rot;
	t_color_light			*color_light;
	t_ptextu				*texture;
}							t_spe_object;

typedef struct				s_generic_triangle
{
	t_all_pobject			*mimi;
	t_spe_object			*spe;
}							t_generic_triangle;

enum						e_obj
{
	ERROR,
	SQUARE,
	SPHERE,
	CYLINDER,
	CONE,
	PLAN,
	LIGHT,
	CAM,
	GENERIC,
	TRIANGLE,
	RECTANGLE,
	DISK,
	PYRAMID,
	SPHEROID,
	HYPERCUBE,
	PRISM_T,
	PRISM_H
};

enum						e_field
{
	ERR,
	POS,
	DIRR,
	NAME,
	LIGHT_COLOR,
	BEGIN,
	ROT,
	REY,
	TEXTURE,
	DIM,
	AMBIANT,
	P1,
	P2,
	P3,
	DIM_RECT,
	DIM_SQUARE,
	NEG,
	SEPIA,
	STEREO,
	ALIA,
	GREEN,
	RED,
	YELLOW,
	F_NEG,
	END
};

enum						e_field_texture
{
	ERRR,
	COLOR,
	PERLIN,
	PICTURE,
	PROCEDURAL,
	LINK,
	DIFFUSE,
	SPECULAR,
	REFRACT,
	BEGIN2,
	END2
};

/*
** generic param
*/
t_generic_param				*init_generic_param(void);
void						gen_param_set_dim(t_generic_param *g, int x, int y);
void						gen_param_set_ambiant(t_generic_param *g,\
		float ambiant);
void						gen_param_set_name(t_generic_param *g, char *name);
void						gp_min_max_value(t_generic_param *g);
void						malloc_fail(char *str);
/*
** VECTOR 3D
*/
t_vect3d					*vect3d_init(double x, double y, double z);
t_vect3d					vect3d_init2(double x, double y, double z);
double						vect3d_get_x(t_vect3d *vec);
double						vect3d_get_y(t_vect3d *vec);
double						vect3d_get_z(t_vect3d *vec);
void						vect3d_set_x(t_vect3d *vec, double x);
void						vect3d_set_y(t_vect3d *vec, double y);
void						vect3d_set_z(t_vect3d *vec, double z);
void						vect3d_destroy(t_vect3d *v);

/*
** COLOR LIGHT
*/
t_color_light				*color_light_init(float x, float y, float z);
float						color_light_get_x(t_color_light *vec);
float						color_light_get_y(t_color_light *vec);
float						color_light_get_z(t_color_light *vec);
void						color_light_set_x(t_color_light *vec, float x);
void						color_light_set_y(t_color_light *vec, float y);
void						color_light_set_z(t_color_light *vec, float z);
void						color_light_destroy(t_color_light *v);

/*
** CAM
*/
t_cam						*cam_init(void);
double						cam_get_ori_x(t_cam *cam);
double						cam_get_ori_y(t_cam *cam);
double						cam_get_ori_z(t_cam *cam);
double						cam_get_dir_x(t_cam *cam);
double						cam_get_dir_y(t_cam *cam);
double						cam_get_dir_z(t_cam *cam);
void						cam_destroy(t_cam *cam);

/*
** LIGHT
*/
t_light						*light_init(void);
void						light_destroy(t_light **light);
void						free_all_light(t_light **light, int size);

/*
** OBJ
*/
t_obj						*obj_init(void);
void						obj_destroy(t_obj *obj);
void						free_all_obj(t_obj **obj, int size);

/*
** TRIANGLE
*/
t_triangle					*triangle_init(void);
void						triangle_free(t_triangle **triangle);

/*
** SPE OBJECT
*/
t_spe_object				*spe_object_init(void);
void						spe_object_destroy(t_spe_object **s);

void						obj_free_texture(t_ptextu **text);

/*
**	texture dup bitch rt ...
*/

t_ptextu					*dup_ptexture(t_ptextu *pp);

#endif
