/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiante.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:52:53 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/19 19:53:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include "../../minilibx_macos/mlx.h"
#include <math.h>

static void			color_ambiante(t_rt *glb, int id)
{
	t_color_light	col;

	col = color_object(glb, id);
	glb->col.r = glb->tab_obj->all_obj[id]->texture->refl_diffuse *
	glb->setting->ambiant * col.x;
	glb->col.g = glb->tab_obj->all_obj[id]->texture->refl_diffuse *
	glb->setting->ambiant * col.y;
	glb->col.b = glb->tab_obj->all_obj[id]->texture->refl_diffuse *
	glb->setting->ambiant * col.z;
}

void				ambiante(t_rt *glb, int id)
{
	color_ambiante(glb, id);
}
