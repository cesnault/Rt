/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:57:13 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/07 14:57:14 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		quitwindow_render(GtkWidget *button, t_e *e)
{
	button = NULL;
	gtk_widget_hide(e->window_render);
}

void		save_render(GtkWidget *button, t_e *e)
{
	button = NULL;
	if (gtk_toggle_button_get_active(\
		GTK_TOGGLE_BUTTON(e->button_render[2])) == TRUE)
		e->glb->setting->sepia = 1;
	if (gtk_toggle_button_get_active(\
		GTK_TOGGLE_BUTTON(e->button_render[2])) == FALSE)
		e->glb->setting->sepia = 0;
	if (gtk_toggle_button_get_active(\
		GTK_TOGGLE_BUTTON(e->button_render[3])) == TRUE)
		e->glb->setting->stereo = 1;
	if (gtk_toggle_button_get_active(\
		GTK_TOGGLE_BUTTON(e->button_render[3])) == FALSE)
		e->glb->setting->stereo = 0;
	if (gtk_toggle_button_get_active(\
		GTK_TOGGLE_BUTTON(e->button_render[4])) == TRUE)
		e->glb->setting->antialia = 2;
	if (gtk_toggle_button_get_active(\
		GTK_TOGGLE_BUTTON(e->button_render[4])) == FALSE)
		e->glb->setting->antialia = 1;
	update_main_texture(e->glb);
	draw(e->glb, e);
	e->imagepb = gtk_image_new_from_pixbuf(e->pixbufrt);
	e->imagepbcpy = gtk_image_new_from_pixbuf(e->pixbufrtcpy);
	quitwindow_render(button, e);
}

void		place_objects_render(t_e *e)
{
	gtk_grid_attach(GTK_GRID(e->grid_render), e->img_render, 0, 0, 2, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_render),
		e->button_render[2], e->img_render, GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_render),
		e->button_render[3], e->button_render[2], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_render),
		e->button_render[4], e->button_render[3], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid_render), e->button_render[0], 0, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid_render), e->button_render[1], 1, 4, 1, 1);
}

void		create_render(t_e *e)
{
	place_objects_render(e);
	gtk_widget_show_all(e->window_render);
	gtk_window_set_modal(GTK_WINDOW(e->window_render), TRUE);
	g_signal_connect(e->button_render[0], "clicked",
		G_CALLBACK(quitwindow_render), e);
	g_signal_connect(e->button_render[1], "clicked",
		G_CALLBACK(save_render), e);
}
