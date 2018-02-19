/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:15:21 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/19 21:15:39 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include "../../minilibx_macos/mlx.h"

void				init_lst_light(int meter, t_rt *rt, t_all_pobject *pop)
{
	unsigned int	i;

	i = 0;
	meter += 0;
	while (i < pop->size_use)
	{
		if (pop->all_obj[i]->type == LIGHT)
			light_redim_push(rt->tab_light, (t_light *)(pop->all_obj[i]->obj));
		i++;
	}
}
