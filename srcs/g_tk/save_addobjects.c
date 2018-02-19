/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_addobjects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:51:00 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/07 15:51:01 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"
#include "rt.h"
#include "bmp.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void		save_standart(t_e *e)
{
	const gchar		*tmp;
	char			*str;

	e->o = add_in_front(e->o);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[0]));
	e->o->name = (char *)tmp;
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[1]));
	str = (char *)tmp;
	e->o->origin = extract_vector3d(str);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[2]));
	str = (char *)tmp;
	e->o->rot = extract_vector3d(str);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[3]));
	str = (char *)tmp;
	e->o->dir = extract_vector3d(str);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[5]));
	str = (char *)tmp;
	e->o->rey = ft_atoi_double(str);
	e->o->p1 = NULL;
	e->o->p2 = NULL;
	e->o->p3 = NULL;
}

void		text_color(t_e *e)
{
	t_ptextu		*textu;
	t_color_light	*clight2;
	const gchar		*tmp;
	GdkRGBA			rgba;

	textu = NULL;
	clight2 = NULL;
	if (!(textu = malloc(sizeof(t_ptextu))))
		malloc_fail("text_color");
	if (!(clight2 = malloc(sizeof(t_color_light))))
		malloc_fail("text_color");
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[8]));
	textu->refl_specu = (float)ft_atoi_double((char *)tmp);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[9]));
	textu->refl_diffuse = (float)ft_atoi_double((char *)tmp);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[28]));
	textu->refract = (float)ft_atoi_double((char *)tmp);
	textu->type = 1;
	gtk_color_chooser_get_rgba(\
		GTK_COLOR_CHOOSER(e->button_addsphere[3]), &rgba);
	clight2->x = rgba.red;
	clight2->y = rgba.green;
	clight2->z = rgba.blue;
	textu->obj = clight2;
	e->o->texture = textu;
}

int			choose_perlin(char *tmp)
{
	if (ft_strcmp(tmp, "SMOOTH") == 0)
		return (SMOOTH);
	if (ft_strcmp(tmp, "WOOD") == 0)
		return (WOOD);
	if (ft_strcmp(tmp, "MARBLE") == 0)
		return (MARBLE);
	return (0);
}

void		text_perlin(t_e *e)
{
	const gchar		*tmp;
	t_ptextu		*textu;
	t_texture		*tex;
	t_point			*pts;

	if (!(textu = malloc(sizeof(t_ptextu))))
		malloc_fail("text_perlin");
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[20]));
	textu->refl_specu = (float)ft_atoi_double((char *)tmp);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[21]));
	textu->refl_diffuse = (float)ft_atoi_double((char *)tmp);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[29]));
	textu->refract = (float)ft_atoi_double((char *)tmp);
	tmp = gtk_combo_box_text_get_active_text(\
		GTK_COMBO_BOX_TEXT(e->combo_addsphere[0]));
	pts = ft_pts_init(e->glb->setting->dim.x, e->glb->setting->dim.y);
	tex = perlin_texture_generator(*pts, choose_perlin((char*)tmp),
		(char*)gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[11])),
		ft_atoi((char*)gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[13]))));
	textu->type = PERLIN;
	textu->obj = tex;
	e->o->texture = textu;
	free((char *)tmp);
	free(pts);
}

void		text_file(t_e *e)
{
	t_ptextu		*textu;
	const gchar		*tmp;
	t_point			*pts;
	t_texture		*tex;

	textu = NULL;
	pts = NULL;
	tex = NULL;
	if (!(textu = malloc(sizeof(t_ptextu))))
		malloc_fail("text_file");
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[22]));
	textu->refl_specu = (float)ft_atoi_double((char *)tmp);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[23]));
	textu->refl_diffuse = (float)ft_atoi_double((char *)tmp);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[30]));
	textu->refract = (float)ft_atoi_double((char *)tmp);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[14]));
	if (check_file((char *)tmp) == 0)
		tmp = "srcs/g_tk/bad_texture.png";
	if ((tex = import_png((char *)tmp)) == NULL)
		tex = import_png("srcs/g_tk/bad_texture.png");
	textu->type = PICTURE;
	textu->obj = tex;
	e->o->texture = textu;
}
