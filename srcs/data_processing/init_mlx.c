/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:15:01 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 19:46:11 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include "texture.h"

void					init_mlx_norm(t_all_pobject *pop, int i,
	t_generic_param *cell)
{
	cell->name = ((t_generic_param *)pop->all_obj[i]->obj)->name;
	cell->dim = ((t_generic_param *)pop->all_obj[i]->obj)->dim;
	cell->ambiant = ((t_generic_param *)pop->all_obj[i]->obj)->ambiant;
	cell->antialia = ((t_generic_param *)pop->all_obj[i]->obj)->antialia;
	cell->sepia = ((t_generic_param *)pop->all_obj[i]->obj)->sepia;
	cell->green = ((t_generic_param *)pop->all_obj[i]->obj)->green;
	cell->red = ((t_generic_param *)pop->all_obj[i]->obj)->red;
	cell->yellow = ((t_generic_param *)pop->all_obj[i]->obj)->yellow;
	cell->neg = ((t_generic_param *)pop->all_obj[i]->obj)->neg;
	cell->stereo = ((t_generic_param *)pop->all_obj[i]->obj)->stereo;
	if (cell->antialia < 1)
		cell->antialia = 1;
	if (cell->antialia > 2)
		cell->antialia = 2;
	free(((t_generic_param *)pop->all_obj[i]->obj));
}

void					init_mlx_norm2(t_rt *glb, t_generic_param *cell)
{
	gp_min_max_value(cell);
	glb->setting = cell;
	glb->byte = 4;
	if (!(glb->line = (int *)malloc(sizeof(int))))
		malloc_fail("init_mlx");
	*glb->line = 4 * glb->setting->dim.x;
	glb->endian = 0;
	glb->text = texture_init(glb->setting->name,\
	glb->setting->dim.x, glb->setting->dim.y);
}

int						init_mlx(t_rt *glb, t_all_pobject *pop)
{
	unsigned int		i;
	t_generic_param		*cell;
	int					boo;

	cell = malloc(sizeof(t_generic_param));
	boo = 0;
	i = 0;
	while (i < pop->size_use && boo == 0)
	{
		if (pop->all_obj[i]->type == 8)
		{
			init_mlx_norm(pop, i, cell);
			boo = 1;
			free_generic(pop, i);
		}
		i++;
	}
	if (boo == 0)
	{
		free(cell);
		cell = init_generic_param();
	}
	init_mlx_norm2(glb, cell);
	return (0);
}

void					init_mlx_mlx_norm(t_rt *glb, t_generic_param *cell)
{
	glb->setting = cell;
	glb->byte = 4;
	if (!(glb->line = (int *)malloc(sizeof(int))))
		malloc_fail("init_mlx");
	*glb->line = 4 * 1000;
	glb->endian = 0;
	glb->mlx = mlx_init();
	glb->win = mlx_new_window(glb->mlx, 1000, 1000, "RT");
	glb->img = mlx_new_image(glb->mlx, 1000, 1000);
	glb->data = mlx_get_data_addr(glb->img,
		&glb->byte, glb->line, &glb->endian);
	glb->text = texture_init(glb->setting->name, 1000, 1000);
}

int						init_mlx_mlx(t_rt *glb, t_all_pobject *pop)
{
	unsigned int		i;
	t_generic_param		*cell;
	int					boo;

	cell = malloc(sizeof(t_generic_param));
	boo = 0;
	i = 0;
	while (i < pop->size_use && boo == 0)
	{
		if (pop->all_obj[i]->type == 8)
		{
			init_mlx_norm(pop, i, cell);
			boo = 1;
			free_generic(pop, i);
		}
		i++;
	}
	if (boo == 0)
	{
		free(cell);
		cell = init_generic_param();
	}
	init_mlx_mlx_norm(glb, cell);
	return (0);
}
