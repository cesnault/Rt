/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_press_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:16:15 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/26 00:16:17 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		quit_confirm(GtkWidget *button, t_e *e)
{
	button = NULL;
	gtk_widget_hide(e->window[1]);
}

void		button_press_norm2(t_e *e, int i)
{
	char *str;
	char *str1;
	char *str2;
	char *str3;

	if (e->glb->tab_obj->all_obj[i]->dir)
	{
		str1 = ft_ftoa(e->glb->tab_obj->all_obj[i]->dir->x, 2);
		str2 = ft_ftoa(e->glb->tab_obj->all_obj[i]->dir->y, 2);
		str3 = ft_ftoa(e->glb->tab_obj->all_obj[i]->dir->z, 2);
		str = vectortoa((char *)str1, (char *)str2, (char *)str3);
		gtk_entry_set_text(GTK_ENTRY(e->entry[20]), str);
		free(str);
		free(str1);
		free(str2);
		free(str3);
	}
}

void		button_press_free(char *str1, char *str2, char *str3)
{
	free(str1);
	free(str2);
	free(str3);
	str1 = NULL;
	str2 = NULL;
	str3 = NULL;
}

void		color_free(t_color_light *obj)
{
	free(obj);
}
