/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_addobjects_norm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 20:03:01 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/27 20:03:02 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"
#include "rt.h"

void		chose_id(gint id, t_e *e)
{
	if ((id == 2 || id == 1) && (e->idobj != 2))
		e->perlin = 1;
	if ((e->idobj == 2) && (id == 1 || id == 2) && e->perlin == 0)
	{
		e->idobj = 1;
		e->perlin = 1;
	}
	if (id == 0)
		text_color(e);
	if (id == 1)
		text_perlin(e);
	if (id == 2)
		text_file(e);
	if (id == 3)
		text_proced(e);
}

void		place_buttons_addsphere_norm(t_e *e)
{
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[0]),
		e->label_addsphere[5], e->label_addsphere[3], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[0]),
		e->entry_addsphere[5], e->label_addsphere[5], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid_addsphere[0]),
		e->button_addsphere[5], 1, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(e->grid_addsphere[0]),
		e->button_addsphere[0], 1, 8, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[0]),
		e->button_addsphere[1], e->button_addsphere[0], GTK_POS_RIGHT, 1, 1);
}

void		place_buttons_addsphere(t_e *e)
{
	gtk_grid_attach(GTK_GRID(\
		e->grid_addsphere[0]), e->img_addsphere, 0, 0, 4, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[0]),
		e->label_addsphere[0], e->img_addsphere, GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[0]),
		e->entry_addsphere[0], e->label_addsphere[0], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[0]),
		e->label_addsphere[1], e->label_addsphere[0], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[0]),
		e->entry_addsphere[1], e->label_addsphere[1], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[0]),
		e->label_addsphere[2], e->label_addsphere[1], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[0]),
		e->entry_addsphere[2], e->label_addsphere[2], GTK_POS_RIGHT, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[0]),
		e->label_addsphere[3], e->label_addsphere[2], GTK_POS_BOTTOM, 1, 1);
	gtk_grid_attach_next_to(GTK_GRID(e->grid_addsphere[0]),
		e->entry_addsphere[3], e->label_addsphere[3], GTK_POS_RIGHT, 1, 1);
	place_buttons_addsphere_norm(e);
}

void		choose_obj_type(t_e *e, t_obj *obj)
{
	if (e->idobj == 1)
		obj->type = SPHERE;
	else if (e->idobj == 2)
		obj->type = PLAN;
	else if (e->idobj == 3)
		obj->type = CONE;
	else if (e->idobj == 4)
		obj->type = CYLINDER;
}

void		*ft_realloc(void **ptr, size_t buff)
{
	void	*freshptr;

	if (!(freshptr = (void *)ft_memalloc(buff)))
		malloc_fail("ft_realloc");
	if (*ptr)
	{
		ft_memcpy(freshptr, *ptr, buff);
		ft_memdel(ptr);
	}
	return (freshptr);
}
