/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:21:25 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/05 17:21:26 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "ft_ori.h"
#include "rt.h"
#include "gtkgui.h"

void		attach_addobjects_norm(t_e *e)
{
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->button[3], 0, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->combo[1], 1, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->label[6], 0, 10, 2, 1);
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->button[4], 0, 11, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid[0]), e->label[7],
		e->button[4], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->label[8], 0, 12, 2, 1);
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->note[0], 0, 13, 2, 1);
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->button[5], 0, 49, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid[0]), e->button[6],
		e->button[5], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[2]), e->renderover, 0, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[2]), e->button[8], 0, 1, 1, 1);
}

void		attach_addobjects(t_e *e)
{
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->image, 0, 0, 2, 1);
	gtk_container_add(GTK_CONTAINER(e->ebox), GTK_WIDGET(e->imagepb));
	gtk_container_add(GTK_CONTAINER(e->eboxcpy), GTK_WIDGET(e->imagepbcpy));
	gtk_notebook_append_page(GTK_NOTEBOOK(e->note[1]), e->ebox, e->label[24]);
	gtk_notebook_append_page(GTK_NOTEBOOK(e->note[1]),
		e->eboxcpy, e->label[23]);
	gtk_grid_attach_next_to(GTK_GRID(e->grid[0]), e->note[1], e->image,
		GTK_POS_RIGHT, 50, 50);
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->label[2], 0, 1, 2, 1);
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->button[1], 0, 4, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid[0]), e->label[4],
		e->button[1], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid[0]), e->button[7],
		e->button[1], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->label[5], 0, 6, 2, 1);
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->button[2], 0, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid[0]), e->combo[0], 1, 8, 1, 1);
	attach_addobjects_norm(e);
}

void		choose_addobject(GtkWidget *button, t_e *e)
{
	gchar	*text;

	button = e->button[2];
	text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(e->combo[0]));
	if (text == NULL)
		return ;
	else if (ft_strcmp(text, "Sphere") == 0)
		e->idobj = 1;
	else if (ft_strcmp(text, "Plan") == 0)
		e->idobj = 2;
	else if (ft_strcmp(text, "Cone") == 0)
		e->idobj = 3;
	else if (ft_strcmp(text, "Cylinder") == 0)
		e->idobj = 4;
	free(text);
	create_add_sphere(e);
}

void		quitmenu(GtkWidget *button, t_e *e)
{
	t_objl *tmp;

	while (e->o->next)
	{
		tmp = e->o;
		e->o = e->o->next;
		free(tmp);
	}
	free(e->o);
	button = NULL;
	glb_free(e->glb);
	gtk_widget_destroy(e->imagepb);
	gtk_widget_destroy(e->imagepbcpy);
	gtk_main_quit();
}

void		create(t_e *e)
{
	e->id = -1;
	e->perlin = 0;
	attach_addobjects(e);
	g_signal_connect(e->button[1], "clicked", G_CALLBACK(init_campos), e);
	g_signal_connect(e->button[2], "clicked", G_CALLBACK(choose_addobject), e);
	g_signal_connect(e->button[3], "clicked", G_CALLBACK(choose_addlight), e);
	g_signal_connect(e->button[4], "clicked", G_CALLBACK(init_open), e);
	g_signal_connect(e->button[5], "clicked", G_CALLBACK(save_in_file), e);
	g_signal_connect(e->button[6], "clicked", G_CALLBACK(quitmenu), e);
	g_signal_connect(e->button[7], "clicked", G_CALLBACK(init_render), e);
	g_signal_connect(e->button[8], "clicked", G_CALLBACK(quit_confirm), e);
	g_signal_connect(G_OBJECT(e->ebox), "button_press_event",
		G_CALLBACK(button_press), e);
	g_signal_connect(G_OBJECT(e->eboxcpy), "button_press_event",
		G_CALLBACK(button_press), e);
}
