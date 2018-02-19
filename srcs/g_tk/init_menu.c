/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:13:59 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/05 17:14:00 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "ft_ori.h"
#include "rt.h"
#include "gtkgui.h"

void		init_note_0(t_e *e)
{
	e->note[0] = gtk_notebook_new();
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->label[17], 0, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->entry[0], 1, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->label[18], 0, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->entry[18], 1, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->label[19], 0, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->entry[19], 1, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->label[20], 0, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->entry[20], 1, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->label[21], 0, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->entry[21], 1, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->label[22], 0, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[1]), e->entry[22], 1, 5, 1, 1);
	gtk_notebook_append_page(GTK_NOTEBOOK(e->note[0]),
		e->grid[1], e->label[12]);
	gtk_notebook_set_scrollable(GTK_NOTEBOOK(e->note[0]), TRUE);
	gtk_notebook_popup_enable(GTK_NOTEBOOK(e->note[0]));
	e->note[1] = gtk_notebook_new();
	e->ebox = gtk_event_box_new();
	e->eboxcpy = gtk_event_box_new();
}

void		init_window_0(t_e *e)
{
	int i;

	i = -1;
	e->window[0] = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	e->window[1] = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(e->window[1]), GTK_WIN_POS_MOUSE);
	gtk_window_set_title(GTK_WINDOW(e->window[0]), "- RT -");
	gtk_window_set_resizable(GTK_WINDOW(e->window[0]), TRUE);
	gtk_window_set_default_size(GTK_WINDOW(e->window[0]), 200, 800);
	gtk_window_set_decorated(GTK_WINDOW(e->window[0]), TRUE);
	gtk_window_set_decorated(GTK_WINDOW(e->window[1]), FALSE);
	gtk_window_move(GTK_WINDOW(e->window[0]), 500, 250);
	g_signal_connect(G_OBJECT(e->window[0]),
		"destroy", G_CALLBACK(quitmenu), e);
	while (++i <= 30)
		e->entry[i] = gtk_entry_new();
}

void		init_grid_0(t_e *e)
{
	e->grid[0] = gtk_grid_new();
	e->grid[1] = gtk_grid_new();
	e->grid[2] = gtk_grid_new();
	e->grid[3] = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(e->grid[0]), 5);
	gtk_grid_set_row_spacing(GTK_GRID(e->grid[1]), 5);
	gtk_grid_set_row_spacing(GTK_GRID(e->grid[2]), 1);
	gtk_grid_set_row_spacing(GTK_GRID(e->grid[3]), 1);
	gtk_grid_set_column_spacing(GTK_GRID(e->grid[0]), 5);
	gtk_grid_set_column_spacing(GTK_GRID(e->grid[1]), 5);
	gtk_grid_set_column_spacing(GTK_GRID(e->grid[2]), 1);
	gtk_grid_set_column_spacing(GTK_GRID(e->grid[3]), 1);
	gtk_container_add(GTK_CONTAINER(e->window[0]), GTK_WIDGET(e->grid[0]));
	gtk_container_add(GTK_CONTAINER(e->window[1]), GTK_WIDGET(e->grid[2]));
	gtk_grid_set_row_homogeneous(GTK_GRID(e->grid[0]), FALSE);
	gtk_grid_set_row_homogeneous(GTK_GRID(e->grid[1]), FALSE);
	gtk_grid_set_column_homogeneous(GTK_GRID(e->grid[0]), FALSE);
	gtk_grid_set_column_homogeneous(GTK_GRID(e->grid[1]), FALSE);
	gtk_grid_set_column_homogeneous(GTK_GRID(e->grid[2]), FALSE);
	gtk_grid_set_column_homogeneous(GTK_GRID(e->grid[3]), FALSE);
	gtk_grid_set_baseline_row(GTK_GRID(e->grid[0]), 0);
	gtk_grid_set_baseline_row(GTK_GRID(e->grid[1]), 0);
}

void		init_combobox_0(t_e *e)
{
	e->combo[0] = gtk_combo_box_text_new();
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(e->combo[0]), "Sphere");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(e->combo[0]), "Plan");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(e->combo[0]), "Cone");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(e->combo[0]), "Cylinder");
	gtk_combo_box_set_active(GTK_COMBO_BOX(e->combo[0]), 0);
	e->combo[1] = gtk_combo_box_text_new();
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(e->combo[1]),
		"Light Spot");
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(e->combo[1]),
		"Ambiant Light");
	gtk_combo_box_set_active(GTK_COMBO_BOX(e->combo[1]), 0);
}

void		init_button_0(t_e *e)
{
	e->renderover = gtk_image_new_from_file("img/renderdone.png");
	e->button[1] = gtk_button_new_with_label("Set Camera Position");
	e->button[2] = gtk_button_new_with_label("Add and object");
	e->button[3] = gtk_button_new_with_label("Add a light");
	e->button[4] = gtk_button_new_with_label("Open");
	e->button[5] = gtk_button_new_with_label("Save");
	e->button[6] = gtk_button_new_with_label("Quit");
	e->button[7] = gtk_button_new_with_label("Render options");
	e->button[8] = gtk_button_new_with_label("OK");
}
