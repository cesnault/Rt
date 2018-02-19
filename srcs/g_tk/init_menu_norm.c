/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 22:59:39 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/24 22:59:41 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		init_label_0_norm(t_e *e)
{
	e->label[12] = gtk_label_new("Object");
	e->label[13] = gtk_label_new("Position");
	e->label[14] = gtk_label_new("Texture");
	e->label[15] = gtk_label_new("Rendu 1");
	e->label[16] = gtk_label_new("Rendu 2");
	e->label[17] = gtk_label_new("Object ID");
	e->label[18] = gtk_label_new("Position");
	e->label[19] = gtk_label_new("Rotation");
	e->label[20] = gtk_label_new("Direction");
	e->label[21] = gtk_label_new("Rey");
	e->label[22] = gtk_label_new("Name");
	e->label[23] = gtk_label_new("Render 2");
	e->label[24] = gtk_label_new("Render 1");
}

void		init_label_0(t_e *e)
{
	e->label[2] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">SCENE CREATOR</span>");
	e->label[4] = gtk_label_new("Default (0.0.0)");
	e->label[5] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">ADD STUFF TO YOUR SCENE</span>");
	e->label[6] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">LOAD AN EXISTING SCENE</span>");
	e->label[7] = gtk_label_new("scene_name");
	e->label[8] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\"> EDIT OBJECT</span>");
	e->label[9] = gtk_label_new("<span weight=\"bold\"></span>");
	e->label[10] = gtk_label_new("<span weight=\"bold\"></span>");
	e->label[11] = gtk_label_new("<span weight=\"bold\"></span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label[2]), TRUE);
	gtk_label_set_use_markup(GTK_LABEL(e->label[5]), TRUE);
	gtk_label_set_use_markup(GTK_LABEL(e->label[6]), TRUE);
	gtk_label_set_use_markup(GTK_LABEL(e->label[8]), TRUE);
	gtk_label_set_use_markup(GTK_LABEL(e->label[9]), TRUE);
	gtk_label_set_use_markup(GTK_LABEL(e->label[10]), TRUE);
	gtk_label_set_use_markup(GTK_LABEL(e->label[11]), TRUE);
	init_label_0_norm(e);
}
