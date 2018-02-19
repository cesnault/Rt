/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_addambiant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:40:14 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/07 14:40:15 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		init_window_addambiant(t_e *e)
{
	e->window_addambiant = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(e->window_addambiant), "addambiant");
	gtk_window_set_default_size(GTK_WINDOW(e->window_addambiant), 50, 50);
	gtk_window_set_deletable(GTK_WINDOW(e->window_addambiant), TRUE);
	gtk_window_set_resizable(GTK_WINDOW(e->window_addambiant), TRUE);
	gtk_window_set_decorated(GTK_WINDOW(e->window_addambiant), FALSE);
	gtk_window_set_position(\
		GTK_WINDOW(e->window_addambiant), GTK_WIN_POS_MOUSE);
	g_signal_connect(G_OBJECT(e->window_addambiant), "destroy",
		G_CALLBACK(gtk_main_quit), NULL);
}

void		init_entry_addambiant(t_e *e)
{
	int			i;
	char		*str;

	i = -1;
	while (++i <= 0)
		e->entry_addambiant[i] = gtk_entry_new();
	str = ft_ftoa(e->glb->setting->ambiant, 3);
	gtk_entry_set_text(GTK_ENTRY(e->entry_addambiant[0]),
		str);
	free(str);
}

void		init_buttons_addambiant(t_e *e)
{
	e->button_addambiant[0] = gtk_button_new_with_label("Value");
	e->button_addambiant[1] = gtk_button_new_with_label("Position");
	e->button_addambiant[2] = gtk_button_new_with_label("Light color");
	e->button_addambiant[3] = gtk_color_button_new();
	e->button_addambiant[4] = gtk_button_new_with_label("Save");
	e->button_addambiant[5] = gtk_button_new_with_label("Cancel");
	gtk_color_button_set_title(\
		GTK_COLOR_BUTTON(e->button_addambiant[3]), "Select object color");
}

void		init_grid_addambiant(t_e *e)
{
	e->grid_addambiant = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(e->grid_addambiant), 5);
	gtk_grid_set_column_spacing(GTK_GRID(e->grid_addambiant), 5);
	gtk_container_add(\
		GTK_CONTAINER(e->window_addambiant), GTK_WIDGET(e->grid_addambiant));
}

void		init_addambiant(t_e *e)
{
	e->img_addambiant = gtk_image_new_from_file("img/ambiant.png");
	init_window_addambiant(e);
	init_entry_addambiant(e);
	init_buttons_addambiant(e);
	init_grid_addambiant(e);
}
