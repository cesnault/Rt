/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 13:56:23 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 13:59:44 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "ft_ori.h"
#include "rt.h"
#include "type.h"
#include "texture.h"
#include "post_treatment.h"
#include "gtkgui.h"

void				update_main_texture(t_rt *glb)
{
	t_texture		*tmp;

	if (glb->setting->antialia == 1)
		rt_texture(glb, glb->text);
	else
	{
		tmp = texture_init("Antialiasing bitch",
		glb->setting->dim.x * glb->setting->antialia,\
		glb->setting->antialia * glb->setting->dim.y);
		rt_texture(glb, tmp);
		applied_antialia(glb->text, tmp, glb->setting->antialia);
		texture_destroy(&tmp);
	}
	main_post_treatment(glb->text, glb->setting);
}

void				main_norm(t_e *e)
{
	e->imagepb = gtk_image_new_from_pixbuf(e->pixbufrt);
	e->imagepbcpy = gtk_image_new_from_pixbuf(e->pixbufrtcpy);
	create(e);
	gtk_widget_show_all(e->window[0]);
	e->toggle = 1;
}

int					main_gtk(int argc, char **argv)
{
	t_all_pobject	*pop;
	t_rt			*glb;
	t_e				e;
	t_objl			*o;

	gtk_init(&argc, &argv);
	o = NULL;
	o = add_in_front(o);
	init_e(&e, o);
	if (!(pop = extract_data(argc, argv)))
		return (0);
	if (!(glb = malloc(sizeof(t_rt))))
		malloc_fail("main");
	data_processing(pop, glb);
	all_pobject_destroy(pop);
	update_main_texture(glb);
	e.pixbufrt = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8,\
	glb->setting->dim.x, glb->setting->dim.y);
	e.pixbufrtcpy = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8,\
	glb->setting->dim.x, glb->setting->dim.y);
	e.glb = glb;
	draw(glb, &e);
	main_norm(&e);
	gtk_main();
	return (1);
}

int					main_mlx(int argc, char **argv)
{
	t_all_pobject	*pop;
	t_rt			*glb;

	if (!(pop = extract_data(argc, argv)))
		return (0);
	if (!(glb = malloc(sizeof(t_rt))))
		malloc_fail("main");
	data_processing_mlx(pop, glb);
	all_pobject_destroy(pop);
	update_main_texture(glb);
	mlx_draw(glb);
	mlx_put_image_to_window(glb->mlx, glb->win, glb->img, 0, 0);
	mlx_key_hook(glb->win, &key, glb);
	mlx_hook(glb->win, 17, 18, red_cross, glb);
	mlx_loop(glb->mlx);
	glb_free(glb);
	return (1);
}

int					main(int argc, char **argv)
{
	if (argc > 3)
	{
		ft_putstr("only 2 arguments max\n");
		return (1);
	}
	if (argc < 3)
	{
		main_mlx(argc, argv);
		return (0);
	}
	if (ft_strcmp("gtk", argv[2]) == 0)
	{
		argc = 2;
		main_gtk(argc, argv);
	}
	else
		ft_putstr("Usage: ./rt scenes.sc gtk\n");
	return (0);
}
