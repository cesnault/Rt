/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:57:06 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/07 14:57:07 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		init_window_render(t_e *e)
{
	e->window_render = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(e->window_render), "Render options");
	gtk_window_set_default_size(GTK_WINDOW(e->window_render), 100, 100);
	gtk_window_set_deletable(GTK_WINDOW(e->window_render), TRUE);
	gtk_window_set_resizable(GTK_WINDOW(e->window_render), TRUE);
	gtk_window_set_decorated(GTK_WINDOW(e->window_render), FALSE);
	gtk_window_set_position(GTK_WINDOW(e->window_render), GTK_WIN_POS_MOUSE);
}

void		init_buttons_render(t_e *e)
{
	e->button_render[0] = gtk_button_new_with_label("Quit");
	e->button_render[1] = gtk_button_new_with_label("Save");
	e->button_render[2] = gtk_check_button_new_with_label("Sepia");
	e->button_render[3] = gtk_check_button_new_with_label("Stereoscopique");
	e->button_render[4] = gtk_check_button_new_with_label("Antialiasing");
}

void		init_grid_render(t_e *e)
{
	e->grid_render = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(e->grid_render), 5);
	gtk_grid_set_column_spacing(GTK_GRID(e->grid_render), 5);
	gtk_container_add(\
		GTK_CONTAINER(e->window_render), GTK_WIDGET(e->grid_render));
}

void		init_render(GtkWidget *button, t_e *e)
{
	button = NULL;
	init_window_render(e);
	init_buttons_render(e);
	init_grid_render(e);
	e->img_render = gtk_image_new_from_file("img/renderoptions.png");
	create_render(e);
}
