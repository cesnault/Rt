/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_labels_addsphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 21:45:12 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/26 21:45:13 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		init_labels_addsphere_norm3(t_e *e)
{
	e->label_addsphere[24] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Specular</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[24]), TRUE);
	e->label_addsphere[25] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Diffuse</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[25]), TRUE);
	e->label_addsphere[26] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">  Texture name  </span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[26]), TRUE);
	e->label_addsphere[27] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Zoom</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[27]), TRUE);
	e->label_addsphere[28] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Refraction</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[28]), TRUE);
	e->label_addsphere[29] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Refraction</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[29]), TRUE);
	e->label_addsphere[30] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Refraction</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[30]), TRUE);
	e->label_addsphere[31] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Refraction</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[31]), TRUE);
}

void		init_labels_addsphere_norm2(t_e *e)
{
	e->label_addsphere[16] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Color</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[16]), TRUE);
	e->label_addsphere[17] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Perlin</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[17]), TRUE);
	e->label_addsphere[18] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Fichier</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[18]), TRUE);
	e->label_addsphere[19] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Procedural</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[19]), TRUE);
	e->label_addsphere[20] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Specular</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[20]), TRUE);
	e->label_addsphere[21] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Diffuse</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[21]), TRUE);
	e->label_addsphere[22] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Specular</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[22]), TRUE);
	e->label_addsphere[23] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Diffuse</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[23]), TRUE);
	init_labels_addsphere_norm3(e);
}

void		init_labels_addsphere_norm(t_e *e)
{
	e->label_addsphere[8] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Specular</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[8]), TRUE);
	e->label_addsphere[9] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Diffuse</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[9]), TRUE);
	e->label_addsphere[10] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Perlin Type</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[10]), TRUE);
	e->label_addsphere[11] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">  Texture name  </span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[11]), TRUE);
	e->label_addsphere[12] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Dimensions</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[12]), TRUE);
	e->label_addsphere[13] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Zoom</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[13]), TRUE);
	e->label_addsphere[14] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">  Picture  </span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[14]), TRUE);
	e->label_addsphere[15] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">  Type  </span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[15]), TRUE);
	init_labels_addsphere_norm2(e);
}

void		init_labels_addsphere(t_e *e)
{
	e->label_addsphere[0] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Name</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[0]), TRUE);
	e->label_addsphere[1] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Position</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[1]), TRUE);
	e->label_addsphere[2] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Rotation</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[2]), TRUE);
	e->label_addsphere[3] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Direction</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[3]), TRUE);
	e->label_addsphere[5] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Rey</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[5]), TRUE);
	e->label_addsphere[6] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">Texture type</span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[6]), TRUE);
	e->label_addsphere[7] = gtk_label_new(\
		"<span weight=\"bold\"size=\"large\">  Texture color  </span>");
	gtk_label_set_use_markup(GTK_LABEL(e->label_addsphere[7]), TRUE);
	init_labels_addsphere_norm(e);
}
