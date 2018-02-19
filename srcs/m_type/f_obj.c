/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_obj.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 16:48:04 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/14 01:32:19 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>
#include "ft_ori.h"

t_obj		*obj_init(void)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
	{
		ft_putstr_fd("parser_extract_obj: error malloc ...\n", 2);
		exit(0);
	}
	obj->name = 0;
	obj->origin = 0;
	obj->id = 0;
	obj->rey = 0.0;
	obj->dir = 0;
	obj->texture = 0;
	obj->color_light = 0;
	obj->rot = 0;
	obj->p1 = 0;
	obj->p2 = 0;
	obj->p3 = 0;
	obj->neg = 0;
	return (obj);
}
