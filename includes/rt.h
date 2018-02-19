/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:10:07 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:10:09 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include "type.h"
# include "parser.h"
# include "tab_int_resize.h"
# include "tab_int_double_resize.h"
# include "../minilibx_macos/mlx.h"

# define NB_OBJ 100
# define NB_LIGHT 10
# define LCOL glb->tab_light->all_light[i]->color_light

typedef struct				s_col
{
	float					r;
	float					g;
	float					b;
}							t_col;

typedef	struct				s_rt
{
	t_obj_redim				*tab_obj;
	t_light_redim			*tab_light;
	t_cam					*cam;
	t_tir					*pos_obj;
	t_tir					*neg_obj;
	t_tidr					*tmp_obj;
	t_generic_param			*setting;
	t_texture				*text;
	int						byte;
	int						*line;
	int						endian;
	void					*mlx;
	void					*win;
	void					*img;
	char					*data;
	t_col					col;
	int						max;
}							t_rt;

typedef struct				s_discr
{
	double					delta;
	double					a;
	double					b;
	double					c;
	double					t;
}							t_discr;

void						rt(t_rt *glb);
void						init_ray(int x, int y, t_cam *cam,\
		t_generic_param *setting);
void						rt_texture(t_rt *glb, t_texture *text);
void						check_hit(t_rt *glb);
void						data_processing(t_all_pobject *pop, t_rt *glb);
void						data_processing_mlx(t_all_pobject *pop, t_rt *glb);

int							get_id_with_ray(int x, int y, t_rt *rt);

void						rotation(t_vect3d *vect,\
		t_vect3d *rot, int reverse);
void						rev_rotation(t_vect3d *vect,\
		t_vect3d *rot, int reverse);

/*
** COLOR MANAGE
*/

t_color_light				color_object(t_rt *glb, int id);

t_color_light				color_obj(t_rt *glb, int id);
t_color_light				rgb_in_color_light(t_rgb rgb);
void						min_maxf(float *v, float min, float max);
t_color_light				color_procedural(t_rt *glb, int id);
t_color_light				color_picture(t_rt *glb, int id);

void						main_uv_texture(t_obj *obj, float *u, float *v);
void						glb_free(t_rt *glb);
void						shadow(t_rt *glb, int id);
void						specular(t_rt *glb, int id);
void						copy_glb(t_rt **glb2, t_rt *glb);
void						init_cam(t_rt *rt, t_all_pobject *pop);
int							init_mlx(t_rt *glb, t_all_pobject *pop);
int							init_mlx_mlx(t_rt *glb, t_all_pobject *pop);
void						init_lst_light(int meter, t_rt *rt,\
		t_all_pobject *pop);
void						init_lst_obj(int meter, t_rt *rt,\
		t_all_pobject *pop);
void						calcul_intersect(t_rt *glb, int id);
void						calcul_normal(t_rt *glb, int id);
void						calcul_rot(t_vect3d *pts,\
		t_vect3d *ori, t_vect3d *rad);

int							check_neg(t_rt *glb, int id);
void						found_id(t_rt *glb, int *id);

t_vect3d					vector_mult2(double a, t_vect3d b);
t_vect3d					vector_norm2(t_vect3d a);
double						vector_len2(t_vect3d a);
t_vect3d					*extract_vector3d(char *data);

void						vect_set_all(t_vect3d *a, double x,\
		double y, double z);

/*
** savoir si un point est dans une sphere
*/

int							is_inter_sphere_other(t_obj *sphere, t_vect3d *pos);

void						hit_object(t_rt *glb, int x, int y);
void						hit_object_texture(t_rt *glb,\
		int x, int y, t_texture *text);

void						stock(t_rt *glb, int x, int y);
void						stock_texture(t_rt *glb, int x,\
		int y, t_texture *text);

void						draw_text(t_texture *text);
void						mlx_draw(t_rt *glb);
void						refraction_v2(t_rt *glb, int id);
t_color_light				recur_refl(t_rt *glb, int id);
void						outs(t_rt *glb, int id, int *id2,\
		t_color_light *glb_col2);
void						ambiante(t_rt *glb, int id);
void						diffuse(t_rt *glb, int id);

void						hit_ball(t_rt *glb, t_obj *ball);
void						hit_spheroid(t_rt *glb, t_obj *cyl);
void						hit_cylindre(t_rt *glb, t_obj *cyl);
void						hit_disk(t_rt *glb, t_obj *p);
void						hit_plan(t_rt *glb, t_obj *p);
void						hit_cone(t_rt *glb, t_obj *cone);
void						hit_triangle(t_rt *glb, t_obj *triangle);
void						hit_rectangle(t_rt *glb, t_obj *rect);

int							is_hit_cylinder(t_rt *gln, t_obj *cyl);

void						ref_ball(t_rt *glb, t_obj *ball,\
		int *id, double *t);
void						ref_cylindre(t_rt *glb, t_obj *cyl,\
		int *id, double *t);
void						ref_plan(t_rt *glb, t_obj *p,\
		int *id, double *t);
void						ref_cone(t_rt *glb, t_obj *cone,\
		int *id, double *t);
t_vect3d					*vect_sub(t_vect3d *a, t_vect3d *b);
t_vect3d					*vect_add(t_vect3d *a, t_vect3d *b);
t_vect3d					vect_mult2(t_vect3d *a, t_vect3d *b);
t_vect3d					vect_sub2(t_vect3d *a, t_vect3d *b);
void						vect_sub3(t_vect3d *ori, t_vect3d *a, t_vect3d *b);
void						vect_add3(t_vect3d *ori, t_vect3d *a, t_vect3d *b);
t_vect3d					vect_add2(t_vect3d *a, t_vect3d *b);
void						vect_normalize(t_vect3d *a);
double						vect_dot(t_vect3d *a, t_vect3d *b);
void						vect_scalaire(t_vect3d *a, double b);
t_vect3d					vect_cross(t_vect3d *v1, t_vect3d *v2);
t_vect3d					*vect_dup(t_vect3d *vec);
t_color_light				*color_light_dup(t_color_light *vec);
void						update_main_texture(t_rt *glb);

void						rt_destroy(t_rt **glb);
int							key(int keycode, void *param);
int							red_cross(void *param);
t_all_pobject				*extract_data_little(char *name);
t_vect3d					vect_sub2(t_vect3d *a, t_vect3d *b);
void						apply_rotation(t_rt *glb, t_vect3d *tmp, int id);
void						refract(t_rt *glb, int id, double n1, double n2);
void						hit(t_rt *glb, int id);
void						calcul(t_rt *glb, int id);
void						outs(t_rt *glb, int id, int *id2,
	t_color_light *glb_col2);
void						enter(t_rt *glb, int id);
int							ft_clamp(int value, int min, int max);
void						uv_sphere(t_obj *o, float *u, float *v);
void						uv_cylinder(t_obj *o, float *u, float *v);
t_vect3d					rgb_to_vect3d(t_rgb r);
t_vect3d					vect3d_mult(t_vect3d a, float b);
t_vect3d					vect3d_mult2(t_vect3d a, t_vect3d b);
t_vect3d					vect3d_add(t_vect3d a, t_vect3d b);
t_all_pobject				*extract_data_little(char *name);
t_all_pobject				*extract_data(int argc, char **argv);
void						free_generic(t_all_pobject *pop, unsigned int i);
#endif
