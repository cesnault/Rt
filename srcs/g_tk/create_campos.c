/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_campos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:27:48 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/05 17:27:49 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"
#include "rt.h"

void		quitwindow_campos(GtkWidget *button, t_e *e)
{
	button = NULL;
	gtk_widget_hide(e->window_campos);
}

void		reset_pixbuf(t_e *e)
{
	int x;
	int y;

	x = -1;
	while (++x < e->glb->setting->dim.x)
	{
		y = 0;
		while (++y < e->glb->setting->dim.y)
			put_pixel(e, 0.0, 0.0, 0.0);
	}
}

void		save_campos(GtkWidget *button, t_e *e)
{
	t_cam		*cam;
	const gchar *text;

	cam = NULL;
	button = NULL;
	if (!(cam = malloc(sizeof(t_cam))))
		malloc_fail("save_campos");
	text = gtk_entry_get_text(GTK_ENTRY(e->entry_campos[0]));
	gtk_label_set_text(GTK_LABEL(e->label[4]), text);
	cam->origin = extract_vector3d((char*)text);
	text = gtk_entry_get_text(GTK_ENTRY(e->entry_campos[1]));
	cam->rot = extract_vector3d((char*)text);
	text = "0.0 0.0 0.0";
	cam->dir = extract_vector3d((char*)text);
	free(e->glb->cam->origin);
	free(e->glb->cam->rot);
	free(e->glb->cam->dir);
	free(e->glb->cam);
	e->glb->cam = cam;
	update_main_texture(e->glb);
	reset_pixbuf(e);
	draw(e->glb, e);
	e->imagepb = gtk_image_new_from_pixbuf(e->pixbufrt);
	e->imagepbcpy = gtk_image_new_from_pixbuf(e->pixbufrtcpy);
	quitwindow_campos(button, e);
}

void		place_objects_campos(t_e *e)
{
	gtk_grid_attach(GTK_GRID(e->grid_campos), e->img_campos, 0, 0, 2, 4);
	gtk_grid_attach(GTK_GRID(e->grid_campos), e->label_campos[1], 0, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid_campos), e->entry_campos[0], 1, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid_campos), e->button_campos[0], 1, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid_campos), e->button_campos[1], 0, 7, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_campos), e->label_campos[3],
		e->label_campos[1], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_campos), e->entry_campos[1],
		e->entry_campos[0], GTK_POS_BOTTOM, 1, 1);
}

void		create_campos(t_e *e)
{
	place_objects_campos(e);
	g_signal_connect(GTK_BUTTON(e->button_campos[0]), "clicked",
		G_CALLBACK(save_campos), e);
	g_signal_connect(GTK_BUTTON(e->button_campos[1]), "clicked",
		G_CALLBACK(quitwindow_campos), e);
	gtk_widget_show_all(e->window_campos);
	gtk_window_set_modal(GTK_WINDOW(e->window_campos), TRUE);
}
