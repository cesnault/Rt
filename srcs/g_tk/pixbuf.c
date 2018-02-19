/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixbuf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:03:40 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/07 15:03:41 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void		put_pixel_cpy(t_e *e, guchar red,
	guchar green, guchar blue)
{
	int		rowstride;
	int		n_channels;
	guchar	*pixels;
	guchar	*p;

	n_channels = gdk_pixbuf_get_n_channels(e->pixbufrtcpy);
	g_assert(gdk_pixbuf_get_colorspace(e->pixbufrtcpy) == GDK_COLORSPACE_RGB);
	g_assert(gdk_pixbuf_get_bits_per_sample(e->pixbufrtcpy) == 8);
	g_assert(gdk_pixbuf_get_has_alpha(e->pixbufrtcpy));
	g_assert(n_channels == 4);
	e->width = gdk_pixbuf_get_width(e->pixbufrtcpy);
	e->height = gdk_pixbuf_get_height(e->pixbufrtcpy);
	rowstride = gdk_pixbuf_get_rowstride(e->pixbufrtcpy);
	pixels = gdk_pixbuf_get_pixels(e->pixbufrtcpy);
	p = pixels + e->y * rowstride + e->x * n_channels;
	p[0] = red;
	p[1] = green;
	p[2] = blue;
	p[3] = 255;
}

void		put_pixel(t_e *e, guchar red,
	guchar green, guchar blue)
{
	int		rowstride;
	int		n_channels;
	guchar	*pixels;
	guchar	*p;

	n_channels = gdk_pixbuf_get_n_channels(e->pixbufrt);
	g_assert(gdk_pixbuf_get_colorspace(e->pixbufrt) == GDK_COLORSPACE_RGB);
	g_assert(gdk_pixbuf_get_bits_per_sample(e->pixbufrt) == 8);
	g_assert(gdk_pixbuf_get_has_alpha(e->pixbufrt));
	g_assert(n_channels == 4);
	e->width = gdk_pixbuf_get_width(e->pixbufrt);
	e->height = gdk_pixbuf_get_height(e->pixbufrt);
	rowstride = gdk_pixbuf_get_rowstride(e->pixbufrt);
	pixels = gdk_pixbuf_get_pixels(e->pixbufrt);
	p = pixels + e->y * rowstride + e->x * n_channels;
	p[0] = red;
	p[1] = green;
	p[2] = blue;
	p[3] = 255;
}

void		init_image_0(t_e *e)
{
	e->image = gtk_image_new_from_file("RT.png");
}

void		init_pixbuf_0(t_e *e)
{
	e->pbloader = gdk_pixbuf_loader_new();
}

void		text_proced(t_e *e)
{
	t_ptextu		*textu;
	const gchar		*tmp;
	int				proced;
	gchar			*tmp2;

	textu = NULL;
	if (!(textu = malloc(sizeof(t_ptextu))))
		malloc_fail("text_proced");
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[24]));
	textu->refl_specu = (float)ft_atoi_double((char *)tmp);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[25]));
	textu->refl_diffuse = (float)ft_atoi_double((char *)tmp);
	tmp = gtk_entry_get_text(GTK_ENTRY(e->entry_addsphere[31]));
	textu->refract = (float)ft_atoi_double((char *)tmp);
	textu->type = 3;
	tmp2 = gtk_combo_box_text_get_active_text(\
		GTK_COMBO_BOX_TEXT(e->combo_addsphere[1]));
	if (ft_strcmp(tmp2, "Damier 2D"))
		proced = 0;
	if (ft_strcmp(tmp2, "Damier 3D"))
		proced = 1;
	textu->obj = (void*)&proced;
	e->o->texture = textu;
	textu->type = PROCEDURAL;
	free(tmp2);
}
