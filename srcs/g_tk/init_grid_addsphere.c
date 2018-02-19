/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid_addsphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 21:57:06 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/26 21:57:07 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		init_grid_addsphere_norm4(t_e *e)
{
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[4]),
		e->label_addsphere[25], e->label_addsphere[24], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[4]),
		e->entry_addsphere[25], e->label_addsphere[25], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[4]),
		e->label_addsphere[31], e->label_addsphere[25], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[4]),
		e->entry_addsphere[31], e->label_addsphere[31], GTK_POS_RIGHT, 1, 1);
	gtk_grid_set_row_homogeneous(GTK_GRID(e->grid_addsphere[4]), FALSE);
	gtk_grid_set_column_homogeneous(GTK_GRID(e->grid_addsphere[4]), TRUE);
	gtk_notebook_append_page(GTK_NOTEBOOK(e->notebook_addsphere),
		e->grid_addsphere[4], e->label_addsphere[19]);
}

void		init_grid_addsphere_norm3(t_e *e)
{
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[3]),
		e->entry_addsphere[22], e->label_addsphere[22], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[3]),
		e->label_addsphere[23], e->label_addsphere[22], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[3]),
		e->entry_addsphere[23], e->label_addsphere[23], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[3]),
		e->label_addsphere[30], e->label_addsphere[23], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[3]),
		e->entry_addsphere[30], e->label_addsphere[30], GTK_POS_RIGHT, 1, 1);
	gtk_grid_set_row_homogeneous(GTK_GRID(e->grid_addsphere[3]), FALSE);
	gtk_grid_set_column_homogeneous(GTK_GRID(e->grid_addsphere[3]), TRUE);
	gtk_notebook_append_page(GTK_NOTEBOOK(\
		e->notebook_addsphere), e->grid_addsphere[3], e->label_addsphere[18]);
	gtk_grid_attach(GTK_GRID(e->grid_addsphere[4]),
		e->label_addsphere[15], 0, 0, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[4]),
		e->combo_addsphere[1], e->label_addsphere[15], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[4]),
		e->label_addsphere[24], e->label_addsphere[15], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[4]),
		e->entry_addsphere[24], e->label_addsphere[24], GTK_POS_RIGHT, 1, 1);
	init_grid_addsphere_norm4(e);
}

void		init_grid_addsphere_norm2(t_e *e)
{
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[2]),
		e->entry_addsphere[21], e->label_addsphere[21], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[2]),
		e->label_addsphere[29], e->label_addsphere[21], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[2]),
		e->entry_addsphere[29], e->label_addsphere[29], GTK_POS_RIGHT, 1, 1);
	gtk_grid_set_row_homogeneous(GTK_GRID(e->grid_addsphere[2]), FALSE);
	gtk_grid_set_column_homogeneous(GTK_GRID(e->grid_addsphere[2]), TRUE);
	gtk_notebook_append_page(GTK_NOTEBOOK(e->notebook_addsphere),
		e->grid_addsphere[2], e->label_addsphere[17]);
	gtk_grid_attach(GTK_GRID(e->grid_addsphere[3]),
		e->label_addsphere[14], 0, 0, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[3]),
		e->entry_addsphere[14], e->label_addsphere[14], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[3]),
		e->label_addsphere[26], e->label_addsphere[14], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[3]),
		e->entry_addsphere[26], e->label_addsphere[26], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[3]),
		e->label_addsphere[27], e->label_addsphere[26], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[3]),
		e->entry_addsphere[27], e->label_addsphere[27], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[3]),
		e->label_addsphere[22], e->label_addsphere[27], GTK_POS_BOTTOM, 1, 1);
	init_grid_addsphere_norm3(e);
}

void		init_grid_addsphere_norm(t_e *e)
{
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[1]),
		e->entry_addsphere[28], e->label_addsphere[28], GTK_POS_RIGHT, 1, 1);
	gtk_grid_set_row_homogeneous(GTK_GRID(e->grid_addsphere[1]), FALSE);
	gtk_grid_set_column_homogeneous(GTK_GRID(e->grid_addsphere[1]), TRUE);
	gtk_notebook_append_page(GTK_NOTEBOOK(e->notebook_addsphere),
		e->grid_addsphere[1], e->label_addsphere[16]);
	gtk_grid_attach(GTK_GRID(e->grid_addsphere[2]),
		e->label_addsphere[10], 0, 0, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[2]),
		e->combo_addsphere[0], e->label_addsphere[10], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[2]),
		e->label_addsphere[11], e->label_addsphere[10], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[2]),
		e->entry_addsphere[11], e->label_addsphere[11], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[2]),
		e->label_addsphere[13], e->label_addsphere[11], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[2]),
		e->entry_addsphere[13], e->label_addsphere[13], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[2]),
		e->label_addsphere[20], e->label_addsphere[13], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[2]),
		e->entry_addsphere[20], e->label_addsphere[20], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[2]),
		e->label_addsphere[21], e->label_addsphere[20], GTK_POS_BOTTOM, 1, 1);
	init_grid_addsphere_norm2(e);
}

void		init_grid_addsphere(t_e *e)
{
	e->grid_addsphere[0] = gtk_grid_new();
	e->grid_addsphere[1] = gtk_grid_new();
	e->grid_addsphere[2] = gtk_grid_new();
	e->grid_addsphere[3] = gtk_grid_new();
	e->grid_addsphere[4] = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(e->grid_addsphere[0]), 5);
	gtk_grid_set_column_spacing(GTK_GRID(e->grid_addsphere[0]), 5);
	gtk_container_add(GTK_CONTAINER(e->window_addsphere),
		GTK_WIDGET(e->grid_addsphere[0]));
	e->notebook_addsphere = gtk_notebook_new();
	gtk_grid_attach(GTK_GRID(e->grid_addsphere[1]),
		e->label_addsphere[7], 0, 0, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[1]),
		e->button_addsphere[3], e->label_addsphere[7], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[1]),
		e->label_addsphere[8], e->label_addsphere[7], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[1]),
		e->entry_addsphere[8], e->label_addsphere[8], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[1]),
		e->label_addsphere[9], e->label_addsphere[8], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[1]),
		e->entry_addsphere[9], e->label_addsphere[9], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[1]),
		e->label_addsphere[28], e->label_addsphere[9], GTK_POS_BOTTOM, 1, 1);
	init_grid_addsphere_norm(e);
}
