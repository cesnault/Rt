/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:49:20 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/14 05:00:47 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"
#include "rt.h"

void			quitwindow_open(GtkWidget *button, t_e *e)
{
	button = e->button_open[1];
	gtk_widget_hide(e->window_open);
}

void			place_objects_open(t_e *e)
{
	int		i;
	int		j;

	i = e->ifichier;
	j = 5;
	gtk_grid_attach(GTK_GRID(e->grid_open), e->img_open, 0, 0, 1, 10);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_open), e->label_open[1],
		e->img_open, GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid_open), e->button_open[1], 0, 9999, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_open), e->button_open[4],
		e->label_open[1], GTK_POS_BOTTOM, 1, 1);
	while (j < i)
	{
		gtk_grid_attach_next_to(GTK_GRID(e->grid_open), e->button_open[j],
			e->button_open[j - 1], GTK_POS_BOTTOM, 1, 1);
		j++;
	}
}

void			create_open(t_e *e)
{
	int i;

	i = e->ifichier;
	place_objects_open(e);
	g_signal_connect(e->button_open[0], "clicked",
		G_CALLBACK(quitwindow_open), e);
	g_signal_connect(e->button_open[1], "clicked",
		G_CALLBACK(quitwindow_open), e);
	while (i-- > 4)
	{
		g_signal_connect(e->button_open[i], "clicked",
			G_CALLBACK(save_open), e);
	}
	gtk_widget_show_all(e->window_open);
	gtk_window_set_modal(GTK_WINDOW(e->window_open), TRUE);
}
