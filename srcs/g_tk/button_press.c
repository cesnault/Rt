/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 00:15:10 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/14 03:36:50 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		button_press_norm3(t_e *e, char *str, int i)
{
	gtk_entry_set_text(GTK_ENTRY(e->entry[i]), str);
	free(str);
}

void		button_press_norm(t_e *e, int i)
{
	char *str;
	char *str1;
	char *str2;
	char *str3;

	if (e->glb->tab_obj->all_obj[i]->origin)
	{
		str1 = ft_ftoa(e->glb->tab_obj->all_obj[i]->origin->x, 2);
		str2 = ft_ftoa(e->glb->tab_obj->all_obj[i]->origin->y, 2);
		str3 = ft_ftoa(e->glb->tab_obj->all_obj[i]->origin->z, 2);
		str = vectortoa((char *)str1, (char *)str2, (char *)str3);
		button_press_free(str1, str2, str3);
	}
	if (e->glb->tab_obj->all_obj[i]->rot)
	{
		button_press_norm3(e, str, 18);
		str1 = ft_ftoa(e->glb->tab_obj->all_obj[i]->rot->x, 2);
		str2 = ft_ftoa(e->glb->tab_obj->all_obj[i]->rot->y, 2);
		str3 = ft_ftoa(e->glb->tab_obj->all_obj[i]->rot->z, 2);
		str = vectortoa((char *)str1, (char *)str2, (char *)str3);
		gtk_entry_set_text(GTK_ENTRY(e->entry[19]), str);
		button_press_free(str1, str2, str3);
	}
	free(str);
	button_press_norm2(e, i);
}

void		button_press(GtkWidget *button, GdkEventButton *event, t_e *e)
{
	int		id;
	int		i;
	char	*str_itoa;

	button = NULL;
	id = get_id_with_ray((int)event->x, (int)event->y, e->glb);
	e->id = id;
	str_itoa = ft_itoa(id);
	gtk_entry_set_text(GTK_ENTRY(e->entry[0]), str_itoa);
	free(str_itoa);
	if (id != -1)
	{
		i = 0;
		e->mousex = (int)event->x;
		e->mousey = (int)event->y;
		while (e->glb->tab_obj->all_obj[i]->id != id)
			i++;
		str_itoa = ft_itoa((int)e->glb->tab_obj->all_obj[i]->rey);
		button_press_norm3(e, str_itoa, 21);
		str_itoa = (e->glb->tab_obj->all_obj[i]->name);
		gtk_entry_set_text(GTK_ENTRY(e->entry[22]),
			str_itoa);
		button_press_norm(e, i);
	}
}

void		update_draw(t_e *e)
{
	update_main_texture(e->glb);
	draw(e->glb, e);
}

void		save_in_file(GtkWidget *button, t_e *e)
{
	int				i;
	const	gchar	*str;

	i = 0;
	button = NULL;
	if (e->id > -1)
	{
		while (e->glb->tab_obj->all_obj[i]->id != e->id)
			i++;
		str = gtk_entry_get_text(GTK_ENTRY(e->entry[18]));
		free(e->glb->tab_obj->all_obj[i]->origin);
		e->glb->tab_obj->all_obj[i]->origin = extract_vector3d((char *)str);
		str = gtk_entry_get_text(GTK_ENTRY(e->entry[19]));
		free(e->glb->tab_obj->all_obj[i]->rot);
		e->glb->tab_obj->all_obj[i]->rot = extract_vector3d((char *)str);
		str = gtk_entry_get_text(GTK_ENTRY(e->entry[20]));
		free(e->glb->tab_obj->all_obj[i]->dir);
		e->glb->tab_obj->all_obj[i]->dir = extract_vector3d((char *)str);
		str = gtk_entry_get_text(GTK_ENTRY(e->entry[21]));
		e->glb->tab_obj->all_obj[i]->rey = ft_atoi_double(str);
		update_draw(e);
		e->imagepb = gtk_image_new_from_pixbuf(e->pixbufrt);
		e->imagepbcpy = gtk_image_new_from_pixbuf(e->pixbufrtcpy);
	}
	gtk_widget_show_all(e->window[1]);
}
