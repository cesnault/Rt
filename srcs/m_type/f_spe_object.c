/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_spe_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:28:26 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/02 19:28:47 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>
#include "ft_ori.h"
#include <unistd.h>

t_spe_object		*spe_object_init(void)
{
	t_spe_object	*spe;

	if (!(spe = (t_spe_object *)malloc(sizeof(t_spe_object))))
	{
		ft_putstr_fd("parser_extract_obj : error malloc\n", 2);
		exit(0);
	}
	spe->name = 0;
	spe->origin = 0;
	spe->dim = 0;
	spe->rot = 0;
	spe->color_light = 0;
	return (spe);
}

void				spe_object_destroy(t_spe_object **s)
{
	t_spe_object	*spe;

	if (!s)
		return ;
	spe = *s;
	obj_free_texture(&(spe->texture));
	if (spe->name)
		free(spe->name);
	if (spe->origin)
		free(spe->origin);
	if (spe->dim)
		free(spe->dim);
	if (spe->rot)
		free(spe->rot);
	if (spe->color_light)
		free(spe->color_light);
	free(spe);
	*s = 0;
}
