/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_addlight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:39:44 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/07 14:39:45 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		init_window_addlight(t_e *e)
{
	e->window_addlight = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(e->window_addlight), "addlight");
	gtk_window_set_default_size(GTK_WINDOW(e->window_addlight), 200, 200);
	gtk_window_set_deletable(GTK_WINDOW(e->window_addlight), TRUE);
	gtk_window_set_resizable(GTK_WINDOW(e->window_addlight), TRUE);
	gtk_window_set_decorated(GTK_WINDOW(e->window_addlight), FALSE);
	gtk_window_set_position(GTK_WINDOW(e->window_addlight), GTK_WIN_POS_MOUSE);
	g_signal_connect(G_OBJECT(e->window_addlight), "destroy",
		G_CALLBACK(gtk_main_quit), NULL);
}

void		init_entry_addlight(t_e *e)
{
	int		i;

	i = -1;
	while (++i <= 4)
		e->entry_addlight[i] = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(e->entry_addlight[0]), "Light_Name");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addlight[1]), "0.0 0.0 0.0");
	e->label_addlight[0] = gtk_label_new(\
		"<span weight=\"bold\"size=\"xx-large\">	        LIGHT</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addlight[0]), TRUE);
}

void		init_buttons_addlight(t_e *e)
{
	e->button_addlight[0] = gtk_button_new_with_label("Name");
	e->button_addlight[1] = gtk_button_new_with_label("Position");
	e->button_addlight[2] = gtk_button_new_with_label("Light color");
	e->button_addlight[3] = gtk_color_button_new();
	e->button_addlight[4] = gtk_button_new_with_label("Cancel");
	e->button_addlight[5] = gtk_button_new_with_label("Save");
	gtk_color_button_set_title(\
		GTK_COLOR_BUTTON(e->button_addlight[3]), "Select object color");
}

void		init_grid_addlight(t_e *e)
{
	e->grid_addlight = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(e->grid_addlight), 5);
	gtk_grid_set_column_spacing(GTK_GRID(e->grid_addlight), 5);
	gtk_container_add(\
		GTK_CONTAINER(e->window_addlight), GTK_WIDGET(e->grid_addlight));
}

void		init_addlight(t_e *e)
{
	init_window_addlight(e);
	init_entry_addlight(e);
	init_buttons_addlight(e);
	e->img_addlight = gtk_image_new_from_file("img/add_light.png");
	init_grid_addlight(e);
}
