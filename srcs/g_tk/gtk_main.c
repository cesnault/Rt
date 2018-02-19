/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtk_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 16:52:25 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/05 16:52:26 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		init_e(t_e *e, t_objl *o)
{
	e->ximg = 1100;
	e->yimg = 1100;
	init_window_0(e);
	init_grid_0(e);
	init_combobox_0(e);
	init_label_0(e);
	init_button_0(e);
	init_note_0(e);
	init_image_0(e);
	init_pixbuf_0(e);
	e->o = o;
}

void		init_o(t_objl *o)
{
	o->name = "name";
}

t_objl		*add_in_front(t_objl *o)
{
	t_objl *tmp;

	if (!(tmp = (t_objl *)malloc(sizeof(t_objl))))
		malloc_fail("add_in_front");
	init_o(tmp);
	tmp->next = o;
	return (tmp);
}

void		gtk_initialize(void)
{
	t_e		e;
	t_objl	*o;

	o = NULL;
	o = add_in_front(o);
	init_e(&e, o);
	create(&e);
	gtk_widget_show_all(e.window[0]);
}
