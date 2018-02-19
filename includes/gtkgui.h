/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtkgui.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:10:34 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:10:36 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GTKGUI_H
# define GTKGUI_H

# include <gtk/gtk.h>
# include <glib.h>
# include <gdk-pixbuf/gdk-pixbuf.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <dirent.h>
# include "type.h"
# include "parser.h"
# include "vector.h"
# include "ft_ori.h"
# include "perlin.h"
# include "rt.h"

typedef struct				s_objl
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
	char					*type;
	int						neg;
	double					t;
	struct s_objl			*next;
}							t_objl;

typedef struct				s_e
{
	int						perlin;
	int						toggle;
	int						complete;
	double					progress;
	DIR						*dir;
	struct s_objl			*o;
	struct s_generic_param	*g;
	struct s_cam			*cam;
	int						idobj;
	int						ximg;
	int						yimg;
	int						mousex;
	int						mousey;
	int						x;
	int						y;
	int						width;
	int						height;
	GtkWidget				*renderover;
	GdkPixbuf				*pixbufrt;
	GdkPixbuf				*pixbufrtcpy;
	GtkWidget				*window[2];
	GtkWidget				*combo[2];
	GtkWidget				*grid[5];
	GtkWidget				*label[25];
	GtkWidget				*stack[10];
	GtkWidget				*button[10];
	GtkWidget				*entry[32];
	GtkWidget				*image;
	GtkWidget				*imagepb;
	GtkWidget				*imagepbcpy;
	GtkWidget				*note[2];
	GtkWidget				*ebox;
	GtkWidget				*eboxcpy;
	GdkPixbuf				*pixbuf;
	GdkPixbufLoader			*pbloader;
	GtkWidget				*window_addsphere;
	GtkWidget				*combo_addsphere[2];
	GtkWidget				*button_addsphere[17];
	GtkWidget				*grid_addsphere[5];
	GtkWidget				*entry_addsphere[40];
	GtkWidget				*label_addsphere[40];
	GtkWidget				*img_addsphere;
	GtkWidget				*listbox_addsphere[3];
	GtkWidget				*notebook_addsphere;
	GtkWidget				*color_addsphere[2];
	GdkRGBA					*col;
	GtkWidget				*window_addlight;
	GtkWidget				*button_addlight[6];
	GtkWidget				*grid_addlight;
	GtkWidget				*entry_addlight[4];
	GtkWidget				*label_addlight[1];
	GtkWidget				*img_addlight;
	GtkWidget				*window_addambiant;
	GtkWidget				*button_addambiant[6];
	GtkWidget				*grid_addambiant;
	GtkWidget				*entry_addambiant[4];
	GtkWidget				*img_addambiant;
	GtkWidget				*window_campos;
	GtkWidget				*button_campos[6];
	GtkWidget				*grid_campos;
	GtkWidget				*entry_campos[4];
	GtkWidget				*label_campos[5];
	GtkWidget				*img_campos;
	GtkWidget				*window_open;
	GtkWidget				*button_open[50];
	GtkWidget				*grid_open;
	GtkWidget				*entry_open[2];
	GtkWidget				*label_open[3];
	GtkWidget				*img_open;
	GtkWidget				*dialog;
	GtkWidget				*window_render;
	GtkWidget				*button_render[6];
	GtkWidget				*grid_render;
	GtkWidget				*entry_render[3];
	GtkWidget				*label_render[4];
	GtkWidget				*img_render;
	int						ifichier;
	int						id;
	t_rt					*glb;
}							t_e;

/*
**	MAIN
*/

void						gtk_initialize();
void						init_e(t_e *e, t_objl *o);
void						create(t_e *e);
t_objl						*add_in_front(t_objl *o);

void						init_button_0(t_e *e);
void						init_label_0(t_e *e);
void						init_combobox_0(t_e *e);
void						init_grid_0(t_e *e);
void						init_window_0(t_e *e);
void						init_note_0(t_e *e);
void						init_entry_0(t_e *e);
void						quitmenu(GtkWidget *button, t_e *e);

void						init_campos(GtkWidget *button, t_e *e);
void						create_campos(t_e *e);

void						create_add_sphere(t_e *e);
void						create_add_light(t_e *e);
void						create_add_ambiant(t_e *e);

void						create_addsphere(t_e *e);
void						init_addsphere(t_e *e);
void						init_labels_addsphere(t_e *e);
void						init_grid_addsphere(t_e *e);

void						init_addlight(t_e *e);
void						create_addlight(t_e *e);
void						init_addambiant(t_e *e);
void						create_addambiant(t_e *e);
void						choose_addlight(GtkWidget *button, t_e *e);

void						init_open(GtkWidget *button, t_e *e);
void						create_open(t_e *e);
void						save_open(GtkWidget *button, t_e *e);
void						quitwindow_open(GtkWidget *button, t_e *e);

void						init_render(GtkWidget *button, t_e *e);
void						create_render(t_e *e);
void						init_pixbuf_0(t_e *e);
void						put_pixel(t_e *e, guchar red, guchar green,
	guchar blue);
void						put_pixel_cpy(t_e *e, guchar red, guchar green,
	guchar blue);
void						init_image_0(t_e *e);

void						text_color(t_e *e);
void						text_perlin(t_e *e);
void						text_file(t_e *e);
void						text_proced(t_e *e);
void						save_standart(t_e *e);

void						draw(t_rt *glb, t_e *e);
char						*ft_ftoa(double nb, size_t precision);
char						*ft_lltoa(long long n);
void						*ft_realloc(void **ptr, size_t buff);
char						*vectortoa(char *str1, char *str2, char *str3);
void						*ft_realloc(void **ptr, size_t buff);
char						*ft_lltoa(long long n);
char						*ft_ftoa(double nb, size_t precision);
void						button_press(GtkWidget *button,
	GdkEventButton *event, t_e *e);
void						save_in_file(GtkWidget *button, t_e *e);
void						quitwindow_addsphere(GtkWidget *button, t_e *e);
void						choose_obj_type(t_e *e, t_obj *obj);
void						*ft_realloc(void **ptr, size_t buff);
void						place_buttons_addsphere(t_e *e);
void						copy_in_obj(t_e *e, t_obj *obj);
void						chose_id(gint id, t_e *e);
void						quit_confirm(GtkWidget *button, t_e *e);
int							check_file(char *tmp);
char						*vectortoa(char *str1, char *str2, char *str3);
void						quit_confirm(GtkWidget *button, t_e *e);
void						button_press_norm2(t_e *e, int i);
void						button_press_free(char *str1, char *str2,\
	char *str3);
void						setting_free(t_generic_param *setting);
void						tmp_obj_free(t_tidr *tmp_obj);
void						neg_obj_free(t_tir *neg_obj);
void						pos_obj_free(t_tir *pos_obj);
void						cam_free(t_cam *cam);
void						color_free(t_color_light *obj);

#endif
