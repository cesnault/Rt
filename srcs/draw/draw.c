/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:21:09 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 19:51:51 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "../../minilibx_macos/mlx.h"
#include "parser.h"
#include "gtkgui.h"

void	draw(t_rt *glb, t_e *e)
{
	e->y = 0;
	while (e->y < glb->setting->dim.y)
	{
		e->x = 0;
		while (e->x++ < glb->setting->dim.x)
		{
			if (gtk_notebook_get_current_page(GTK_NOTEBOOK(e->note[1])) == 1)
			{
				put_pixel_cpy(e, (guchar)(glb->text->rgb[e->y][e->x].r),
				(guchar)(glb->text->rgb[e->y][e->x].g),
				(guchar)(glb->text->rgb[e->y][e->x].b));
			}
			else if (gtk_notebook_get_current_page(\
				GTK_NOTEBOOK(e->note[1])) == 0 || e->toggle == 0)
			{
				put_pixel(e, (guchar)(glb->text->rgb[e->y][e->x].r),
				(guchar)(glb->text->rgb[e->y][e->x].g),
				(guchar)(glb->text->rgb[e->y][e->x].b));
			}
			glb->text->rgb[e->y][e->x].r = 0;
			glb->text->rgb[e->y][e->x].g = 0;
			glb->text->rgb[e->y][e->x].b = 0;
		}
		e->y++;
	}
}

void	mlx_draw(t_rt *glb)
{
	int index;
	int x;
	int y;

	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			index = x * 4 + y * *glb->line - 4;
			glb->data[index + 2] = glb->text->rgb[y][x].r;
			glb->data[index + 1] = glb->text->rgb[y][x].g;
			glb->data[index] = glb->text->rgb[y][x].b;
			y++;
		}
		x++;
	}
}

void	draw_text(t_texture *text)
{
	int x;
	int y;

	y = 0;
	while (y < text->dim.y)
	{
		x = 0;
		while (x < text->dim.x)
			x++;
		y++;
	}
}
