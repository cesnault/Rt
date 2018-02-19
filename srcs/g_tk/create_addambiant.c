/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_addambiant.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:40:06 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/07 14:40:07 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"
#include "rt.h"

void		quitwindow_addambiant(GtkWidget *button, t_e *e)
{
	button = NULL;
	gtk_widget_hide(e->window_addambiant);
}

void		save_addambiant(GtkWidget *button, t_e *e)
{
	char *str;

	str = (char *)gtk_entry_get_text(GTK_ENTRY(e->entry_addambiant[0]));
	button = NULL;
	e->glb->setting->ambiant = ft_atoi_double(str);
	update_main_texture(e->glb);
	draw(e->glb, e);
	e->imagepb = gtk_image_new_from_pixbuf(e->pixbufrt);
	e->imagepbcpy = gtk_image_new_from_pixbuf(e->pixbufrtcpy);
	quitwindow_addambiant(button, e);
}

void		place_buttons_addambiant(t_e *e)
{
	gtk_grid_attach(GTK_GRID(e->grid_addambiant),
		e->img_addambiant, 0, 0, 2, 10);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addambiant),
		e->button_addambiant[0], e->img_addambiant, GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid_addambiant),
		e->button_addambiant[5], 0, 100, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addambiant),
		e->button_addambiant[4], e->button_addambiant[5], GTK_POS_RIGHT, 1, 1);
}

void		place_texture_addambiant(t_e *e)
{
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addambiant),
		e->entry_addambiant[0], e->button_addambiant[0], GTK_POS_RIGHT, 1, 1);
}

void		create_addambiant(t_e *e)
{
	int		i;

	i = 0;
	place_buttons_addambiant(e);
	place_texture_addambiant(e);
	g_signal_connect(e->button_addambiant[5], "clicked",
		G_CALLBACK(quitwindow_addambiant), e);
	g_signal_connect(e->button_addambiant[4], "clicked",
		G_CALLBACK(save_addambiant), e);
}
