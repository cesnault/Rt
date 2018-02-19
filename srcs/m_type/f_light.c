/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_light.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:29:24 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/19 15:29:38 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

t_light		*light_init(void)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		malloc_fail("light_init");
	light->origin = 0;
	light->color_light = 0;
	light->name = 0;
	return (light);
}

void		light_destroy(t_light **light)
{
	t_light *tmp;

	if (!light || (*light))
		return ;
	tmp = *light;
	if (tmp->origin)
		free(tmp->origin);
	if (tmp->color_light)
		free(tmp->color_light);
	if (tmp->name)
		free(tmp->name);
	free(tmp);
	*light = 0;
}
