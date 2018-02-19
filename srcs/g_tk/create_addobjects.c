/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_addobjects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:29:19 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/14 03:57:59 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"
#include "rt.h"

void			quitwindow_addsphere(GtkWidget *button, t_e *e)
{
	button = NULL;
	gtk_widget_destroy(e->img_addsphere);
	gtk_widget_hide(e->window_addsphere);
}

t_color_light	*copy_clight(t_e *e)
{
	t_color_light	*clight;
	GdkRGBA			rgba;

	if (!(clight = (t_color_light *)malloc(sizeof(t_color_light))))
		malloc_fail("copy_clight");
	gtk_color_chooser_get_rgba(\
		GTK_COLOR_CHOOSER(e->button_addsphere[2]), &rgba);
	clight->x = rgba.red;
	clight->y = rgba.green;
	clight->z = rgba.blue;
	e->o->color_light = clight;
	return (clight);
}

void			save_addsphere(GtkWidget *button, t_e *e)
{
	gint			id;
	t_obj			*obj;

	if (!(obj = obj_init()))
		return ;
	id = gtk_notebook_get_current_page(GTK_NOTEBOOK(e->notebook_addsphere));
	save_standart(e);
	chose_id(id, e);
	copy_in_obj(e, obj);
	obj_redim_push(e->glb->tab_obj, obj);
	if (gtk_toggle_button_get_active(\
		GTK_TOGGLE_BUTTON(e->button_addsphere[5])) == FALSE)
		tir_push_value(e->glb->pos_obj, obj->id);
	if (gtk_toggle_button_get_active(\
		GTK_TOGGLE_BUTTON(e->button_addsphere[5])) == TRUE)
		tir_push_value(e->glb->neg_obj, obj->id);
	update_main_texture(e->glb);
	draw(e->glb, e);
	e->imagepb = gtk_image_new_from_pixbuf(e->pixbufrt);
	e->imagepbcpy = gtk_image_new_from_pixbuf(e->pixbufrtcpy);
	quitwindow_addsphere(button, e);
}

void			place_texture_addsphere(t_e *e)
{
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[0]), "NAME");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[1]), "0.0 0.0 200.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[2]), "0.0 0.0 0.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[3]), "0.0 0.0 0.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[5]), "15.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[8]), "0.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[9]), "1.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[11]), "TEXTURE NAME");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[13]), "15.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[14]), "img/jimmy.png");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[20]), "0.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[21]), "1.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[22]), "0.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[23]), "1.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[24]), "0.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[25]), "1.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[27]), "1.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[28]), "1.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[29]), "1.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[30]), "1.0");
	gtk_entry_set_text(GTK_ENTRY(e->entry_addsphere[31]), "1.0");
	gtk_grid_attach(GTK_GRID(e->grid_addsphere[0]),
		e->notebook_addsphere, 2, 1, 1, 6);
}

void			create_addsphere(t_e *e)
{
	int		i;

	i = 0;
	place_texture_addsphere(e);
	place_buttons_addsphere(e);
	g_signal_connect(e->button_addsphere[0], "clicked",
		G_CALLBACK(quitwindow_addsphere), e);
	g_signal_connect(e->button_addsphere[1], "clicked",
		G_CALLBACK(save_addsphere), e);
}
