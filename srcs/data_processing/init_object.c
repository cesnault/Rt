/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:09:36 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/12 23:38:10 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include "../../minilibx_macos/mlx.h"

void				init_lst_obj(int meter, t_rt *rt, t_all_pobject *pop)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	meter += 0;
	while (i < pop->size_use)
	{
		if ((pop->all_obj[i]->type > 0 && pop->all_obj[i]->type < 6) ||\
			pop->all_obj[i]->type >= 9)
		{
			((t_obj *)((pop->all_obj[i]->obj)))->type = pop->all_obj[i]->type;
			((t_obj *)((pop->all_obj[i]->obj)))->id = j;
			if (!(((t_obj *)((pop->all_obj[i]->obj)))->intersect =\
				(t_vect3d *)malloc(sizeof(t_vect3d))))
				malloc_fail("init_obj");
			if (!(((t_obj *)((pop->all_obj[i]->obj)))->normal =\
				(t_vect3d *)malloc(sizeof(t_vect3d))))
				malloc_fail("init_obj");
			obj_redim_push(rt->tab_obj, (t_obj *)((pop->all_obj[i]->obj)));
			j++;
		}
		i++;
	}
}
