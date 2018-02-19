/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_add_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:29:49 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/07 14:29:50 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		create_add_sphere(t_e *e)
{
	init_addsphere(e);
	create_addsphere(e);
	gtk_widget_show_all(e->window_addsphere);
	gtk_window_set_modal(GTK_WINDOW(e->window_addsphere), TRUE);
}

void		create_add_light(t_e *e)
{
	init_addlight(e);
	create_addlight(e);
	gtk_widget_show_all(e->window_addlight);
	gtk_window_set_modal(GTK_WINDOW(e->window_addlight), TRUE);
}

void		create_add_ambiant(t_e *e)
{
	init_addambiant(e);
	create_addambiant(e);
	gtk_widget_show_all(e->window_addambiant);
	gtk_window_set_modal(GTK_WINDOW(e->window_addambiant), TRUE);
}

void		choose_addlight(GtkWidget *button, t_e *e)
{
	gchar	*text;

	button = e->button[3];
	text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(e->combo[1]));
	if (text == NULL)
		return ;
	else if (ft_strcmp(text, "Light Spot") == 0)
		create_add_light(e);
	else if (ft_strcmp(text, "Ambiant Light") == 0)
		create_add_ambiant(e);
	free(text);
}
