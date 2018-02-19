/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:38:04 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/19 20:38:25 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"
#include "procedural.h"
#include "type.h"
#include "texture.h"
#include <math.h>

t_color_light	color_object(t_rt *glb, int id)
{
	t_color_light res;

	if (glb->tab_obj->all_obj[id]->texture->type == COLOR)
	{
		res = color_obj(glb, id);
	}
	else if (glb->tab_obj->all_obj[id]->texture->type == PROCEDURAL)
		res = color_procedural(glb, id);
	else
	{
		res = color_picture(glb, id);
	}
	return (res);
}
