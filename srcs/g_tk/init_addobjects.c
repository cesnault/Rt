/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_addobjects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:29:11 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/07 14:29:13 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		init_window_addsphere(t_e *e)
{
	int i;

	e->window_addsphere = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(e->window_addsphere), "ADDOBJECT");
	gtk_window_set_default_size(GTK_WINDOW(e->window_addsphere), 300, 300);
	gtk_window_set_deletable(GTK_WINDOW(e->window_addsphere), TRUE);
	gtk_window_set_resizable(GTK_WINDOW(e->window_addsphere), FALSE);
	gtk_window_set_decorated(GTK_WINDOW(e->window_addsphere), FALSE);
	gtk_window_set_position(GTK_WINDOW(e->window_addsphere), GTK_WIN_POS_MOUSE);
	g_signal_connect(G_OBJECT(e->window_addsphere), "destroy",
		G_CALLBACK(gtk_main_quit), NULL);
	i = -1;
	while (++i <= 40)
		e->entry_addsphere[i] = gtk_entry_new();
}

void		init_buttons_addsphere(t_e *e)
{
	e->button_addsphere[0] = gtk_button_new_with_label("Quit");
	e->button_addsphere[1] = gtk_button_new_with_label("Save");
	e->button_addsphere[2] = gtk_color_button_new();
	e->button_addsphere[3] = gtk_color_button_new();
	gtk_color_button_set_title(GTK_COLOR_BUTTON(\
		e->button_addsphere[3]), "Select light color");
	e->button_addsphere[4] = gtk_button_new_with_label("Update texture type");
	e->button_addsphere[5] = gtk_toggle_button_new_with_label("Negatif");
	e->combo_addsphere[0] = gtk_combo_box_text_new();
	gtk_combo_box_text_append_text(\
		GTK_COMBO_BOX_TEXT(e->combo_addsphere[0]), "SMOOTH");
	gtk_combo_box_text_append_text(\
		GTK_COMBO_BOX_TEXT(e->combo_addsphere[0]), "WOOD");
	gtk_combo_box_text_append_text(\
		GTK_COMBO_BOX_TEXT(e->combo_addsphere[0]), "MARBLE");
	gtk_combo_box_set_active(GTK_COMBO_BOX(e->combo_addsphere[0]), 0);
	e->combo_addsphere[1] = gtk_combo_box_text_new();
	gtk_combo_box_text_append_text(\
		GTK_COMBO_BOX_TEXT(e->combo_addsphere[1]), "Damier 2D");
	gtk_combo_box_text_append_text(\
		GTK_COMBO_BOX_TEXT(e->combo_addsphere[1]), "Damier 3D");
	gtk_combo_box_set_active(GTK_COMBO_BOX(e->combo_addsphere[1]), 0);
}

void		init_addsphere(t_e *e)
{
	init_window_addsphere(e);
	init_labels_addsphere(e);
	init_buttons_addsphere(e);
	init_grid_addsphere(e);
	if (e->idobj == 1)
		e->img_addsphere = gtk_image_new_from_file("img/add_sphere.png");
	else if (e->idobj == 2)
		e->img_addsphere = gtk_image_new_from_file("img/add_plan.png");
	else if (e->idobj == 3)
		e->img_addsphere = gtk_image_new_from_file("img/add_cone.png");
	else if (e->idobj == 4)
		e->img_addsphere = gtk_image_new_from_file("img/add_cylinder.png");
	else if (e->idobj == 5)
		e->img_addsphere = gtk_image_new_from_file("img/add_cube.png");
	else if (e->idobj == 6)
		e->img_addsphere = gtk_image_new_from_file("img/add_rectangle.png");
	else if (e->idobj == 7)
		e->img_addsphere = gtk_image_new_from_file("img/add_elipsoid.png");
	else if (e->idobj == 8)
		e->img_addsphere = gtk_image_new_from_file("img/add_pyramid.png");
}
