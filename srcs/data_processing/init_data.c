/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:04:56 by cesnault          #+#    #+#             */
/*   Updated: 2017/07/14 04:15:15 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include "../../minilibx_macos/mlx.h"
#include "tab_int_resize.h"
#include "tab_int_double_resize.h"

void				init_rt(t_rt *rt)
{
	if (!(rt->tab_obj = malloc(sizeof(t_obj_redim))))
		malloc_fail("init_rt");
	if (!(rt->tab_light = malloc(sizeof(t_light_redim))))
		malloc_fail("init_rt");
	obj_redim_init(NB_OBJ, rt->tab_obj);
	light_redim_init(NB_LIGHT, rt->tab_light);
	rt->cam = 0;
	rt->pos_obj = 0;
	rt->neg_obj = 0;
	rt->tmp_obj = 0;
	rt->setting = 0;
	rt->text = 0;
	rt->byte = 0;
	rt->line = 0;
	rt->endian = 0;
	rt->col.r = 0;
	rt->col.g = 0;
	rt->col.b = 0;
}

void				init_opti_tab(t_rt *glb)
{
	int				c;

	glb->pos_obj = tir_init(1000);
	glb->neg_obj = tir_init(1000);
	glb->tmp_obj = tidr_init(1000);
	c = 0;
	while (c < (int)glb->tab_obj->size_use)
	{
		if (glb->tab_obj->all_obj[c]->neg)
			tir_push_value(glb->neg_obj, c);
		else
			tir_push_value(glb->pos_obj, c);
		c++;
	}
}

void				free_pop(t_all_pobject *pop)
{
	unsigned int i;

	i = 0;
	while (i < pop->size_use)
	{
		free(pop->all_obj[i]);
		i++;
	}
}

void				data_processing(t_all_pobject *pop, t_rt *glb)
{
	int				meter;
	unsigned int	i;

	init_rt(glb);
	i = 0;
	meter = 0;
	while (i < pop->size_use)
	{
		if (pop->all_obj[i]->type == LIGHT)
			meter++;
		i++;
	}
	init_lst_light(meter, glb, pop);
	init_lst_obj(meter, glb, pop);
	init_cam(glb, pop);
	init_mlx(glb, pop);
	init_opti_tab(glb);
}

void				data_processing_mlx(t_all_pobject *pop, t_rt *glb)
{
	int				meter;
	unsigned int	i;

	init_rt(glb);
	i = 0;
	meter = 0;
	while (i < pop->size_use)
	{
		if (pop->all_obj[i]->type == LIGHT)
			meter++;
		i++;
	}
	init_lst_light(meter, glb, pop);
	init_lst_obj(meter, glb, pop);
	init_cam(glb, pop);
	init_mlx_mlx(glb, pop);
	init_opti_tab(glb);
}
