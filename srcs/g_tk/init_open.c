/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:49:11 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/14 04:44:23 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		init_window_open(t_e *e)
{
	e->window_open = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(e->window_open), "Open file");
	gtk_window_set_default_size(GTK_WINDOW(e->window_open), 200, 200);
	gtk_window_set_deletable(GTK_WINDOW(e->window_open), TRUE);
	gtk_window_set_resizable(GTK_WINDOW(e->window_open), TRUE);
	gtk_window_set_decorated(GTK_WINDOW(e->window_open), FALSE);
	gtk_window_set_position(GTK_WINDOW(e->window_open), GTK_WIN_POS_MOUSE);
}

void		init_labels_open(t_e *e)
{
	e->label_open[0] = gtk_label_new(\
		"<span weight=\"bold\"size=\"xx-large\"> CHOSE A SCENE </span>");
	e->label_open[1] = gtk_label_new("");
	gtk_label_set_use_markup(GTK_LABEL(e->label_open[0]), TRUE);
}

void		init_buttons_open(t_e *e)
{
	struct dirent	*file;

	e->dir = opendir("./scenes");
	if (e->dir == NULL)
	{
		perror("");
		return ;
	}
	e->ifichier = 2;
	e->button_open[0] = gtk_button_new_with_label("Save");
	e->button_open[1] = gtk_button_new_with_label("Cancel");
	while ((file = readdir(e->dir)) != NULL)
	{
		e->button_open[e->ifichier] = gtk_button_new_with_label(file->d_name);
		e->ifichier++;
	}
	closedir(e->dir);
}

void		init_grid_open(t_e *e)
{
	e->grid_open = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(e->grid_open), 5);
	gtk_grid_set_column_spacing(GTK_GRID(e->grid_open), 5);
	gtk_grid_set_column_homogeneous(GTK_GRID(e->grid_open), TRUE);
	gtk_container_add(GTK_CONTAINER(e->window_open), GTK_WIDGET(e->grid_open));
}

void		init_open(GtkWidget *button, t_e *e)
{
	button = e->button[0];
	init_window_open(e);
	init_labels_open(e);
	init_buttons_open(e);
	init_grid_open(e);
	e->img_open = gtk_image_new_from_file("img/openscene.png");
	create_open(e);
}
