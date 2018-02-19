/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_addlight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:39:51 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/07 14:39:53 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"
#include "rt.h"

void		quitwindow_addlight(GtkWidget *button, t_e *e)
{
	button = NULL;
	gtk_widget_hide(e->window_addlight);
}

void		save_addlight(GtkWidget *button, t_e *e)
{
	const gchar		*text;
	t_light			*obj;
	t_color_light	*clight;
	GdkRGBA			rgba;

	clight = NULL;
	if (!(obj = light_init()))
		return ;
	text = gtk_entry_get_text(GTK_ENTRY(e->entry_addlight[0]));
	obj->name = (char*)text;
	if (!(clight = (t_color_light *)malloc(sizeof(t_color_light))))
		malloc_fail("save_addlight");
	gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(e->button_addlight[3]), &rgba);
	clight->x = rgba.red;
	clight->y = rgba.green;
	clight->z = rgba.blue;
	obj->color_light = clight;
	text = gtk_entry_get_text(GTK_ENTRY(e->entry_addlight[1]));
	obj->origin = extract_vector3d((char *)text);
	light_redim_push(e->glb->tab_light, obj);
	update_main_texture(e->glb);
	draw(e->glb, e);
	e->imagepb = gtk_image_new_from_pixbuf(e->pixbufrt);
	e->imagepbcpy = gtk_image_new_from_pixbuf(e->pixbufrtcpy);
	quitwindow_addlight(button, e);
}

void		place_buttons_addlight(t_e *e)
{
	gtk_grid_attach(GTK_GRID(e->grid_addlight), e->img_addlight, 0, 0, 2, 10);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addlight),
		e->button_addlight[0], e->img_addlight, GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addlight),
		e->button_addlight[1], e->button_addlight[0], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addlight),
		e->button_addlight[2], e->button_addlight[1], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addlight),
		e->button_addlight[3], e->button_addlight[2], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid_addlight),
		e->button_addlight[4], 0, 100, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addlight),
		e->button_addlight[5], e->button_addlight[4], GTK_POS_RIGHT, 1, 1);
}

void		place_texture_addlight(t_e *e)
{
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addlight),
		e->entry_addlight[0], e->button_addlight[0], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addlight),
		e->entry_addlight[1], e->button_addlight[1], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addlight),
		e->entry_addlight[2], e->button_addlight[2], GTK_POS_RIGHT, 1, 1);
}

void		create_addlight(t_e *e)
{
	int		i;

	i = 0;
	place_buttons_addlight(e);
	place_texture_addlight(e);
	g_signal_connect(e->button_addlight[4],
		"clicked", G_CALLBACK(quitwindow_addlight), e);
	g_signal_connect(e->button_addlight[5],
		"clicked", G_CALLBACK(save_addlight), e);
}
