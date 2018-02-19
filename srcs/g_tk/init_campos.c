/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_campos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:25:55 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/05 17:25:56 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		init_window_campos(t_e *e)
{
	e->window_campos = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(e->window_campos), "Camera_position");
	gtk_window_set_default_size(GTK_WINDOW(e->window_campos), 50, 50);
	gtk_window_set_deletable(GTK_WINDOW(e->window_campos), TRUE);
	gtk_window_set_resizable(GTK_WINDOW(e->window_campos), TRUE);
	gtk_window_set_decorated(GTK_WINDOW(e->window_campos), FALSE);
	gtk_window_set_position(GTK_WINDOW(e->window_campos), GTK_WIN_POS_MOUSE);
}

void		init_entry_campos(t_e *e)
{
	e->entry_campos[0] = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(e->entry_campos[0]), "0.0 0.0 0.0");
	e->entry_campos[1] = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(e->entry_campos[1]), "0.0 0.0 0.0");
	e->entry_campos[2] = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(e->entry_campos[2]), "0.0 0.0 0.0");
	e->button_campos[0] = gtk_button_new_with_label("Save");
	e->button_campos[1] = gtk_button_new_with_label("Cancel");
}

void		init_labels_campos(t_e *e)
{
	e->label_campos[0] = gtk_label_new(\
		"<span weight=\"bold\"size=\"xx-large\">CAMERA POSITION</span>");
	e->label_campos[1] = gtk_label_new(\
		"<span weight=\"bold\">Set Position (X ,Y, Z)</span>");
	e->label_campos[2] = gtk_label_new(\
		"Yttj");
	e->label_campos[3] = gtk_label_new(\
		"<span weight=\"bold\">Set Rotation (X ,Y, Z)</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_campos[0]), TRUE);
	gtk_label_set_use_markup(GTK_LABEL(e->label_campos[1]), TRUE);
	gtk_label_set_use_markup(GTK_LABEL(e->label_campos[3]), TRUE);
}

void		init_grid_campos(t_e *e)
{
	e->grid_campos = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(e->grid_campos), 5);
	gtk_grid_set_column_spacing(GTK_GRID(e->grid_campos), 5);
	gtk_container_add(\
		GTK_CONTAINER(e->window_campos), GTK_WIDGET(e->grid_campos));
}

void		init_campos(GtkWidget *button, t_e *e)
{
	button = NULL;
	init_window_campos(e);
	init_entry_campos(e);
	init_labels_campos(e);
	init_grid_campos(e);
	e->img_campos = gtk_image_new_from_file("img/camerapos.png");
	create_campos(e);
}
